#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],s[500010];
bool check(ll x)
{
	for(ll i=x;i<=n;i++)
	{
		ll ans=(x-1)*a[i]-(s[i-1]-s[i-x]);
		if(ans<=m) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll k,ld;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
