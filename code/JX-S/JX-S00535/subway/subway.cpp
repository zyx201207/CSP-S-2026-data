#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
using namespace std;
const int N = 505;
const int M = 5e5 + 9;
int c, n, m, D, q, idx;
int w[M];
ll dp[N][N]; // line i to j
vector<PII> d[M];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // frropen (^ ^
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, x, y; j <= k; j++) {
            cin >> x >> y;
            d[x].push_back({i, y});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = ((i == j) ? 0 : 1e18);
    for (int i = 1; i <= m; i++) {
        for (auto u : d[i]) {
            for (auto v : d[i]) {
                int x = u.first, y = v.first;
                if (x == y) continue;
                dp[x][y] = min(dp[x][y], (ll)(u.second + v.second));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll res = 1e18;
        for (auto u : d[x]) {
            for (auto v : d[y]) {
                int p = u.first, q = v.first;
                res = min(res, dp[p][q] + u.second + v.second);
            }
        }
        cout << res + w[x] + w[y] << "\n";
    }
    return 0;
}

/*
O(n ^ 3 + d ^ 2 * q + d * m)?
sonanoka?
I love you CCF, please let me pass this question.

*listen and hear
the song is birds are singing.
*sitting down a while
and watch the flowers are blooming.
(huh, I forgot ;))
*/
