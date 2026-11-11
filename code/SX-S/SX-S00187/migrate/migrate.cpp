#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			int n, d;
			cin >> n >> d;
			int a, b;
			cin >> a >> b;
			int x;
			for (int i = 3; i <= n; i++)
				cin >> x;
			b = abs(b - a);
			d /= b;
			d++;
			cout << max(0, n - d) << endl;
		}
	} else {
		while (t--) {
			int n, d;
			cin >> n >> d;
			int a[n + 1];
			int ans = 0;
			int dp[n + 1][n + 1];
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				for (int j = 1; j < i; j++) {
					if (a[i] - a[j] <= d)
						dp[j][i] = 1;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {

				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (dp[i][j] == 2)
						ans++;
				}
			}
			cout << ans << endl;

		}
	}
}
