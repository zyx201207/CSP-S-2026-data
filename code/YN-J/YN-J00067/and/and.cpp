#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];

int dp[2005][2005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	memset(dp,-127,sizeof(dp));
	dp[1][1] = a[1];
	for (int i = 1; i <= n; i++) {
		dp[i][1] = a[i];
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] & a[i], dp[i][j - 1] & a[i]);
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	cout << dp[n][m];
	return 0;
}