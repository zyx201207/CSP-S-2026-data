#include <bits/stdc++.h>

using namespace std;

#define int long long
const int maxn = 5005;

int dp[maxn][maxn], sdp[maxn][maxn], x[maxn], dis[maxn]; 

void solve() {
	int n, d; cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	int ans = 0;
	for (int st = 1; st <= n; ++st) {
//		memset(dp, 0, sizeof dp);
//		memset(sdp, 0, sizeof sdp);
		memset(dis, 0, sizeof dis);
		for (int i = 1; i < st; ++i) dp[i][0] = sdp[i][0] = 0;
		for (int i = st; i <= n; ++i) sdp[i][0] = 1, dp[i][0] = 0;
		dp[st][0] = 1;
		for (int j = 1; j <= n - st + 1; ++j) {
			for (int i = 1; i <= st; ++i) dp[i][j] = sdp[i][j] = 0;
			for (int i = st + 1; i <= n; ++i) {
				sdp[i][j] = dp[i][j] = 0;
				if (x[i] - x[i - 1] > d) break;
				int pos = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
				dis[i] = dis[pos] + 1;
				if (pos) dp[i][j] = sdp[i - 1][j - 1] - sdp[pos - 1][j - 1];
//				cout << dp[i][j] << " ";
				if (dp[i][j] == 2 && j == dis[i]) ans++; 
				sdp[i][j] = sdp[i - 1][j] + dp[i][j];
			}
//			cout << endl;
		}
	}
	cout << ans << endl; 
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; cin >> c >> T;
	while (T--) solve(); 
	return 0; 
} 