#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 5;
typedef long long LL;
typedef pair<int, LL> PIL;
int c, n, m, d, q;
LL w[M];
int k[N];
vector<PIL> sat[M];
LL g[N][N], f[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for(int j = 1; j <= k[i]; j++) {
            int u; LL t;
            scanf("%d%lld", &u, &t);
            sat[u].push_back(make_pair(i, t));
        }
    }
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            f[i][j] = g[i][j] = (i == j ? 0 : 1e18);
    for(int i = 1; i <= m; i++) {
        int siz = sat[i].size();
        for(int j = 0; j < siz; j++)
            for(int kk = 0; kk < j; kk++) {
                int u = sat[i][j].first, v = sat[i][kk].first;
                LL w1 = sat[i][j].second, w2 = sat[i][kk].second;
                f[u][v] = g[u][v] = f[v][u] = g[v][u] = min(g[u][v], w1 + w2);
            }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--) {
        int qx, qy;
        scanf("%d%d", &qx, &qy);
        LL ans = 1e18;
        int sizx = sat[qx].size(), sizy = sat[qy].size();
        for(int i = 0; i < sizx; i++)
            for(int j = 0; j < sizy; j++)
                ans = min(ans, sat[qx][i].second + f[sat[qx][i].first][sat[qy][j].first] + sat[qy][j].second);
        ans += w[qx] + w[qy];
        printf("%lld\n", ans);

    }
    return 0;
}
