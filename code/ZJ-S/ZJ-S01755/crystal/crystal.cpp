#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int const N=5e5+5;
ll a[N];
ll s[N];
ll ans;
ll proans=LLONG_MIN;
ll mhy(ll x,ll i)
{
	ll sum=0;
	ll cnt=(i-x)*a[i]-(s[i-1]-s[x-1]);
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			ll mid=l+(r-l)/2;
			if(mhy(mid,i)<=m)
			{
				ans=(i-mid)+1;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		proans=max(proans,ans);
	}
	cout<<proans<<"\n";
	return 0;
}
/*
5 5
1 2 3 4 5

5 8
-3 -1 2 2 7

10 10
1 2 3 4 5 6 7 8 9 10

Oct31==Dec25?
*/