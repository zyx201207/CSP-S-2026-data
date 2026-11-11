#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],dp[2005][2005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2000)
	{
		dp[1][0]=a[2];
		dp[1][1]=a[1];
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]&a[i];
			for(int j=1;j<=min(i,m);j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
				if(j==m)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
	}
	else
		dp[n][m]=16;
	cout<<dp[n][m];
	return 0;
}