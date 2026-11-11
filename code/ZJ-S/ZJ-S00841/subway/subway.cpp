#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 5;
const int M = 505;
const ull inf = 1e18;

template <typename _Tp1, typename _Tp2>
inline void chkmin(_Tp1 &x, const _Tp2 &y) {
	x = min(x, static_cast<_Tp1>(y));
}

int c, n, m, d, q;
ull w[N], dis[M][M];

vector<pair<int, int>> E[N];

int main() {
	assert(freopen("subway.in", "r", stdin));
	assert(freopen("subway.out", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int u, d;
			cin >> u >> d;
			E[u].emplace_back(i, d);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		for (auto [u, d1] : E[i]) {
			for (auto [v, d2] : E[i]) {
				chkmin(dis[u][v], d1 + d2);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				chkmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ull ans = inf;
		for (auto [u, d1] : E[x]) {
			for (auto [v, d2] : E[y]) {
				chkmin(ans, dis[u][v] + d1 + d2);
			}
		}
		cout << w[x] + w[y] + ans << "\n";
	}
	return 0;
}
