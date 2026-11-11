#include <iostream>
#include <vector>
#include <cstring>
#include <queue> 

using namespace std;

const int N = 1e6 + 10; 

int c, t, n, k;
int s, cnt;
int dist[N];
int max_dist = 0;
bool flag[N], vis[N];
vector<int> g[N];
vector<int> cur_r, route;

void dfs1(int u, int pa)
{
	if (dist[u] >= max_dist)
	{
		max_dist = dist[u];
		s = u;
	}
	for (int v : g[u])
	{
		if (v == pa)
			continue;
		dist[v] = dist[u] + 1;
		dfs1(v, u);
	}
}

void dfs2(int u, int pa)
{
	cur_r.push_back(u);
	if (dist[u] >= max_dist)
	{
		max_dist = dist[u];
		s = u;
		route = cur_r;
	}
	for (int v : g[u])
	{
		if (v == pa)
			continue;
		dist[v] = dist[u] + 1;
		dfs2(v, u);
	}
	cur_r.pop_back();
}

int main()
{
	freopen("hub4.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> t;
	while (t--)
	{
		cnt = 0;
		cin >> n >> k;
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		max_dist = 0;
		dfs1(1, 0);
		max_dist = 0;
		dfs2(s, 0);
		int len = route.size();
		int a = route[(len / 2 + 1) / 2];
		int b = route[len - (len / 2 + 1) / 2 - 1];
		flag[a] = flag[b] = true;
		
		queue<int> q;
		q.push(a);
		q.push(b);
		dist[a] = dist[b] = 0;
		vis[a] = vis[b] = 1;
		max_dist = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v : g[u])
			{
				if (vis[v])	
					continue;
				dist[v] = dist[u] + 1;
				max_dist = max(max_dist, dist[v]);
				vis[u] = true;
				q.push(v);
			}
		}
		cout << max_dist << "\n";
		
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		cur_r.clear();
		memset(vis, 0, sizeof vis);
	}
	
	return 0;
}

