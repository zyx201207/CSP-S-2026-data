#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int a[N], b[N][N], f[N][N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(b, 0, sizeof b);
		memset(f, 0x3f, sizeof f);
		for (int k = 1; k <= n; k++) {
			f[k][k] = 0;
			b[k][k] = 1;
			for (int i = k; i <= n; i++) {
				for (int j = i + 1; a[j] - a[i] <= d && j <= n; j++) {
					if (f[k][i] + 1 < f[k][j]) f[k][j] = f[k][i] + 1, b[k][j] = b[k][i];
					else if (f[k][i] + 1 == f[k][j]) b[k][j] += b[k][i];
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (f[i][j] > 1 && b[i][j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}