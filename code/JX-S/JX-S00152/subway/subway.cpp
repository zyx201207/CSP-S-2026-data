#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

struct node
{
	int idx, dis;
	bool operator <(node A) const { return dis < A.dis; }
	bool operator >(node A) const { return dis > A.dis; }
};

struct edge { int to, w; };
vector<vector<edge> > G;
vector<int> dis, vis;

int c, n, m, d, q;
vector<int> w;

void init(int n, int m, int x)
{
	vis.clear();
	dis.clear();
	vis.assign(n + m + 1, 0);
	dis.assign(n + m + 1, INF);
	dis[x] = 0;
}

int Dijkstra(int x, int y)
{
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push({x, 0});
	while (!pq.empty())
	{
		int u = pq.top().idx; pq.pop();
		if (u == y) return dis[u];
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : G[u])
		{
			int v = e.to, w = e.w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
	return dis[y];
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1);
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	G.resize(n + m + 1);
	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t; cin >> a >> t;
			G[a].push_back({i + m, t});
			G[i + m].push_back({a, t});
		}
	}
	
	while (q--)
	{
		int x, y; cin >> x >> y;
		init(n, m, x);
		cout << w[x] + w[y] + Dijkstra(x, y) << "\n";
	}
	
	return 0;
}
