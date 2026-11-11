#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
//T1贪心二分前缀和100
ll n,m,a[N],ans,sum[N];
bool check(ll i,ll mid)
{
	return a[i]*mid-(sum[i]-sum[i-mid])<=m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=n;i>=1;i--)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			if(check(i,mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
