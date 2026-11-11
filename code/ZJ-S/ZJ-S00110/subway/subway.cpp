#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],u[500005];
struct aaa
{
	int to,l;
};
long long dp[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,127,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,v;
			cin>>u>>v;
			dp[i][u]=v;
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dp[k][k]<=1e18&&dp[k][j]<=1e18&&dp[i][k]<=1e18)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+dp[k][k]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+dp[u][v]<<"\n";
	}
	return 0;
}
