#include <bits/stdc++.h>
using namespace std;
int a[2000009], dp[2000009];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[1] = 0, dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = i - 1; j >= 1 && a[i] - a[j] <= d; j--) {
				dp[i] += dp[j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dp[j] - dp[i] == 2) {
					ans++;
				}
			}
			cout << dp[i] << " ";
		}
		cout << ans << endl;
	}
	return 0;
}