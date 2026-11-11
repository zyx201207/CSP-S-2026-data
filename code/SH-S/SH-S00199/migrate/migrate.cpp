#include <bits/stdc++.h>
#define ll __int128
using namespace std;

inline ll read() {
	ll res = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	} 
	while (isdigit(c)) {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
inline void write(ll res) {
	if (res < 0) {
		res = -res;
		putchar('-'); 
	} 
	if (res > 9) write(res / 10);
	putchar(res % 10 + '0');
}

const int maxN = 5010;
ll c, t, n, d, ans, x[maxN], dp[maxN][maxN], cnt[maxN][maxN];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) {
		n = read(), d = read();
		ans = 0;
		for (int i = 1; i <= n; i++) x[i] = read();
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					dp[i][j] = dp[j][i] = x[j] - x[i];
					cnt[i][j] = cnt[j][i] = 1;
				} else break;
			}
			dp[i][i] = 0;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
						cnt[i][j] = cnt[i][k] * cnt[k][j];
					} else if (dp[i][j] == dp[i][k] + dp[k][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];	
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2) {
					// cout << i << ", " << j << '\n';
					ans++;
				}
			}
		}
		write(ans);
		putchar('\n');
	} 
	return 0; 
}
