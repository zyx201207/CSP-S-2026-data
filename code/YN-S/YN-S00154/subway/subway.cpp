#include <bits/stdc++.h>
using namespace std;
#define int long long
#define freopen(io) freopen(io".in", "r", stdin), freopen(io".out", "w", stdout)

const int MAXN = 507, MAXM = 500007, MAXQ = 100007;
int c, n, m, d, q, w[MAXM];
vector<pair<int, int>> e[MAXM + MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[MAXM + MAXN];
bitset<MAXM + MAXN> vis;
vector<pair<int, int>> query[MAXQ];
int ans[MAXQ];

signed main()
{
	freopen("subway");
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int siz; cin >> siz;
		for (int j = 1; j <= siz; j++)
		{
			int a, t; cin >> a >> t;
			e[a].push_back({m + i, t}), e[m + i].push_back({a, t});
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int s, t; cin >> s >> t;
		query[s].push_back({t, i});
	}
	for (int s = 1; s <= m; s++)
	{
		if (query[s].empty()) continue;
		memset(dis, 0x3f, (m + n + 1) * sizeof(int));
		pq.push({0, s}), dis[s] = 0, vis.reset();
		while (!pq.empty())
		{
			int u = pq.top().second; pq.pop();
			if (vis[u]) continue; vis[u] = 1;
			for (size_t i = 0; i < e[u].size(); i++)
			{
				int v = e[u][i].first, w = e[u][i].second;
				if (dis[u] + w < dis[v]) pq.push({dis[v] = dis[u] + w, v});
			}
		}
		for (size_t i = 0; i < query[s].size(); i++)
		{
			int t = query[s][i].first, id = query[s][i].second;
			ans[id] = w[s] + dis[t] + w[t];
		}
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n'; 
}