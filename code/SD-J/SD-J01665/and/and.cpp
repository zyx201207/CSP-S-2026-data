#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	 }
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int ans=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int q=a[i]&a[j];
				ans=max(ans,q);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
 } 
