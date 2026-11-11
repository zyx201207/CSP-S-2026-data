#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500067;
ll n,m,a[N],s[N];
bool check(ll l)
{
	for(ll i=1;i+l-1<=n;i++)
	{
		if(l*a[i+l-1]-(s[i+l-1]-s[i-1])<=m)
			return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll l=0ll,r=n+1,ans=0ll;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1ll;
		else r=mid-1ll;
	}
	cout << ans << '\n';
	return 0;
}
//Xterfusion 1st Anniversary
//Special song: Craft Super Crystal
//Happy birthday, Xterfusion by REDAlice vs. t+pazolite
//14:56 Pass all the samples.
