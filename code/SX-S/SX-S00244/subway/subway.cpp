#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500010], T[501], dist[501][501];
vector<pair<int, int>> adj[500010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = LLONG_MAX / 2ll - 10ll;
		}
	}
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		for (int j = 1; j <= T[i]; j++) {
			int a, t;
			cin >> a >> t;
			adj[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)adj[i].size(); j++) {
			for (int k = 0; k < (int)adj[i].size(); k++) {
				if (j == k)
					continue;
				int u = adj[i][j].first, uw = adj[i][j].second;
				int v = adj[i][k].first, vw = adj[i][k].second;
				dist[u][v] = dist[v][u] = min(dist[u][v], uw + vw);
//				cout << u << ' ' << v << ' ' << dist[u][v] << '\n';
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = LLONG_MAX / 2ll - 10ll;
		for (int j = 0; j < (int)adj[x].size(); j++) {
			for (int k = 0; k < (int)adj[y].size(); k++) {
				ans = min(ans, dist[adj[x][j].first][adj[y][k].first] + adj[x][j].second + adj[y][k].second);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}
