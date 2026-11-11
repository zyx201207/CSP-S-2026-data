#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505];
vector<int> a[505],t[505];
vector<vector<pair<int,int> > > g;
bool vis[500005];
long long dist[500005];
void dijkstra(int s)
{
	memset(dist,0x3f,sizeof dist);
	memset(vis,false,sizeof vis);
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		pair<int,int> top=pq.top();
		pq.pop();
		int u=top.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(!vis[v]&&dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	g.resize(m+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
		for(int x=1;x<=k[i];x++)
			for(int y=1;y<=k[i];y++)
				if(x!=y)
					g[a[i][x]].push_back(make_pair(a[i][y],t[i][x]+t[i][y]));
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x);
		printf("%lld\n",dist[y]+w[x]+w[y]);
	}
	return 0;
}
