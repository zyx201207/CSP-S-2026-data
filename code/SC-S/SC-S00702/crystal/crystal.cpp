#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m;
ll a[500505];
bool ch(ll x,ll i)
{
	ll df=(a[i]-a[i-1])*x-(a[i]-a[i-x]);
	return df<=m;
}
ll res=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=l+r+1>>1;
			if(ch(mid,i))l=mid;
			else r=mid-1;
		}
		res=max(res,l);
	}
	cout<<res;
	return 0;
}