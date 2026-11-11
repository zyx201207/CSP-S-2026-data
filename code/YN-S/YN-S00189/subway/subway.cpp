#include <bits/stdc++.h>
using namespace std;
int w[1005];
int a[505][1005], t[505][1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x3f, sizeof dp);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		dp[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= k; x++) {
				dp[a[i][j]][a[i][x]] =
				    min(dp[a[i][j]][a[i][x]], t[i][j] + t[i][x]);
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
