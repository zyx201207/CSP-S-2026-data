#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
#define int long long
int c, n, m, d, q;
int f[N][N], w[N], a[N], b[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		f[i][i] = 0;
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		memset(a, 0x3f, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int j = 1, x, t; j <= k; j++) {
			cin >> x >> t;
			b[j] = x;
			a[b[j]] = t;
			for (int l = 1; l < j; l++) {
				f[x][b[l]] = min(f[x][b[l]], a[x] + a[b[l]]);
				f[b[l]][x] = min(f[b[l]][x], a[x] + a[b[l]]);
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + f[x][y] << "\n";
	}
	return 0;
}
