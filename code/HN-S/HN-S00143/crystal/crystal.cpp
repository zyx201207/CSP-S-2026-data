#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005],sum[500005];
int ef(long long int x)
{
	long long int ans=0,l=0,r=x;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]*(x-mid)-(sum[x]-sum[mid])<=m)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long int maxx=0;
	for(long long int i=1;i<=n;i++)
	{
		long long int l=ef(i);
		maxx=max(maxx,i-l);
	}
	cout<<maxx;
	return 0;
}
