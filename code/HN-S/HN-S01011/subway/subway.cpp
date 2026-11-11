#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[500001], dp[2001][2001];
// dp中前n个点表示n条线路，n+1~n+m表示站厅 
void solve() {
	cin >> c >> n >> m >> d >> q; 
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int lastx = 0;
		for (int j = 1; j <= x; j++) {
			int a, t;
			cin >> a >> t;
			dp[i][a + n] = dp[a + n][i] = t;
		}
	}
	for (int k = 1; k <= n + m; k++) {
		for (int i = 1; i <= n + m; i++) {
			for (int j = 1; j <= n + m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dp[x + n][y + n] + w[x] + w[y] << '\n';
	}
} 
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	} 
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/ 
