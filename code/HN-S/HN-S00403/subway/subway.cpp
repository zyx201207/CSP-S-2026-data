#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5, M = 505, INF = 1e18;
int c, n, m, d, q, w[N], k[N], dp[M][M];
vector<pair<int, int> > zhan[N], xian[N];
void solve() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = INF;
        dp[i][i] = 0;
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int a, t; cin >> a >> t;
            xian[i].push_back({a, t});
            zhan[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int xx = 0; xx < zhan[i].size(); xx++) {
            for (int yy = xx + 1; yy < zhan[i].size(); yy++) {
                pair<int, int> x = zhan[i][xx], y = zhan[i][yy];
                dp[x.first][y.first] = min(dp[x.first][y.first], x.second + y.second);
                dp[y.first][x.first] = min(dp[y.first][x.first], x.second + y.second);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--) {
        int x, y; cin >> x >> y;
        int B = w[x] + w[y], ans = INF;
        for (int i = 0; i < zhan[x].size(); i++) {
            for (int j = 0; j < zhan[y].size(); j++) {
                pair<int, int> a = zhan[x][i], b = zhan[y][j];
                //cout << i << " " << j << " " << dp[a.first][b.first] << "\n";
                ans = min(ans, dp[a.first][b.first] + a.second + b.second);
            }
        }
        cout << ans + B << "\n";
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
