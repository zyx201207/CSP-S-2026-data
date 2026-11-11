//SN-S00518 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;
int c, T, n, m, a[N], dp[N][N];

signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int len = 1; len < n; len++) {
			for (int i = 1; i <= n; i++) {
				int j = i + len;
				bool flag = 1;
				for (int k = i; k <= j; k++) {
					if (a[k] > m) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					continue;
				}
				int minn = len;
				for (int k = i + 1; k < j; k++) {
					minn = min(minn, dp[i][k] + dp[k][j]);
				}
				
			}
		}
	}
	return 0;
}
