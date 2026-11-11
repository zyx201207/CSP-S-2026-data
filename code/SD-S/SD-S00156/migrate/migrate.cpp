#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int N = 305;
int c, T, n, d, a[N], cnt[N][N], f[N][N], ans;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i != j && abs(a[i] - a[j]) <= d) {
					f[i][j] = 1;
					f[j][i] = 1;
					cnt[i][j] = cnt[j][i] = 1;
				} else {
					f[i][j] = 0;
					f[j][i] = 0;
					cnt[i][j] = cnt[j][i] = 0;
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (i == k) continue;
				for (int j = 1; j <= n; j++) {
					if (i != j && f[i][k] != 0 && f[k][j] != 0) {
						if (f[i][j] == 0) {
							f[i][j] = f[i][k] + f[k][j];
							cnt[i][j] = cnt[i][k] * cnt[k][j];
						} else if (f[i][j] > f[i][k] + f[k][j]) {
							f[i][j] = f[i][k] + f[k][j];
							cnt[i][j] = 1;
						} else if (f[i][j] == f[i][k] + f[k][j]) {
							cnt[i][j] += cnt[i][k] * cnt[k][j];
						} else {
							continue;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i != j && cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
