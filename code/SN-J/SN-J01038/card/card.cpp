#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005], dp[20005][20005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= m; j++) {
			dp[i][j] = 1;
		}
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + a[i], dp[i - 1][j]);
		}
	}
	cout << dp[n][m];
	return 0;
}
