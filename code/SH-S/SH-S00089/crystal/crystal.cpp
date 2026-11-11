#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,r,mid,ans;
ll a[500005];
ll sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		l=1;r=i;
		for(;l<=r;)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
