#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=1;i<=n;i++)
		cout<<arr[i+1];
	return 0;
 } 
