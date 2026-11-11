#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 5, M = 500 + 5;

int c, n, m, d, q;

ll w[N], f[M][M];

vector<pair<int, ll>> vec[N];

int main() {
	assert(freopen("subway.in", "r", stdin));
	assert(freopen("subway.out", "w", stdout));

	cin.tie(0)->sync_with_stdio(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1, x, v; j <= k; ++j) {
			cin >> x >> v;
			vec[x].emplace_back(i, v);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j] = (i == j ? 0 : INF_LL);
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (auto [u, x] : vec[i]) {
			for (auto [v, y] : vec[i]) {
				f[u][v] = min(f[u][v], x + y);
			}
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
			}
		}
	}

	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		ll res = INF_LL;
		for (auto [u, a] : vec[x]) {
			for (auto [v, b] : vec[y]) {
				res = min(res, f[u][v] + w[x] + w[y] + a + b);
			}
		}
		cout << res << '\n';
	}

	return 0;
}