#include<bits/stdc++.h>
using namespace std;
long long Read() {
	long long x = 0, f = 1;
	char c;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x*f;
}
const long long N = 5e3+5;
long long dp[N][N], dp2[N][N];
long long c, T, n, d, x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		n = Read();
		d = Read();
		memset(dp, 0x3f, sizeof dp);
		memset(dp2, 0, sizeof dp2);
		for (long long i = 1; i <= n; i++) {
			x[i] = Read();
		}
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					dp[i][j] = 1;
					dp2[i][j] = 1;
				} else {
					break;
				}
			}
		}
		for (long long k = 1; k <= n; k++) {
			for (long long i = 1; i <= n; i++) {
				for (long long j = 1; j <= n; j++) {
					if (i == j || j == k || i == k)continue;
					if (dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
						dp2[i][j] = dp2[i][k] * dp2[k][j];
					} else if (dp[i][j] == dp[i][k] + dp[k][j]) {
						dp2[i][j] += dp2[i][k] * dp2[k][j];
					}
				}
			}
		}
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				if (dp2[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}