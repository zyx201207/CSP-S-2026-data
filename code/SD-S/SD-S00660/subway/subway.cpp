#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=510,M=5e5+10,INF=1e18;
int C,n,m,D,q,dis[N][N],len[M],sz[M];
vector<PII> g[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>len[i],g[i].push_back({0,0});
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int siz;
		cin>>siz;
		while(siz--)
		{
			int k,d;
			cin>>k>>d;
			sz[k]++;
			g[k].push_back({i,d});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=sz[i];j++)
		{
			for(int k=j+1;k<=sz[i];k++)
			{
				int u=g[i][j].first,du=g[i][j].second;
				int v=g[i][k].first,dv=g[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],du+dv);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=INF;
		for(int i=1;i<=sz[u];i++)
		{
			for(int j=1;j<=sz[v];j++)
			{
				int id1=g[u][i].first,dis1=g[u][i].second;
				int id2=g[v][j].first,dis2=g[v][j].second;
				ans=min(ans,dis1+dis2+dis[id1][id2]);
			}
		}
		cout<<ans+len[u]+len[v]<<'\n';
	}
	return 0;
}
