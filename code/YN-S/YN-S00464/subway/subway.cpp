#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
const int M = 4e5 + 5000;
int a[M];
int b[N][M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q, k;
	cin >> c >> n >> m >> d >> q;
	if (c == 0) {
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> k;
			for (int j = 1; j <= k; j++) {
				int jj, tt;
				cin >> jj >> tt;
				b[i][jj] = tt;
			}
		}
		int s, f;
		for (int i = 1; i <= q; i++) {
			int minn = LLONG_MAX;
			cin >> s >> f;
			if (b[s][f] != 0) {
				cout << a[s] + a[f] + b[s][f] << "\n";
			} else {
				for (int j = 1; j <= m; j++) {
					if (b[s][j] != 0) {
						if (b[j][f] != 0) {
							int ys = a[s] + a[f] + a[j] + b[s][j] + b[j][f];
							minn = min(minn, ys);
						}
					}
				}
				cout << minn << "\n";
			}
		}
	}
	return 0;
}