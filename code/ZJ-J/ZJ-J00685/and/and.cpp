#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],dp[2005][2005];
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][0]=INT_MAX;
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
	}
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=m;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<"\n";
//	}
	cout<<dp[n][m]<<"\n";
	return 0;
}

