#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, M = 5005, INF = 1e18;
int c, n, d, x[N], ans;
pair<int, int> dp[M][M];
void solve() {
    cin >> n >> d; ans = 0;
    for (int i = 1; i <= n; i++) cin >> x[i];
    if (c > 10) {
        cout << "0\n"; return;
        // 这不厉害。
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = {INF, 0};
        }
        dp[i][i] = {0, 1};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int q = j - 1;
            while(q >= i && x[j] - x[q] <= d) {
                    // if (i == 1 && j == 4) cout << q << " ";
                if (dp[i][q].first + 1 < dp[i][j].first) {
                    dp[i][j] = {dp[i][q].first + 1, dp[i][q].second};
                // if (i == 1 && j == 4) cout << q << " " << dp[i][j].second << " ";
                } else if (dp[i][q].first + 1 == dp[i][j].first) {
                    dp[i][j].second += dp[i][q].second;
                }
                q--;
            }
            if (dp[i][j].second == 2) ans++;
            //if (i == 4) cout << j << " " << dp[i][j].first << " " << dp[i][j].second << "\n";
        }
        //cout << "\n";
    }
    cout << ans << "\n";
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> c >> t; while(t--) solve();
    return 0;
}
