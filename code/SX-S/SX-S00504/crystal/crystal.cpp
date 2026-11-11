#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], sum[500010], dp[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		if (a[i]*i - sum[i] <= m) {
			dp[i] = i;
		} else {
			long long  l = 1, r = i - 1, p = 0;
			while (l <= r) {
				long long mid = (l + r) / 2;
				if (a[i] * (i - mid) - sum[i] + sum[mid] == m) {
					p = mid;
					break;
				}
				if (a[i] * (i - mid) - sum[i] + sum[mid] > m) {
					l = mid + 1;
				}
				if (a[i] * (i - mid) - sum[i] + sum[mid] < m) {
					p = mid;
					r = mid - 1;
				}
			}
			dp[i] = dp[i - 1];
			if (p != 0) {
				dp[i] = max(dp[i], i - p);
			}
		}
	}
	cout << dp[n];
	return 0;
}
