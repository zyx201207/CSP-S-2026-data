#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1200;
int w[M], cnt[M], a[M][M], t[M][M];
int xs, xe, ys, ye;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cnt[i];
		for (int j = 1; j <= cnt[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int bol = 1, bl = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt[i]; j++) {
				if (a[i][j] == x) {
					xs = i;
					ys = j;
					bol = 0;
					j = 2e9;
				}
			}
			for (int j = 1; j <= cnt[i]; j++) {
				if (a[i][j] == y) {
					xe = i;
					ye = j;
					bl = 0;
					j = 2e9;
				}
			}
			if (bol == 0 && bl == 0) {
				i = 2e9;
			}
		}
		ans += w[xs];
		ans += w[xe];
		ans += t[xs][ys];
		if (xe >= xs) {
			for (int i = xs; i <= xe; i++) {
				if (i == xe) {
					ans += t[xe][ye];
					cout << ans << '\n';
				}
				for (int j = 1; j <= cnt[i]; j++) {
					if (a[i][j] == a[i + 1][j]) {
						ans = ans + (t[i][j] + t[i + 1][j]);
						j = 2e9;
					}
				}
			}
		} else {
			for (int i = xs; i >= xe; i--) {
				if (i == xe) {
					ans += t[xe][ye];
					cout << ans << '\n';
				}
				for (int j = 1; j <= cnt[i]; j++) {
					if (a[i][j] == a[i - 1][j]) {
						ans = ans + (t[i][j] + t[i - 1][j]);
						j = 2e9;
					}
				}
			}
		}
	}
}