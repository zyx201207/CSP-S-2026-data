#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define F first
#define S second

const ll MN=5e5+10;
ll n,m,ans;
ll a[MN];
ll s[MN];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll l=0,r=i+1;
		while(l<r-1)
		{
			ll mid=(r-l)/2+l;
			(((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)?r:l)=mid;
		}
		ans=max(ans,i-l);
	}
	cout<<ans<<'\n';
	return 0;
}
