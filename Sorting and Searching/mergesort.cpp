
//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
using namespace std;


void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void merge(int arr[] , int low , int mid , int high)
{
	int i = low , j = mid + 1;

	int k = 0;
	int temp[high - low + 1];

	while(i < (mid + 1) && j < (high + 1))
	{
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	for( ; i <= mid ; i++)
	{
		temp[k++] = arr[i];
	}

	for( ; j <= high ; j++)
	{
		temp[k++] = arr[j];
	}

	k = 0;
	for(int i = low ; i <= high ; i++)
	{
		arr[i] = temp[k++];
	}

}



void merge_sort(int arr[] , int low , int high)
{
	if(low >= high)
		return;
	int mid = (low + high) / 2;

	merge_sort(arr , low , mid);
	merge_sort(arr , mid + 1 , high);

	merge(arr , low , mid , high);
}

int main()
{

    local();
    
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i]; 

	merge_sort(arr , 0 , n - 1);
	
	cout << "Array after sorting : ";
	for(int i = 0 ; i < n ; i++)
		cout << arr[i] << " ";

    return 0;
}