#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000005], dp[2000005], sum, ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (long long i = 1; i <= n; i++) {
			sum = x[i - 1];
			cin >> x[i];
			for (long long j = lower_bound(x + 1, x + 1 + i, x[i] - d) - x - 1; j <= i; j++) {
				sum += x[i] - x[i - 1];
			}
			if (sum == 2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
