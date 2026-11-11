#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=505,MAXM=5e5+5,MAXD=25,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,dis[MAXN][MAXN],G[MAXN][MAXN],w[MAXM],sz[MAXM];
pair<int,int> T[MAXM][MAXD];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(G,0x3f,sizeof(G));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		G[i][i]=0;
		int k;
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
		{
			cin>>a>>t;
			sz[a]++;
			T[a][sz[a]]={i,t};
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int u=1;u<=sz[i];u++)
		{
			for(int v=u+1;v<=sz[i];v++)
			{
				int x=T[i][u].first,y=T[i][v].first;
				int t=T[i][u].second+T[i][v].second;
				G[x][y]=min(G[x][y],t);
				G[y][x]=min(G[y][x],t);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=G[i][j];
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int ans=INF,u,v;
		cin>>u>>v;
		for(int i=1;i<=sz[u];i++) for(int j=1;j<=sz[v];j++)
		{
			pair<int,int> x=T[u][i],y=T[v][j];
			ans=min(ans,dis[x.first][y.first]+x.second+y.second);
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
