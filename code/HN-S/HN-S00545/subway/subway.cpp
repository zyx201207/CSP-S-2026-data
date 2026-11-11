#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5, inf = 1e18;
int n, m, d, q, w[M], g[N][N];
using PII = pair<int, int>;
#define x first
#define y second
vector<PII> v[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int c;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1, x, y; j <= k; j++) cin >> x >> y, v[x].emplace_back(i, y);
    }
    for(int i = 1; i <= m; i++) {
        int k = v[i].size();
        for(int x = 0; x < k; x++) {
            for(int y = x + 1; y < k; y++) {
                auto [a1, b1] = v[i][x];
                auto [a2, b2] = v[i][y];
                g[a1][a2] = min(g[a1][a2], b1 + b2);
                g[a2][a1] = min(g[a1][a2], b1 + b2);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        int res = inf;
        for(auto [a1, b1] : v[x]) {
            for(auto [a2, b2] : v[y]) res = min(res, g[a1][a2] + b1 + b2);
        }
        cout << res + w[x] + w[y] << '\n';
    }
    return 0;
}
/*
乐扣保佑！！！！！！
*/