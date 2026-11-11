#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;
int f[N], g[N], x[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[j] = 1e18, g[j] = 0;
			}
			f[i] = 0, g[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				for (int k = j - 1; k >= i; k--) {
					if (x[j] - x[k] <= d) {
						if (f[k] + 1 < f[j]) {
							f[j] = f[k] + 1;
							g[j] = g[k];
						} else if (f[k] + 1 == f[j]) {
							g[j] += g[k];
						}
					}
				}
				if (g[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}