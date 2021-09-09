
//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
using namespace std;




int partition(int *arr , int start , int end)
{
	int i = start - 1;
	int j = start;
	int pivot = arr[end];
	for( ; j < end ; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(arr[i] , arr[j]);
		}
	}
	
	//Place the pivot element in the correct place
	swap(arr[i + 1] , arr[end]);
	return i + 1;
}

void quick_sort(int arr[] , int start , int end)
{
	if(start >= end)
		return;
	
	//Pivot
	int p = partition(arr , start , end);
	
	//Left
	quick_sort(arr , start , p - 1);
	
	//Right
	quick_sort(arr , p + 1 , end);

}

void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}



int main()
{

    local();

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i]; 

	quick_sort(arr , 0 , n - 1);
	
	cout << "Array after sorting : ";
	for(int i = 0 ; i < n ; i++)
		cout << arr[i] << " ";

    return 0;
}