#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		vector<long long> a(n + 1, 0);
		for (long long i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
		long long num = 0;
		for (int len = 2; len <= n; len++) {
			for (int l = 1; l <= n - len + 1; l++) {
				int r = l + len - 1;
				if (a[l] + d <= a[r]) {
					dp[l][r]++;
					for (int k = l + 1; k < r; k++) {
						dp[l][r] += dp[l][k] + dp[k][r];
					}
					if (dp[l][r] == 2) {
						num++;
					}
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
