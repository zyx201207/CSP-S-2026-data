#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10, M = 5e5 + 10;

int c, n, m, d, q;
int w[M], vis[N];
long long dist[N][N];
vector<pair<int, int>> line[M], g[N];

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i != j)
				dist[i][j] = 1e18;
		cin >> k;
		for (int j = 1, s, w; j <= k; j++) {
			cin >> s >> w;
			for (int __ = 0; __ < line[s].size(); __++) {
				int x = line[s][__].first, w1 = line[s][__].second;
				g[i].push_back({x, w + w1}), g[x].push_back({i, w + w1});//build graph
			}
			line[s].push_back({i, w});
		}
	}
	for (int i = 1; i <= n; i++) {//dijkstra
		memset(vis, 0, sizeof vis);
		priority_queue<pair<long long, int>> q;
		q.push({0, i});
		while (!q.empty()) {
			int x = q.top().second;
			q.pop();
			if (vis[x])
				continue;
			vis[x] = 1;
			for (int __ = 0; __ < g[x].size(); __++) {
				int v = g[x][__].first, w = g[x][__].second;
				if (dist[i][v] > dist[i][x] + w)
					dist[i][v] = dist[i][x] + w, q.push({-dist[i][v], v});
			}
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		long long res = 1e18;
		for (int __ = 0; __ < line[u].size(); __++) {
			int i = line[u][__].first, w1 = line[u][__].second;
			for (int _1 = 0; _1 < line[v].size(); _1++) {
				int j = line[v][_1].first, w2 = line[v][_1].second;
				res = min(res, w1 + dist[i][j] + w2);
			}
		}
		cout << res + w[u] + w[v] << '\n';
	}
	return 0;
}