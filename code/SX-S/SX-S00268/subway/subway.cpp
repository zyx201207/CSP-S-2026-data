#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, d, q, a[500005], f[505][505];
vector<pair<int, int>> vc[500005];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int Tec = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1; i <= m; ++i)
		a[i] = read();
	for (int i = 1; i <= n; ++i) {
		int k = read();
		for (int j = 1; j <= k; ++j) {
			int x = read(), y = read();
			vc[x].push_back(make_pair(i, y));
		}
	}
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			f[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i)
		f[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < vc[i].size(); ++j) {
			for (int k = j + 1; k < vc[i].size(); ++k) {
				f[vc[i][j].first][vc[i][k].first] = min(f[vc[i][j].first][vc[i][k].first], vc[i][j].second + vc[i][k].second);
				f[vc[i][k].first][vc[i][j].first] = f[vc[i][j].first][vc[i][k].first];
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int x = read(), y = read();
		int ans = f[n + 1][0];
		for (auto p1 : vc[x]) {
			for (auto p2 : vc[y]) {
				ans = min(ans, f[p1.first][p2.first] + p1.second + p2.second);
			}
		}
		printf("%lld\n", ans + a[x] + a[y]);
	}
	return 0;
}