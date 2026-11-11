#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10, INF = LLONG_MAX;
int c, T, n, d, x[N], dp[N][N], num[N][N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		memset(num, 0, sizeof num);
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) dp[i][j] = 0, num[i][j] = 1;
				else {
					if(abs(x[i] - x[j]) <= d) {
						dp[i][j] = dp[j][i] = 1;
						num[i][j] = 1;
					} else {
						dp[i][j] = INF;
					}
				}
			}
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				if(dp[i][k] == INF) continue;
				for(int j = 1; j <= n; j++) {
					if(dp[k][j] == INF) continue;
					if(dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
						num[i][j] = 1;
					} else if(dp[i][j] == dp[i][k] + dp[k][j] && i != k && k != j) {
						num[i][j]++;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i != j) {
					if(num[i][j] == 2) ans++;
				}
			}
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}
