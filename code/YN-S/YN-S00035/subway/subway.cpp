// File Memory Longlong Calm

#include <bits/stdc++.h>

const int N = 6e5 + 10, M = 1e5 + 10, S = 20;

using namespace std;

vector<pair<int, long long>> G[N];
int nd, md, fa[N][30];
long long dep[N], len[N];

void dfs(int u, int pre)
{
//	printf("%d %d\n", u, pre);
	fa[u][0] = pre;
	for(int i = 1; i <= S; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(auto x : G[u])
	{
		int v = x.first;
		long long w = x.second;
		if(v == pre) continue;
		dep[v] = dep[u] + w;
		len[v] = len[u] + 1;
		dfs(v, u);
	}
}

int lca(int u, int v)
{
	if(len[u] < len[v]) swap(u, v);
	for(int i = S; i >= 0; i--) if(len[fa[u][i]] >= len[v]) u = fa[u][i];
	for(int i = S; i >= 0; i--) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return u == v ? u : fa[u][0];
}

long long w[M];
void add(int u, int v, long long w) 
{ 
	md++; 
	G[u].push_back({v, w}); 
	G[v].push_back({u, w}); 
//	printf("%d %d %lld\n", u, v, w);
}

long long dis[N], vis[N];

void Dijkstra(int s)
{
	priority_queue<pair<long long, int>> Q;
	for(int i = 1; i <= nd; i++) vis[i] = 0, dis[i] = 1e18;
	dis[s] = 0;
	Q.push({0, s});
	while(!Q.empty())
	{
		int u = Q.top().second; Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto x : G[u])
		{
			int v = x.first;
			long long w = x.second;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				Q.push({-dis[v], v});
			}
		}
	}
}

long long ans[1010][1010];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	scanf("%d %d %d %d %d", &c, &m, &n, &d, &q);
	nd = n;
	
	for(int i = 1; i <= n; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= m; i++)
	{
		int k;
		scanf("%d", &k);
		int p = ++nd;
		for(int j = 1; j <= k; j++)
		{
			int a;
			long long w;
			scanf("%d %lld", &a, &w);
			add(a, p, w);
		}
	}
	
	if(md == nd - 1)
	{
		dfs(1, 0);
		while(q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%lld\n", dep[x] + dep[y] - 2 * dep[lca(x, y)] + w[x] + w[y]);
		}
	}
	else if(m <= 1000)
	{
		for(int i = 1; i <= n; i++) 
		{
			Dijkstra(i);
			for(int j = 1; j <= n; j++) ans[i][j] = dis[j];
		}
		while(q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%lld\n", ans[x][y] + w[x] + w[y]);
		}
	}
	else
	{
		while(q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			Dijkstra(x);
			printf("%lld\n", dis[y] + w[x] + w[y]);
		}
	}
	
	return 0;
}
