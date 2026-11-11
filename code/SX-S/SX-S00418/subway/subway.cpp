#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], k[505], x, y;
int a[505][500005], t[505][500005];
int ans, e[500005][500005], minn = 999999;
bool b[500005][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][a[i][j]];
			b[a[i][j]][i] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (i != j) {
				minn = 999999;
				for (int l = 1; l <= n; l++) {
					if (b[i][l] == 1 && b[j][l] == 1) {
						minn = min(minn, t[l][i] + t[l][j]);
					}
					e[i][j] = e[j][i] = minn;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (e[i][j] == 0) {
				minn = 999999;
				for (int l = i + 1; l <= m; l++) {
					for (int p = 1; p < j; p++) {
						if (e[i][l] != 0 && e[p][j] != 0 && l == p) {
							minn = min(minn, e[i][l] + e[p][j]);
						}
					}
					e[i][j] = e[j][i] = minn;
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		ans = w[x] + w[y] + e[x][y];
		cout << ans;
	}
	return 0;
}
