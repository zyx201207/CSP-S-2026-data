#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define F first
#define S second

const int MN=2e5+10;
ll n,ans;
ll a[MN];
char c[MN];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r)
	{
		ll d=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=d;
		a[l]-=d;
		a[r]-=d;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans<<'\n';
	return 0;
}
