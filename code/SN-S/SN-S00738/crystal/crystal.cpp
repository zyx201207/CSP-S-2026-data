#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans = 0, a[500005], sum[500005], dp[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (m == 0) {
		int ca = a[1];
		for (int i = 1; i <= n; i++) {
			if (ca == a[i]) ans++;
		}
		if (ans == 1) {
			cout << 0;
			return 0;
		}
	}
	else {
		sum[1] = a[1];
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
		int op = 0;
		for (int j = 2; j <= n; j++) {
			dp[j] = (j - 1) * a[j] - sum[j - 1];
			if (dp[j] == m) op = j;
		}
		for (int i = 1; i <= op; i++) a[i] = a[op];
		int cb = a[1];
		for (int i = 1; i <= n; i++) {
			if (cb == a[i]) ans++;
		}
		if (ans == 1) {
			cout << 0;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
