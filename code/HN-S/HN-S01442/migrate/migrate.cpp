// lichenxi108.rp = inf

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int N0 = 5e3 + 5;
int c, q, n;
long long m, a[N], dis[N0][N0], dp[N0][N0];
bool fail[N0][N0];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			fail[i][j] = 0;
			if (a[j] - a[i] <= m) dis[i][j] = 1, dp[i][j] = 1;
			else dis[i][j] = 1e9, dp[i][j] = 0;
		}
	}
	int ans = 0;
	for (int l = 3; l <= n; l++) {
		for (int i = 1, j; i + l - 1 <= n; i++) {
			j = i + l - 1;
			if (dis[i][j] == 1) continue;
			for (int k = i + 1; k <= j - 1; k++) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					fail[i][j] = 0;
					dis[i][j] = dis[i][k] + dis[k][j];
					dp[i][j] = dp[i][k] * dp[k][j];
					if (dp[i][j] > 2 || fail[i][k] || fail[k][j]) fail[i][j] = 1;
				}
				else if (dis[i][k] + dis[k][j] == dis[i][j]) {
					dp[i][j] += dp[i][k] * dp[k][j];
					if (dp[i][j] > 2) fail[i][j] = 1;
				}
			}
			if (dp[i][j] == 2 && !fail[i][j]) ++ans;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << a[i + 1] - a[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << i << ' ' << j << ' ' << dis[i][j] << ' ' << dp[i][j] << '\n';
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> q;
	while (q--) solve();
	return 0;
} 
