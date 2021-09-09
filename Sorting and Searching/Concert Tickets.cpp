
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
#define nl                 '\n'

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double


void solve()
{
	
	int n , m;
	cin >> n >> m;
	multiset<int> st;
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin >> x;
		st.insert(x);
	}
	
	vci people(m);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> people[i];
		if(st.size() == 0)
		{
			cout << "-1" << nl;
			continue;
		}
		auto it = st.lower_bound(people[i]);
		if(it == st.end())
		{
			cout << (*prev(it)) << nl;
			st.erase(prev(it));
		}
		
		else if(it == st.begin())
		{
			if((*it) > people[i])
			{
				cout << "-1" << nl;
				continue;
			}
			cout << (*it) << nl;
			st.erase(it);
		}

		else
		{
			if((*it) == people[i])
			{
				cout << (*it) << nl;
				st.erase(it);
			}
			else
			{
				cout << (*prev(it)) << nl;
				st.erase(prev(it));
			}
		}

	}



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