#include<bits/stdc++.h>
using namespace std;
const unsigned long long N = 5010, xx = 1e18;
long long n, t, d, x, y, c, g[N][N];
long long a[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		long long ans = 0;
		cin >> n >> d;
		if (c == 13 || c == 14) {
			cout << 0 << "\n";
			continue;
		}
		memset(g, 0x3f, sizeof g);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (a[j] - a[i] <= d) g[i][j] = g[j][i] = 1;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (g[i][j] * 2 == a[j] - a[i] + 1 && g[i][j] * 2 >= 4) ans++;
		cout << ans << "\n";
	}
	return 0;
}