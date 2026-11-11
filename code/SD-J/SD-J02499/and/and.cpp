#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long dp[2010][2010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++) dp[i][0]=pow(2,31)-1;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][m]);
	cout<<ans;
	return 0;
}
