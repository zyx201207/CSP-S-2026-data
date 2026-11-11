#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int x[N];
int dp[N][N], cnt[N][N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		} 
		int ans = 0;
		memset(dp, 0, sizeof dp);
		memset(cnt, 0x3f, sizeof cnt);
		for (int i = 1; i <= n; ++i) {
			dp[i][i] = 0; 
			cnt[i][i] = 0;
		}
		for (int l = 2; l <= n; ++l) {
			for (int i = 1; i <= n - l + 1; ++i) {
				int j = i + l - 1;
				if(x[j] - x[i] <= d) {
					dp[i][j] = 1;
					cnt[i][j] = 1;
//					cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
					continue;
				}
				dp[i][j] = 0; 
				for (int k = i + 1; k < j; ++k) {
					cnt[i][j] = min(cnt[i][j], cnt[i][k] + cnt[k][j]);
				}
				for (int k = i + 1; k < j; ++k) {
					if(cnt[i][k] + cnt[k][j] != cnt[i][j]) continue;
					dp[i][j] += dp[i][k] * dp[k][j];
				}				
//				cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
				if(dp[i][j] == 2) {
					ans++;
//					cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
