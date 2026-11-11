#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int _, n, m, q;
	cin >> _ >> m >> n >> _ >> q;
	vector<int> w(n+1, 0);
	for (int i = 1; i <= n; ++i) cin >> w[i];
	vector<vector<pair<int, int>>> e(n+m+1);
	for (int i = 1; i <= m; ++i) {
		int k; cin >> k;
		while (k--) {
			int a, t; cin >> a >> t;
			e[a].push_back({ n+i, t });
			e[n+i].push_back({ a, t });
		}
	}
	for (int i = 1; i <= n+m; ++i) {
		sort(e[i].begin(), e[i].end());
	}
	vector<vector<int>> d(m+1, vector<int>(m+1, 1e18));
	for (int i = 1; i <= m; ++i) {
		d[i][i] = 0;
		for (auto& t1 : e[n+i]) {
			int u = t1.first, w1 = t1.second;
			for (auto& t2 : e[u]) {
				int j = t2.first, w2 = t2.second;
				d[i][j-n] = min(d[i][j-n], w1+w2);
			}
		}
	}
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		int ans = 1e18;
		for (auto& t1 : e[x]) {
			int u = t1.first, w1 = t1.second;
			for (auto& t2 : e[y]) {
				int v = t2.first, w2 = t2.second;
				ans = min(ans, d[u-n][v-n] + w1 + w2);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
