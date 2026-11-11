#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m;
ll a[N];
ll s[N];
map<ll,ll>mp;
bool cmp(ll a,ll b)
{
	if(mp[a]!=mp[b])
	{
		return mp[a]>mp[b];
	}
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		if(abs(i*a[i]-s[i])<=m)
		{
			ans=i;
		}
	}
	cout<<ans;
}
