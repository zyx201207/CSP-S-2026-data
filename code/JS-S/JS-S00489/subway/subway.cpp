#include<bits/stdc++.h>
using namespace std;
#define N (500)
#define M (500000)
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

int c, n, m, d, q;
int w[M + 5];
vector<pii> vec[M + 5];

ll mp[N + 5][N + 5];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", w + i);
    }
    for (int i = 1, k; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 1, a, t; j <= k; ++j) {
            scanf("%d%d", &a, &t);
            vec[a].push_back({i, t});
        }
    }
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; ++i) { mp[i][i] = 0; }
    for (int i = 1; i <= m; ++i) {
        for (auto x : vec[i]) {
            for (auto y : vec[i]) {
                if (x.fi == y.fi) { continue; }
                mp[x.fi][y.fi] = min(mp[x.fi][y.fi], 1ll * x.se + y.se);
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (int i = 1, x, y; i <= q; ++i) {
        scanf("%d%d", &x, &y); ll ans = 1e18;
        for (auto a : vec[x]) {
            for (auto b : vec[y]) {
                ans = min(ans, w[x] + w[y] + mp[a.fi][b.fi] + a.se + b.se);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
