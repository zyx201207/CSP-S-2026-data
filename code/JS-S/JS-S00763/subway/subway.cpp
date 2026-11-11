#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Inf = 1e18;

const int L = 510, S = 5e5 + 10;

int c, n, m, d, q;

int w[S];

ll dist[L][L];

vector<pair<int, int> > g[S];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++) {
        scanf("%d", w + i);
    }
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        int u, t;
        for (int j = 1; j <= k; j++) {
            scanf("%d%d", &u, &t);
            g[u].emplace_back(make_pair(i, t));
        }
    }
    for (int i = 1; i <= m; i++) {
        int s = g[i].size();
        for (int j = 0; j < s; j++) {
            for (int k = j + 1; k < s; k++) {
                int u = g[i][j].first, v = g[i][k].first;
                dist[u][v] = min(dist[u][v], 0ll + g[i][j].second + g[i][k].second);
            }
        }
    }
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll d1 = (i <= k ? dist[i][k] : dist[k][i]);
                ll d2 = (k <= j ? dist[k][j] : dist[j][k]);
                dist[i][j] = min(dist[i][j], d1 + d2);
            }
        }
    }
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        ll ans = Inf;
        int su = g[u].size(), sv = g[v].size();
        for (int j = 0; j < su; j++) {
            for (int k = 0; k < sv; k++) {
                int s = g[u][j].first;
                int t = g[v][k].first;
                ans = min(ans, (s <= t ? dist[s][t] : dist[t][s]) + g[u][j].second + g[v][k].second);
            }
        }
        printf("%lld\n", ans + w[u] + w[v]);
    }
    return 0;
}
