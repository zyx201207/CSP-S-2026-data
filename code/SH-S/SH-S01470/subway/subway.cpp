#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
#define ll long long
int t,n,m,d,q;
int k[N];
ll w[M],dis[N][N],ans;
struct Node{int v;ll w;};
vector<Node> g[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>t>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			int u;ll w;cin>>u>>w;
			for(int c=0;c<g[u].size();++c)
			{
				int v=g[u][c].v;ll val=g[u][c].w;
				dis[i][v]=min(dis[i][v],val+w);
				dis[v][i]=min(dis[v][i],val+w);
			}
			g[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;cin>>x>>y;
		ans=1e18;
		for(int i=0;i<g[x].size();++i)
			for(int j=0;j<g[y].size();++j)
			{
				int u=g[x][i].v,v=g[y][j].v;
				ll w1=g[x][i].w,w2=g[y][j].w;
				ans=min(ans,dis[u][v]+w1+w2);
			}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
		
	return 0;
}
