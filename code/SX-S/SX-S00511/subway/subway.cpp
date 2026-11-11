#include <bits/stdc++.h>
using namespace std;
int f[505][505];
int w[500005];
vector<pair<int, int>>node[500005];
int dist[505][505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a, t;
			node[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		int len = node[i].size() - 1;
		for (int l = 0; l < len; l++) {
			for (int r = l + 1; r <= len; r++) {
				int x = node[i][l].second + node[i][r].second;
				int x = node[i][l], first, y = node[i][r].first;
				f[x][y] = min([x][y], v);
				f[y][x] = min([y][x], v);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1;; j <= n; j++) {
				if (i != j && i != k && f[i][x] = f[0][0] && f[x])
					f[i][j] = min(f[i][j], f[i][x] + f[x][j]);
			}
		}
	}
	while (q--)
		return 0;
}

