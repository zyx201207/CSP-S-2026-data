#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ans=1,hh=1,a[500010];

bool cmp(ll a, ll b)
{
	return a>b;
}

ll hrzn()
{
	ll tmp=m;
	ll ans=1,hh=1;
	sort(a+1,a+n+1);
	while(a[hh]==a[hh+1]&&hh<n)
	{
		hh++;
		ans++;
	}
	while(tmp>0)
	{
		ll k=a[hh+1]-a[hh];
		tmp-=ans*k;
		ans++;
		hh++;
		while(a[hh]==a[hh+1]&&hh<n)
		{
			hh++;
			ans++;
		}
	}
	if(tmp<0)ans--;
	return ans;
}

ll vert()
{
	ll tmp=m;
	ll ans=1,hh=1;
	sort(a+1,a+n+1,cmp);
	while(a[hh]==a[hh+1]&&hh<n)
	{
		hh++;
		ans++;
	}
	while(tmp>0)
	{
		ll k=a[1]-a[hh+1];
		tmp-=k;
		ans++;
		hh++;
		while(a[hh]==a[hh+1]&&hh<n)
		{
			hh++;
			ans++;
		}
	}
	if(tmp<0)ans--;
	return ans;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ans=max(hrzn(),vert());
	cout<<ans;
	return 0;
}

