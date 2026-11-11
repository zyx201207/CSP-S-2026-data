#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, ans, a[5001], dp[5001][5001]; 
// 这是从i到j的路径数量 
void solve() {
	cin >> n >> m;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 0; 
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][i] = 1; // 初始条件 
	}
	for (int len = 1; len <= n - 1; len++) {
		for (int i = 1; i + len <= n; i++) {
			int j = i + len;
			// 枚举中转点 
			if (len == 1) {
				dp[i][j] = (a[i + 1] - a[i] <= m);
				continue;
			}
			for (int k = i + 1; k <= j - 1; k++) {
				dp[i][j] += dp[i][k] * dp[k][j]; 
			}
			dp[i][j] += (a[j] - a[i] <= m);
			if (dp[i][j] == 2) {
				ans++;
			}
		} 
	}
	cout << ans - 1 << '\n';
} 
/*
dp[1][1] = 1 dp[2][2] = 1 dp[3][3] = 1 dp[4][4] = 1
dp[1][2] = 1 dp[2][3] = 1 dp[3][4] = 1
dp[1][3] = 2 dp[2][4] = 2
dp[1][4] = 2 + 2 + 1 = 5 ?
*/
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while (T--) {
		solve();
	} 
}

/*

显然，海鸟不会回头 

*/

/*

luogu UID: 1273514

*/
