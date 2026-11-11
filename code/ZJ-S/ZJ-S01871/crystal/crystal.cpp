#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxn,cnt,ans,a[500010];	
map<ll,ll>mp;
vector<ll>v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		if(mp[a[i]]>=maxn)
		{
			maxn=mp[a[i]];
			cnt=a[i];
		}		
	}
	for(ll i=1;i<=n;i++)
		if(mp[a[i]]==maxn)v.push_back(a[i]);
	sort(a+1,a+n+1,greater<ll>());
	for(ll t:v)
	{
		ll s=0,ts=m;
		for(ll i=1;i<=n;i++)
		{
			if(ts<=0)break;
			if(a[i]>=t)continue;
			ts-=(t-a[i]);
			if(ts>=0)s++;
		}	
		ans=max(ans,s);
	}
	cout<<maxn+ans<<'\n';
	return 0;
}

