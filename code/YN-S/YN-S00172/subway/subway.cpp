//2026.10.31  zyb  subway
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 505;
int id, n, m, D, Q;
int W[N];
vector<pair<int, int> >e[N];
int g[M][M];

void floyd() {
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> id >> m >> n >> D >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> W[i];
	}
	for (int i = 1, c, a, t; i <= m; i++) {
		cin >> c;
		while (c--) {
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			g[i][j] = 1e18 * (i != j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto j : e[i]) {
			for (auto k : e[i]) {
				int u = j.first, v = k.first;
				g[u][v] = g[v][u] = min(g[u][v], j.second + k.second);
			}
		}
	}
	floyd();
	int x, y;
	while (Q--) {
		cin >> x >> y;
		int ans = 1e18;
		for (auto i : e[x]) {
			for (auto j : e[y]) {
				ans = min(ans, g[i.first][j.first] + i.second + j.second);
			}
		}
		cout << ans + W[x] + W[y] << '\n';
	}
	return 0;
}