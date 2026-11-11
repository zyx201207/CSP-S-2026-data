#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t;
int n, d;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (11 <= c || c <= 12) {
		while (t--) {
			cin >> n >> d;

		}
		return 0;
	}
	while (t--) {
		cin >> n >> d;
		vector<int>x(n + 1, 0);
		vector<int>dp(n + 1, 0);
		vector<bool>vis(n + 1, 0);
		vector<int>t(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			t[x[i]] = i;
		}
		int la = 1;
		for (int i = 1; i <= n; i++) {
			int s = x[i];
			i = la;
			for (int j = 1; j <= d; j++) {
				if ((s + j) > x[n])
					break;
				if (t[s + j] > 0) {
					int k = s + j;
					dp[k] = dp[i] + 1;
					la = k;
				}
			}
		}
	}
	return 0;
}