#include<iostream>
using namespace std;
const int MAXN = 1e3 + 5;
int c, t, n, k, dp[MAXN][MAXN];
void floyd() {
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
	}
	return;
}
int main () {
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) {
			int u, v;
			cin >> u >> v;
			dp[u][v] = 1;
		}
		floyd();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) cout << dp[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}

