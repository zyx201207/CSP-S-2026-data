#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5, M = 305;
ll c, T, n, d, x[N], dp[M][M][M];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if(c == 11 || c == 12) {
			ll l = x[2] - x[1];
			ll t = d / l;
			if(t == 0 || t == 1) {
				cout << 0 << endl;
			}
			else {
				ll m = t * 2 - 1;
				cout << max(n - m, 0ll) << endl;
			}
		}
		else {
			for(int i = 0; i <= M - 1; i++) {
				for(int j = 0; j <= M - 1; j++) {
					for(int k = 0; k <= M - 1; k++) {
						dp[i][j][k] = 0;
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				dp[i][i][0] = 1;
			}
			for(int l = 1; l <= n; l++) {
				for(int i = 1; i + l - 1 <= n; i++) {
					int j = i + l - 1;
					for(int t = 1; t <= l - 1; t++) {
						int r = 1;
						while(x[i + r] - x[i] <= d && i + r <= j) {
							dp[i][j][t] += dp[i + r][j][t - 1];
							r++;
						}
					}
				}
			}
			ll ans = 0;
//			for(int i = 1; i <= n; i++) {
//				for(int j = i; j <= n; j++) {
//					for(int t = 0; t <= j - i; t++) {
//						cout << dp[i][j][t] << " ";
//					}
//					cout << endl;
//				}
//				cout << endl;
//			}
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					int t = 1;
					while(dp[i][j][t] == 0 && t <= j - i) {
						t++;
					}
					if(t <= j - i && dp[i][j][t] == 2) {
						ans += 1;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
