#include <bits/stdc++.h>
#define in long long
using namespace std;
int n, m;
int a[500005],dp[10005][10005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= m; j++) {
			dp[i][j] = 1;
		} 
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j];
		}
	}
	cout << dp[n][m];
	return 0;
}
