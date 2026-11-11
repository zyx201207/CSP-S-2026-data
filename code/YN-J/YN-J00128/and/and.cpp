#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200005] = {};

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
//	int dp[n + 2][m + 2] = {};
//	memset(dp, 0x01, sizeof(dp));
//	cout << dp[1][1] << "\n";
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			dp[i][j] = dp[i - 1][j];
//			dp[i][j] = max(dp[i][j], (long long)(dp[i - 1][j - 1] & a[i]);
//			cout << i << " " << j << " " << dp[i][j] << "\n";
//		}
//	}
	cout << a[1];
	return 0;
}
