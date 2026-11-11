#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-15
#define db double
const int N=5e5+10;
ll a[N],sum[N];
ll n,m;
bool check(ll x)
{
	for(int i=x;i<=n;i++)if(a[i]*x-(sum[i]-sum[i-x])<=m)return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll l=1,r=N,best=1;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))
		{
			l=mid+1;
			best=mid;
		}
		else r=mid-1;
	}
	printf("%lld",best);
	return 0;
}
