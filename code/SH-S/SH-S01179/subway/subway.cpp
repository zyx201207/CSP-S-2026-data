#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long v,w;
};

vector<node> edge[500010];
vector<node> g[510];
bool vis[510];
long long d[510][510];
long long w[500010];

bool operator <(node x,node y)
{
	return x.w > y.w;
}

void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({s,0});
	d[s][s] = 0;
	while(q.size())
	{
		int u = q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i = 0;i < g[u].size();i++)
		{
			long long v = g[u][i].v,w = g[u][i].w;
			if(d[s][v] > d[s][u] + w)
			{
				d[s][v] = d[s][u] + w;
				q.push({v,d[s][v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,D,q;
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;i++)scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++)
		{
			long long a,t;
			scanf("%lld%lld",&a,&t);
			edge[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= m;i++)
		for(int j = 0;j < edge[i].size();j++)
			for(int k = j + 1;k < edge[i].size();k++)
			{
				node u = edge[i][j],v = edge[i][k];
				g[u.v].push_back({v.v,u.w + v.w});
				g[v.v].push_back({u.v,u.w + v.w});
			}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			d[i][j] = 1e18;
	for(int i = 1;i <= n;i++)dijkstra(i);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans = 1e18;
		for(int j = 0;j < edge[x].size();j++)
			for(int k = 0;k < edge[y].size();k++)
			{
				node u = edge[x][j],v = edge[y][k];
				ans = min(ans,u.w + v.w + d[u.v][v.v]);
			}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
