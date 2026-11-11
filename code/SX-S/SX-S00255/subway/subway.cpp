#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[505][505];
int w[500005];
vector<pair<int, int> >node[500005];
int dist[505][505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	memset(f, 0x3f, sizeof f);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			node[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		int len = node[i].size() - 1;
		for (int l = 0; l < len; l++) {
			for (int r = l + 1; r <= len; r++) {
				int v = node[i][l].second + node[i][r].second;
				int x = node[i][l].first, y = node[i][r].first;
				f[x][y] = min(f[x][y], v);
				f[y][x] = min(f[y][x], v);
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && i != k && j != k && f[i][k] != f[0][0] && f[k][j] != f[0][0]) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << "0\n";
			continue;
		}
		int ans = w[l] + w[r], cnt = LLONG_MAX;
		int ll = node[l].size() - 1, lr = node[r].size() - 1;
		for (int i = 0; i <= ll; i++) {
			for (int j = 0; j <= lr; j++) {
				int x = node[l][i].first, xw = node[l][i].second;
				int y = node[r][j].first, yw = node[r][j].second;
				int v = f[x][y] + xw + yw;
				cnt = min(cnt, v);
			}
		}
		ans += cnt;
		cout << ans << '\n';
	}
	return 0;
}
