#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, x[2000005], dp[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		long long ans = 0;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= d && i - j > 0; j++) {
				dp[i] += dp[i - j];
			}
			if (dp[i] >= 2) {
				ans++;
			}
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}
