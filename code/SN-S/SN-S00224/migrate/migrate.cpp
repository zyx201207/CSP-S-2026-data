#include<bits/stdc++.h>
using namespace std;
int a[2000005], nxt[2000005], f[2000005], dp[2000005];
int sum[20000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			if (a[i] + d > a[n]) nxt[i] = n;
			else nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		}
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			if (nxt[i] == n) {
				f[i] = n - i + 1;
				continue;
			}
			int x1 = nxt[nxt[i]], x2 = nxt[nxt[i] - 1], x3 = nxt[nxt[i] - 2];
			f[i] = nxt[i] - i;
			if (nxt[i] == i) {f[i] = 1; continue;}
			else if (nxt[i] == i + 1) {
				dp[i] += dp[nxt[i]];
				f[i] += f[nxt[i]];
			}else {
				if (x1 != x2) {
					f[i] += f[x1];
					dp[i] += dp[x1];
				}else {
					if (x2 != x3) {
						dp[i] += f[x1];
					}
				}
			}
			ans += dp[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
