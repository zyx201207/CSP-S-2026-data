#include<bits/stdc++.h>
using namespace std;
#define N 600011
int c, n, m, d, q;
int w[N];
struct node
{
	int to, vl;	
	bool operator < (node b)
	const
	{
		return vl > b.vl;
	}
};
vector<node> g[N];
int len[600][600];
bool vis[N] = {0};
int dis[N] = {0};
void dij(int s)
{
	priority_queue<node> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push({s, 0});
	dis[s] = 0;
	while (q.size())
	{
		node f = q.top();
		q.pop();
		int u = f.to, vl = f.vl;
		if (vis[u])
			continue;
		vis[u] = 1;
		for (node x : g[u])
		{
			if (x.vl + vl < dis[x.to])
			{
				dis[x.to] = x.vl + vl;
				q.push({x.to, dis[x.to]});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		len[s - m][i] = dis[i + m];
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			g[m + i].push_back({a, t});
			g[a].push_back({m + i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		dij(m + i);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = INT_MAX;
		for (node a : g[x])
			for (node b : g[y])
				ans = min(ans, w[x] + a.vl + len[a.to - m][b.to - m] + b.vl + w[y]);
		cout << ans << '\n';
	}
	return 0;
}

