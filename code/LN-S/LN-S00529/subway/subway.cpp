#include<bits/stdc++.h>
#define FILE "subway"
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

namespace FakeWilson {
const int M = 5e5 + 5;
const int N = 505;
vector<pii> rou[M];
i64 G[N][N];
int w[M];

signed main() {
    int c, n, m, d, q;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%d", w + i);
    memset(G, 0x3f, sizeof(G));
    for(int i = 1; i <= n; i++) {
        int k; G[i][i] = 0;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            int v, t;
            scanf("%d%d", &v, &t);
            rou[v].emplace_back(i, t);
        }
    }
    for(int i = 1; i <= m; i++) {
        int num = rou[i].size();
        for(int j = 0; j < num; j++) {
            for(int k = j + 1; k < num; k++) {
                auto [x, t1] = rou[i][j];
                auto [y, t2] = rou[i][k];
                G[x][y] = G[y][x] = min(G[x][y], (i64)(t1 + t2));
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    while(q--) {
        int x, y;
        i64 ans = 1e18;
        scanf("%d%d", &x, &y);
        for(int i = 0; i < rou[x].size(); i++) {
            for(int j = 0; j < rou[y].size(); j++) {
                auto [r1, t1] = rou[x][i];
                auto [r2, t2] = rou[y][j];
                ans = min(ans, t1 + t2 + G[r1][r2]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}
