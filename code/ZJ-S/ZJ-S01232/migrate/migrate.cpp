#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e6 + 6;
const int M = 5e3 + 6;
int c, t, n;
LL d, x[N];
int dp1[M][M];
int dp2[M][M];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dp1[i][j] = 1e9;
			dp2[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (x[j] - x[i] <= d) {
				dp1[i][j] = 1;
				dp2[i][j] = 1;
			}
		}
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			for (int k = i + 1; k < j; ++k) {
				dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k][j]);
			}
		}
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			for (int k = i + 1; k < j; ++k) {
				if (dp1[i][k] + dp1[k][j] == dp1[i][j]) {
					dp2[i][j] += dp2[i][k] * dp2[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (dp2[i][j] == 2) {
//				cout << i << ' ' << j <<'\n';
				++ans;
			}
		}
	}
	cout << ans << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
