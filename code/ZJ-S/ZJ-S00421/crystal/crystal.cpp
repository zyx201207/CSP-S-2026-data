#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
long long n,m;
long long a[mx],sum[mx];
bool check(long long l,long long r)
{
	if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m) return true;
	return false;
}
long long f(long long x)
{
	long long l=1,r=x,mid=0,ans=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid,x))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
		ans=max(ans,i-f(i)+1);
	printf("%lld\n",ans);
	return 0;
}