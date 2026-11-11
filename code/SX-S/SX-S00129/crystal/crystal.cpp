#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[500005], dp[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, i;
	cin >> n >> m;

	for (i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	dp[1] = 1;
	int l = 1, r, mx = 0;
	for (r = 2; r <= n; r++) {
		mx += (a[r] - a[r - 1]) * (r - l);
		dp[r] = dp[r - 1] + 1;
		while (mx > m) {
			mx -= a[r] - a[l];
			dp[r]--;
			l++;
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}
