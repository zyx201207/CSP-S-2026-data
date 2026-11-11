#include <bits/stdc++.h>

using namespace std;

int n, m, a[2005], dp[2005][2005];

int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = max (dp[i - 1][1], a[i]);
		for (int j = 2; j <= min (m, i); j++) {
			dp[i][j] = max (dp[i - 1][j - 1] & a[i], dp[i - 1][j]);
		}
	}
	cout << dp[n][m];
	fclose (stdin);
	fclose (stdout);
	return 0;
} 
