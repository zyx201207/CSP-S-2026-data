#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e18;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m);
	for (int v = 0; v < m; v++) {
		cin >> w[v];
	}
	vector<vector<pair<int, int>>> way(m);
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		for (int v, t; k--; ) {
			cin >> v >> t;
			v--;
			way[v].emplace_back(i, t);
		}
	}
	vector<vector<ll>> dis(n, vector<ll>(n, inf));
	for (int i = 0; i < n; i++) {
		dis[i][i] = 0;
	}
	for (int v = 0; v < m; v++) {
		for (int x = 0; x < way[v].size(); x++) {
			int i = way[v][x].first, ti = way[v][x].second;
			for (int y = x + 1; y < way[v].size(); y++) {
				int j = way[v][y].first, tj = way[v][y].second;
				dis[i][j] = min<ll>(dis[i][j], ti + tj);
				dis[j][i] = min<ll>(dis[j][i], tj + ti);
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int u, v; q--; ) {
		cin >> u >> v;
		u--, v--;
		ll ans = inf;
		for (int x = 0; x < way[u].size(); x++) {
			int i = way[u][x].first, ti = way[u][x].second;
			for (int y = 0; y < way[v].size(); y++) {
				int j = way[v][y].first, tj = way[v][y].second;
				ans = min(ans, ti + dis[i][j] + tj);
			}
		}
		cout << w[u] + ans + w[v] << '\n';
	}

	// cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}