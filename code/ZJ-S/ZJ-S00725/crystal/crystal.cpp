#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll d[500005];
ll s[500005];
bool check(ll p,ll t)
{
	ll id=s[t]-s[p]-(p-1)*(a[t]-a[p]);
	if(id<=m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	s[1]=0;
	for(ll i=2;i<=n;i++)
	{
		s[i]=d[i-1]*(i-1)+s[i-1];
	}
	ll num=1;
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i,ans=0;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(mid,i)==true)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		num=max(num,i-ans+1);
	}
	cout<<num;
	return 0;
}
