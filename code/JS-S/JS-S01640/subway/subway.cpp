#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q;
long long w[500500],k[550];
long long dp[550][550];
long long gos[500500][25],got[500500][25],dt[500500];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)
		scanf("%lld",w+i);
	memset(dp,0x3f,sizeof dp);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",k+i);
		dp[i][i]=0;
		for(long long j=1;j<=k[i];j++)
		{
			long long aa,tt;
			scanf("%lld",&aa);
			scanf("%lld",&tt);
			gos[aa][++dt[aa]]=i;
			got[aa][dt[aa]]=tt;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=dt[i];j++)
			for(int k=j+1;k<=dt[i];k++)
				dp[gos[i][j]][gos[i][k]]=min(dp[gos[i][j]][gos[i][k]],got[i][j]+got[i][k]),dp[gos[i][k]][gos[i][j]]=min(dp[gos[i][k]][gos[i][j]],got[i][j]+got[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=dt[u];i++)
			for(int j=1;j<=dt[v];j++)
				ans=min(ans,w[u]+got[u][i]+dp[gos[u][i]][gos[v][j]]+got[v][j]+w[v]);
		printf("%lld\n",ans);
	}
	return 0;
}
