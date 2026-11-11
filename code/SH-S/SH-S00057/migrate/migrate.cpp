#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010] = {};
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int tk = 1; tk <= t; tk++) {
		for (int i = 1; i <= 5000; i++) {
			for (int j = 1; j <= 5000; j++) {
				dp[i][j] = 0;
			} 
		}
		int n;
		long long d;
		cin >> n >> d;
		long long x[5010] = {};
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			dp[i][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				for (int k = 1; k < j; k++) {
					if (x[j] - x[j - k] > d) break;
					dp[i][j] += dp[i][j - k];
				}
//				cout << dp[i][j] << ' ';
			}
//			cout << endl;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dp[i][j] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
