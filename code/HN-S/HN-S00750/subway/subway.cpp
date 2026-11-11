#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[1010];
int dis[1010][1010];
int dp[1010][1010];
int x[1010];
int y[1010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][j]=min(dp[i][j],y[i]+y[j]);
			}
		}
	}
	for(int k=n;k>=1;k--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
}

