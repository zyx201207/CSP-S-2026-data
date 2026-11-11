#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=1,ans=1;
	while(l<=r&&r<=n)
	{
		ll cost=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
		if(cost<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else
		{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
