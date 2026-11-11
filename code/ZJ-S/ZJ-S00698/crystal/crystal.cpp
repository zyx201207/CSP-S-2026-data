#include<bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long ll;
ll a[N];
ll n,m;
bool check(ll x)
{
	ll cc=0;
	for(ll i=1;i<=n;i++){
		if(a[i]<=x)
			cc+=x-a[i];
	}
	if(cc<=m) return 1;
	return 0;
}
ll bre(ll l,ll r)
{
	while(l<r)
	{
		ll mid=l+r+1>>1;
//		cout<<l<<" "<<r<<"\n";
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll l=INT_MAX,r=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	ll x=bre(l,r),cc=0;
	for(ll i=1;i<=n;i++)
		if(a[i]<=x) cc++;
	cout<<cc<"\n";
	return 0;
}

