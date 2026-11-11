#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[500005];
long long sum[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i,res=0;
		while(l<=r)
		{
			long long mid=(l+r)>>1ll;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
			{
				res=i-mid+1;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
