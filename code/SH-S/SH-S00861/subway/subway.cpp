#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5;
typedef long long ll;
const int INF=0x3f3f3f3f;
ll dis[N];
bool vis[N];
ll dw[N];
struct edge
{
	int v;
	ll w;
};
vector<edge> g[N];
struct node
{
	int idx;
	ll dist;
	bool operator < (const node & other) const
	{
		dist>other.dist;
	}
};
void dijkstra(int s)
{
	memset(dis,INF,sizeof dis);
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty())
	{
		node cur=q.top();
		q.pop();
		int u=cur.idx;
		if(vis[u])
			continue;
		vis[u]=true;
		for(edge ed : g[u])
		{
			int v=ed.v;
			ll w=ed.w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>dw[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,v,ww;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>ww;
			ll distan=ww+dw[i]+dw[v];
			g[i].push_back({v,distan});
			g[v].push_back({i,distan});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		dijkstra(u);
		cout<<dis[v]<<endl;
	}
	return 0;
}
