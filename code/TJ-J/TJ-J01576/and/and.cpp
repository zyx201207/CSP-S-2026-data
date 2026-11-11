#include <bits/stdc++.h>
using namespace std;
long long f[10000001], maxx = -999999, dp[10000001], n, m, a[10000001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long s = a[1];
	if (n == m) {
		for (int i = 2; i <= m; i++) {
			s = s & a[i];
		}
		cout << s;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[m] = a[i];
		for (int j = m; j >= 1; j--) {
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	cout << dp[m];
	return 0;
}