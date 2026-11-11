#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010];
bool check(long long mid)
{
	for(int i=1;i<=n;++i)
	{
		if(i>=mid)
		{
			if(1ll*mid*a[i]-(sum[i]-sum[i-mid])<=m) 
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	  sum[i]=sum[i-1]+a[i];
	int ans=0,l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
