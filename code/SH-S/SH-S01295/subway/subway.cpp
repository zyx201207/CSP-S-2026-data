#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
int c, n, m, d, q;
long long w[500010], f[510][510];
vector<pair<int, int> > subway[500010];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	rep (i, 1, m) {
		cin >> w[i];
	}
	rep (i, 1, n) {
		int k;
		cin >> k;
		rep (j, 1, k) {
			int a, t; cin >> a >> t;
			subway[a].push_back({i, t});
		}
	}
	// 建图
	rep (i, 1, n) {
		rep (j, 1, n) {
			f[i][j] = 0x3f3f3f3f3f3f3f3f;
		}
		f[i][i] = 0;
	}
	rep (i, 1, m) {
		for (auto j: subway[i]) {
			int u = j.first, w1 = j.second;
			for (auto k: subway[i]) {
				int v = k.first, w2 = k.second;
				f[u][v] = min(f[u][v], 1ll * w1 + w2);
			}
		}
	}
	// rep (i, 1, n) {
		// rep (j, 1, n) {
			// cout << f[i][j] << " ";
		// }
		// cout << "\n";
	// }
	// Floyd
	rep (k, 1, n) {
		rep (i, 1, n) {
			rep (j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	// rep (i, 1, n) {
		// rep (j, 1, n) {
			// cout << f[i][j] << " ";
		// }
		// cout << "\n";
	// }
	// 查询
	rep (i, 1, q) {
		int x, y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (auto j: subway[x]) {
			int u = j.first, w1 = j.second;
			for (auto k: subway[y]) {
				int v = k.first, w2 = k.second;
				// cout << u << " " << v << " " << w1 << " " << w2 << " " << f[u][v] + w[x] + w[y] + w1 + w2 << "\n";
				ans = min(ans, f[u][v] + w[x] + w[y] + w1 + w2);
			}
		}
		cout << ans << "\n";
	}
}
// Passed at 15:46