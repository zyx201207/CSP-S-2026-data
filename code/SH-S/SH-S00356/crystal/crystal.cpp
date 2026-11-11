#include<bits/stdc++.h>
using namespace std;
#define ll long long  
ll n,m;
ll a[500010];
ll dp[500010];
ll ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	cout<<a[n]<<'\n';
	for(int i=2;i<=n;++i)
	{
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
	}
//	cout<<dp[n]<<'\n';
	ll l=1,r=1;
	while(r<=n)
	{
		while(dp[r]-dp[l-1]-(a[r]-a[l-1])*(l-1)<=m&&r<=n) r++;
		ans=max(ans,r-l); 
		l++;
	}
	cout<<ans;
	return 0;
}
