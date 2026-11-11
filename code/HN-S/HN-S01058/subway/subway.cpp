#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 2e4 + 10, M = 510;
int c, n, m, d, q, w[N], a[M][N], t[M][N], f[N][N];
signed main() {
	file(subway);
	cin >> c >> n >> m >> d >> q;
	for (int u = 1; u <= m; ++u)	cin >> w[u];
	memset(f, 0x3f, sizeof f);
	for (int t = 1; t <= m; ++t)	f[t][t] = 0;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)	cin >> a[i][j] >> t[i][j];
		for (int x = 1; x <= k; ++x)	for (int y = x + 1; y <= k; ++y)	f[a[i][x]][a[i][y]] = f[a[i][y]][a[i][x]] = min(t[i][x] + t[i][y], f[a[i][x]][a[i][y]]);
	}
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[j][k]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		ans += f[x][y];
		cout << ans << "\n";
	}
	return 0;
} 
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
