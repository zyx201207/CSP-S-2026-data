#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],sum[500010],out=1;
int comp(ll x,ll y)
{
	return x>y;
}
int check(ll x,ll y)
{
	if(y*a[x]-(sum[x+y-1]-sum[x-1])<=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,comp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=n-i+1,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(i,mid))
			{
				out=max(mid,out);
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<out;
	return 0;
}
