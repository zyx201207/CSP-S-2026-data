#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll n,m;
ll a[N];
ll v[N];
ll check(ll x)
{
	ll sum=0;
	if(x>=n)return 0;
	for(ll i=1;i<=x;i++)// x为二分位置 
	{
		sum+=a[x]-a[i];
	}
	if(sum<=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll maxx=-1;
	ll x=(1<<25);
	ll len=(1<<25);
	while(len)
	{
		if(check(x))
		{
			maxx=max(maxx,x);
			x+=len/2;
			len/=2;
		}
		else
		{
			x-=len/2; 
			len/=2; 
		}
	}
	cout<<maxx;
}
