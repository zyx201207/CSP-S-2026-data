#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int inf=0x3f3f3f3f;
int dp[505][505][505],a[505],kk[505],ww[505][505],vv[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	memset(g,-1,sizeof(g));
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++) cin>>ww[i][j]>>vv[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
			dp[i][j][k]=ww[k][i]+ww[k][j]+a[i]+a[j];
	}
	for(int i=1;i<=m;i++) dp[i][i][0]=0;
	for(int k=1;k<=m;k++)
		for(int l=1;l<=n;l++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
			{
				if(dp[i][j][0]!=-1&&dp[i][k][0]!=-1&&dp[k][j][0]!=-1)
				dp[i][j][0]=min(dp[i][j][l],dp[i][k][l]+dp[k][j][l]+dp[i][k][l]);
			}
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<dp[x][y][0];
	}
	return 0;
}
