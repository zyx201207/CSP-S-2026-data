#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 5, MAXN = 505;
int c, n, m, dd, q;
int w[MAXM];
long long d[MAXN][MAXN];
vector<pair<int, int>> g[MAXM];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int x, y;
			cin >> x >> y;
			g[x].push_back({y, i});
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (g[i].size() > 1) {
			for (int l = 0; l < g[i].size(); ++l) {
				for (int r = l + 1; r < g[i].size(); ++r) {
					int u = g[i][l].second, v = g[i][r].second;
					d[u][v] = min(d[u][v], 1ll * g[i][l].first + g[i][r].first);
					d[v][u] = d[u][v];
				}
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		d[u][u] = 0;
	}
	for (int k = 1; k <= n; ++k) {
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (pair<int, int> tt1 : g[x]) {
			for (pair<int, int> tt2 : g[y]) {
				int u = tt1.second, v = tt2.second;
				ans = min(ans, d[u][v] + w[x] + w[y] + tt1.first + tt2.first);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}