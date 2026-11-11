#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=0;
	if(n==m)
	{
		ans=arr[1];
		for(int i=2;i<=n;i++)
		{
			ans&=arr[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
