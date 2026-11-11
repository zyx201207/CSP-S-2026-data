#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i,res=0;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m)
			{
				r=mid-1;
				res=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
} 
