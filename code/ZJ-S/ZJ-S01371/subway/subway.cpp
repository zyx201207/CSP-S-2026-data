#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
inline int read() {
    int res = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}
const int maxn = 505, maxm = 5e5 + 10;
int c, n, m, d, q, w[maxm], k[maxn];
vector<pair<int, int> > vec[maxm];
long long dp[maxn][maxn];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        k[i] = read();
        for (int j = 1; j <= k[i]; j++) {
            int a = read(), t = read();
            vec[a].push_back({t, i});
        }
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < vec[i].size(); i++) {
            int t = vec[i][j].first, v = vec[i][j].second;
            for (int k = 0; k < vec[i].size(); k++) {
                int t2 = vec[i][k].first, v2 = vec[i][k].second;
                dp[v][v2] = dp[v2][v] = min(dp[v][v2], 1ll * t + t2);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--) {
        int x = read(), y = read();
        long long ans = 1e18;
        for (int i = 0; i < vec[x].size(); i++) {
            int t = vec[x][i].first, v = vec[x][i].second;
            for (int j = 0; j < vec[y].size(); j++) {
                int t2 = vec[y][j].first, v2 = vec[y][j].second;
                ans = min(ans, t + t2 + dp[v][v2]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
