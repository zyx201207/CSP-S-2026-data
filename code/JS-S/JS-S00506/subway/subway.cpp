#include<bits/stdc++.h>
// #define ll long long
using namespace std;
int op,n,m,dd,q;
int ans;
int w[500010];
int k[510];
int d[1000010],vis[1000010];
struct node
{
	int v,w;
};
struct Node
{
	int u,v,w;
};
vector<node> g[1000010];
bool operator<(Node a1,Node b1)
{
	return a1.w>b1.w;
}
void Dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f3f3f3f,sizeof(d));
	d[s]=0;
	priority_queue<Node> pq;
	pq.push({0,s,0});
	while(!pq.empty())
	{
		Node tmp=pq.top();
		pq.pop();
		int u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=1;
		// cout<<tmp.u<<" "<<u<<" "<<tmp.w<<" "<<g[u].size()<<'\n';
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v;
			int w=g[u][i].w;
			// cout<<u<<" "<<v<<" "<<w<<'\n';
			if(v==tmp.u)
				continue;
			if(vis[v])
				continue;
			d[v]=min(d[v],d[u]+w);
			pq.push({u,v,d[v]});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,v,w;j<=k[i];j++)
		{
			cin>>v>>w;
			g[i+m].push_back({v,w});
			g[v].push_back({i+m,w});
			// cout<<i+m<<" "<<v<<" "<<w<<'\n';
		}
	}
	// cout<<'\n';
	while(q--)
	{
		int x,y;
		ans=0;
		cin>>x>>y;
		Dijkstra(x);
		// cout<<d[y]<<'\n';
		ans+=w[x]+w[y]+d[y];
		cout<<ans<<'\n';
	}
	return 0;
}