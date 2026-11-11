#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=5e5+10;
ll n,m,a[N],sum[N];
bool check(ll x)
{
	for(int i=x; i<=n; ++i)
	{
		ll now=x*a[i]-(sum[i]-sum[i-x]);
		if(now<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read();m=read();
	for(int i=1; i<=n; ++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
