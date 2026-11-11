#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int k[505];
vector<pair<int,long long> > a[500005];
long long dp[505][505],fa[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=dp[j][i]=999999999999999999;
		}
		for (int j=1;j<=k[i];j++)
		{
			int o;
			long long u;
			cin>>o>>u;
			a[o].push_back({i,u});
		}
	}
	for (int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<a[i].size();j++)
		{
			int id1=a[i][j].first;
			long long zhi1=a[i][j].second;
			for (int p=j+1;p<a[i].size();p++)
			{
				int id2=a[i][p].first;
				long long zhi2=a[i][p].second;
				dp[id1][id2]=min(dp[id1][id2],zhi1+zhi2);
				dp[id2][id1]=dp[id1][id2];
			}
		}
	}
	for (int z=1;z<=n;z++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][z]+dp[j][z]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	while (q--)
	{
		int start,end;
		long long ans=999999999999999999;
		cin>>start>>end;
		for (int i=0;i<a[start].size();i++)
		{
			for (int j=0;j<a[end].size();j++)
			{
				ans=min(ans,dp[a[start][i].first][a[end][j].first]+a[start][i].second+a[end][j].second);
			}
		}
		cout<<ans+w[start]+w[end]<<endl;
	}
	return 0;
}
