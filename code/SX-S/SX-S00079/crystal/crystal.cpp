#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],l,r,qzh[N];
bool check(ll len)
{
	ll ans=9e18;
	for(ll i=len;i<=n;i++)
	{
		ll z=a[i]*len,t=qzh[i]-qzh[i-len-1];
		ans=min(ans,z-t);
	}
	return (ans<=m);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	l=1,r=n;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	while(r>l)
	{
		ll mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}