#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
#define int  long long
int c, T, n, d, a[N], f[N][N], v[N][N], g[N][N], cnt[N][N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		memset(f, 0x3f, sizeof(f));
		memset(g, 0x3f, sizeof(g));
		memset(v, 0, sizeof(v));
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f[i][i] = 0;
			g[i][i] = 0;
			for (int j = 1; j < i; j++) {
				if (a[i] < 0 && a[j] < 0) {
					int w = (-a[j]) + a[i];
					if (w <= d) {
						f[j][i] = 1;
						g[j][i] = 1;
						cnt[j][i] = 1;
					}
				} else {
					int w = a[i] - a[j];
					if ( w <= d) {
						f[j][i] = 1;
						g[j][i] = 1;
						cnt[j][i] = 1;
					}
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1 ; j <= n; j++) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i < k; i++) {
				for (int j = k + 1 ; j <= n; j++) {
					if (g[i][k] + g[k][j] == f[i][j]) {
						cnt[i][j] += cnt[i][k] * cnt[k][j];
					}
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1 ; j <= n; j++) {
				if (cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

