#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=1005;
const int inf=1e18;
int w[N],k[M],a[M][1005],t[M][1005],ct,dd[N],f[N],g[3][N],aa[2][N],tt[2][N];
bool vis[N<<1];
struct node
{
	int v,w;
	bool operator <(const node&a) const
	{
		return w>a.w;
	}
};
vector <node> e[N<<1];
int dis[M][M<<1],ds;
priority_queue <node> pq;
void Dijkstra(int s)
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=ds;i++)
		dis[s][i]=inf;
	dis[s][s]=0;
	pq.push({s,0});
	while(!pq.empty())
	{
		node d=pq.top();pq.pop();
		int u=d.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].v,ww=e[u][i].w;
			if(dis[s][u]+ww<dis[s][v])
			{
				dis[s][v]=dis[s][u]+ww;
				pq.push({v,dis[s][v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(n<=2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
				cin>>aa[i][j]>>tt[i][j];
		}
		if(n==1)
		{
			while(q--)
			{
				int u,v;cin>>u>>v;
				cout<<w[u]+w[v]<<'\n';
			}
			exit(0);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
				f[aa[i][j]]+=(1<<(i-1)),dd[aa[i][j]]+=tt[i][j],g[i][aa[i][j]]=tt[i][j];
		}
		int mn=inf;
		for(int i=1;i<=m;i++)
			if(f[i]==3) mn=min(dd[i],mn);
		while(q--)
		{
			int u,v;cin>>u>>v;
			if(f[u]==f[v]||f[u]==3||f[v]==3)
			{
				if(f[u]==f[v]&&f[u]==3) cout<<w[u]+w[v]+min(g[1][u]+g[1][v],g[2][u]+g[2][v])<<'\n';
				else cout<<w[u]+w[v]+g[min(f[u],f[v])][u]+g[min(f[u],f[v])][v];
			}
			else cout<<mn+w[u]+w[v]+dd[u]+dd[v]<<'\n';
		}
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			ct++;
			e[m+ct].push_back({a[i][j],t[i][j]});
			e[a[i][j]].push_back({m+ct,t[i][j]});
			if(j!=1) e[m+ct].push_back({m+ct-1,0}),e[m+ct-1].push_back({m+ct,0});
		}
	}
	ds=m+ct;
	for(int i=1;i<=m;i++)
		Dijkstra(i);
	while(q--)
	{
		int u,v;cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
// 站厅 i
// 站台 m+ct