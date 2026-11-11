#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500010];
ll n;
ll m,ans=0;
bool check(ll x){
	ll res = 0;
	for (ll i=1;i<x;i++)
	{
		res += 1ll*a[x]-a[i];
	}
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
	/*	if (A)
		{
			if (a[i]!=i) A = 0;
		}
		if (B)
		{
			if (i>2 && a[i]-a[i-1] != a[i-1]-a[i-2]) B = 0;
		}*/
	}
	/*if (A) 
	{
		ll ii=1;
		for (ii;ii*(ii+1)/2<m;ii++) ;
		cout<<ii;
		return 0;
	}
	if (B)
	{
		ll ii=1,dist = a[2]-a[1];
		for (ii;dist*ii*(ii+1)/2<m;ii++) ;
		cout<<ii;
		return 0;
	}*/
	sort(a+1,a+n+1);
	ll l = 1,r = n,mid;
	while (l<=r)
	{
		mid = 1ll*(l+r)>>1;
		if (check(mid))
		{
			l = mid+1ll;
			ans = max(ans,mid);
		}
		else
		{
			r = mid-1ll;
		}
	}
	cout<<ans;
	return 0;
}
