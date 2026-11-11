#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 505, M = 5e5 + 5;

namespace Solver {
	int c, n, m, d, q;
	void solve() {
		cin >> c >> n >> m >> d >> q;
		vector<i64> w(m + 1);
		for (int i = 1; i <= m; ++i) cin >> w[i];
		vector<int> t(n + 1);
		vector<vector<pair<int, i64>>> a(m + 1); 
		for (int i = 1; i <= n; ++i) {
			cin >> t[i];
			for (int j = 1; j <= t[i]; ++j) {
				int x;
				i64 c;
				cin >> x >> c;
				a[x].push_back({i, c});
			}
		}
		vector<vector<i64>> d(n + 1, vector<i64>(n + 1, 1e18));
		for (int i = 1; i <= m; ++i) {
			for (int l = 0; l < (int)a[i].size(); ++l) {
				for (int r = l + 1; r < (int)a[i].size(); ++r) {
					int lx = a[i][l].first, rx = a[i][r].first;
					d[rx][lx] = d[lx][rx] = min(d[lx][rx], a[i][l].second + a[i][r].second);
				}
			}
		}
		for (int i = 1; i <= n; ++i) d[i][i] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j || d[j][i] == 1e18) continue;
				for (int k = 1; k <= n; ++k) {
					if (i == k || d[i][k] == 1e18) continue;
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
				}
			}
		}
		while (q--) {
			int aa, b;
			cin >> aa >> b;
			i64 ans = 1e18;
			for (auto it : a[aa]) {
				for (auto ed : a[b]) {
					ans = min(ans, it.second + ed.second + d[it.first][ed.first]);
				} 
			}
			if (ans == 1e18) {
				cout << "-1\n";
			} else {
				cout << ans + w[aa] + w[b] << '\n';
			}
		}
	}
}

using namespace Solver;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
