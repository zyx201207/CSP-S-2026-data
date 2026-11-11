#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],d[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[i]=a[i]+d[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if((i-mid)*a[i]-(d[i-1]-d[mid-1])<=m)r=mid-1;
			else l=mid;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
 } 
