#include <bits/stdc++.h>
using namespace std;
long long w[500005], t[505][505], a[505][505], k, dist[505][505];
vector<pair<int, int> > g[500005];
vector<pair<int, int> > z[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = 10000000000;
		}
	}
	int n, m, d, q, c;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			z[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < z[i].size(); j++) {
			for (int p = j + 1; p < z[i].size(); p++) {
				int x = z[i][j].first, y = z[i][p].first;
				g[x].push_back({y, z[i][p].second + z[i][j].second});
				g[y].push_back({x, z[i][p].second + z[i][j].second});
				dist[x][y] = dist[y][x] = z[i][p].second + z[i][j].second;
			}
		}
	}
	for (int p = 1; p <= n; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || i == p || j == p) {
					continue;
				}
				dist[i][j] = min(dist[i][p] + dist[p][j], dist[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		long long ans = 100000000000;
		for (int i = 0; i < z[x].size(); i++) {
			for (int j = 0; j < z[y].size(); j++) {
				int x0 = z[x][i].first, y0 = z[y][j].first;
				long long u = dist[x0][y0];
				long long v = z[x][i].second + z[y][j].second;
				ans = min(w[x] + w[y] + v + u, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}