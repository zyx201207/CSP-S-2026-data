#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005], p[2000005], dis[305][305], f[305][305];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	if (c == 11 || c == 12) {
		while (T--) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			if (n == 1) {
				cout << 0 << '\n';
				continue;
			}
			int dif = a[2] - a[1];
			d /= dif;
			if (!d || d == 1) cout << 0 << '\n';
			else cout << max(n - 2 * d + 1, 0ll) << '\n';
		}
		return 0;
	}
	while (T--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		a[n + 1] = 1e18 + 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) dis[i][j] = 1e18, f[i][j] = 0;
		}
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			p[i] = upper_bound(a + 1, a + 2 + n, a[i] + d) - a - 1;
			for (int j = i + 1; j <= p[i]; j++) dis[i][j] = dis[j][i] = 1, f[i][j] = f[j][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (dis[j][k] > dis[j][i] + dis[i][k]) {
						dis[j][k] = dis[j][i] + dis[i][k];
						f[j][k] = f[j][i] * f[i][k];
					} else if (dis[j][k] == dis[j][i] + dis[i][k]) {
						f[j][k] += f[j][i] * f[i][k];
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (f[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
}
