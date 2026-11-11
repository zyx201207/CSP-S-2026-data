#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],qzs[500005];
int ans=-1e9;
ll check(ll x)
{
	ll mi=1e18;
	for(int i=1;i<=n-x+1;i++)
	{
		ll ed=i+x-1;
		ll xx=qzs[ed]-qzs[i]-(i-1)*(a[ed]-a[i]);
		if(x==n&&xx!=m)
		{
			continue;
		}
		mi=min(mi,xx);
	}
	return mi;
}
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		qzs[i]=qzs[i-1]+(a[i]-a[i-1])*(i-1);
	}
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)<=m)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}