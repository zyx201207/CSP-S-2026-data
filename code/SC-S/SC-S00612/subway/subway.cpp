#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

constexpr long long INF=1e18;

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Task,n,m,d,q;
	scanf("%d%d%d%d%d",&Task,&n,&m,&d,&q);
	vector<long long>w(m+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	vector<vector<pair<int,long long>>>sta(m+1);
	vector<vector<long long>>dist(n+1,vector<long long>(n+1,INF));
	for(int i=1;i<=n;i++)
	{
		dist[i][i]=0;
		int len;
		scanf("%d",&len);
		for(int j=0;j<len;j++)
		{
			int a;
			long long t;
			scanf("%d%lld",&a,&t);
			for(int k=0;k<sta[a].size();k++)
			{
				dist[sta[a][k].first][i]=min(dist[sta[a][k].first][i],t+sta[a][k].second);
				dist[i][sta[a][k].first]=min(dist[i][sta[a][k].first],t+sta[a][k].second);
			}
			sta[a].emplace_back(i,t);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=INF;
		for(int l=0;l<sta[u].size();l++)
		{
			for(int r=0;r<sta[v].size();r++)
			{
				ans=min(ans,dist[sta[u][l].first][sta[v][r].first]+sta[u][l].second+sta[v][r].second);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}