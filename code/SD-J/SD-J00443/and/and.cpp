#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
long long n, m, mx = -2e9, maxn = -2e9, ansn, maxx = -2e9, ma = -2e9, m1, m2;
long long a[N], dp[205][205];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
		ansn &= a[i];
	}
	if (m == 1) {
		cout << mx;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn;
		return 0;
	} else if (m == n) {
		cout << ansn;
		return 0;
	} else if (m == n - 1) {
		for (int i = 1; i <= n; ++i) {
			maxx = max(maxx, ansn ^ a[i]);
		}
		cout << maxx;
		return 0;
	} else if (n <= 200) {
		for (int i = 1; i <= n; ++i) {
			dp[1][i] = a[i]; 
		}
		for (int i = 2; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n && k != j; ++k) {
					dp[i][j] = max(dp[i][j], dp[i - 1][k] & a[j]);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			ma = max(ma, dp[m][i]);
		}
		cout << ma;
	} else {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= m; ++i) {
			m1 &= a[i];
			m2 &= a[m - i + 1];
		}
		cout << max(m1, m2);
	}
	return 0;
}
