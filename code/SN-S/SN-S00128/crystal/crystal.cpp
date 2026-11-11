#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cf[500005],hcf[500005],a[500005];
bool check(ll l,ll r,ll tag)
{
	ll x=hcf[r]-hcf[l-1]-(r-l+1)*tag;
	if(x>m) return 0;
	else return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll da=-1e18;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) cf[i]=a[n]-a[i];
	for(ll i=1;i<=n;i++) hcf[i]=hcf[i-1]+cf[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i,tag=a[n]-a[i],ans=1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid,i,tag)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		da=max(da,i-ans+1);
	}
	cout<<da;
	return 0;
}

