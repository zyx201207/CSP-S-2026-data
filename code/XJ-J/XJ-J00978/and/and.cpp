#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cout<<arr[n];
	return 0;
}
