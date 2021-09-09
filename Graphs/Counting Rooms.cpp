
/*
	ॐ
		JAI SHREE RAM

		Hare Krishna Hare Krishna Krishna Krishna Hare Hare
		Hare Rama Hare Rama Rama Rama Hare Hare
	
												ॐ
*/

//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
pbds;



#define fast            	ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL)
#define int					long long int
#define vci              	vector<int>
#define vcvci             	vector<vector<int>>
#define vcpi             	vector<pair<int,int>>
#define vcs					vector<string>
#define pb              	push_back
#define mpii             	map<int , int>
#define mpsi             	map<string , int>
#define mpci             	map<char , int>
#define umpii             	unordered_map<int , int>
#define umpsi             	unordered_map<string , int>
#define umpci             	unordered_map<char , int>
#define all(x)				auto it = x.begin() ; it != x.end() ; it++
#define vcc              	vector<char>
#define vcs              	vector<string>
#define sti            		set<int>
#define stc            		set<char>
#define sts            		set<string>
#define pqmx				priority_queue<int>
#define pqmn				priority_queue<int , vi , greater<int>>
#define null            	NULL
#define ff            		first
#define ss              	second
#define stb(x)				__builtin_popcount(x)
#define lzr(x)				__builtin_clz(x)
#define tzr(x)					__builtin_ctz(x)
#define prc(x , y)          fixed << setprecision(y) << x
#define max3(a, b, c)   	max(a, max(b, c))
#define min3(a, b, c)   	min(a, min(b, c))

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double



vci gr[1000010];
bool cfloor[1000010];
bool vis[1000010];
int cnt = 0;
void dfs(int src , bool *vis)
{
	vis[src] = true;

	for(auto nbr : gr[src])
	{
		if(!vis[nbr])
		{
			dfs(nbr , vis );

		}
	}
}


void solve()
{
	
	int n , m;
	cin >> n >> m;

	int arr[n][m];
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			char c;
			cin >> c;
			if(c == '#')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
				
		
		}
	}


	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(arr[i][j] == 1)
			{
				if(i + 1 < n && arr[i + 1][j] == 1)
					gr[i * m + j].pb((i + 1) * m + j);

				if(j + 1 < m && arr[i][j + 1] == 1)
					gr[i * m + j].pb(i * m + j + 1);
				if(i - 1 >= 0 && arr[i - 1][j] == 1)
					gr[i * m + j].pb((i - 1) * m + j);
					
				if(j - 1 >= 0 && arr[i][j - 1] == 1)
					gr[i * m + j].pb(i * m + j - 1);
				
				cfloor[i * m + j] = true;
			}
		}
	}


	for(int i = 0 ; i < m * n ; i++)
	{
		if(cfloor[i] == true && vis[i] != true)
		{
			dfs(i , vis);
			cnt++;
		}

	}

	cout << cnt;

}

void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main()
{

    fast;
    local();
    int T = 1;
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}