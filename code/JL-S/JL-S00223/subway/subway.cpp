#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10, M = 510;
const ll inf = 1000000000000000000ll;
struct node { int v, w; };
ll w[N], k[N], dis[M][M];
vector<node> g[N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int u, t;
            cin >> u >> t; 
            g[u].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = inf * (i != j);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            for (int k = j+1; k < (int)g[i].size(); k++) {
                ll u = g[i][j].v, v = g[i][k].v, s = g[i][j].w, t = g[i][k].w;
                dis[u][v] = dis[v][u] = min(dis[u][v], s+t);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        ll res = inf;
        for (int i = 0; i < (int)g[u].size(); i++) {
            for (int j = 0; j < (int)g[v].size(); j++) {
                res = min(res, dis[g[u][i].v][g[v][j].v]+g[u][i].w+g[v][j].w);
            }
        }
        cout << res + w[u] + w[v] << "\n";
    }
    return 0;
}
