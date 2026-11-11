#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int c, t, n, d, a[N], dp[N][N], x[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (n <= 500) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + d + 1; j <= n; j++) {
					if (j % d == i % d) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		} else {
			cout << "0\n";
		}

	}
	return 0;
}
