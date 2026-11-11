#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505, M = 5e5 + 5;

struct edge { int v, w; };

int c, n, m, d, q, k, u, v, w, val[M];
ll dis[N][N];
vector <edge> to[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> val[i];
    for(int i = 1; i <= n; i++) {
        cin >> k;
        while(k--) {
            cin >> v >> w;
            to[v].push_back({i, w});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            dis[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(edge f : to[i]) {
            for(edge g : to[i]) {
                if(f.v == g.v) continue;
                u = f.v, v = g.v, w = f.w + g.w;
                dis[u][v] = min(dis[u][v], 1ll * w);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || i == k || j == k) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        cin >> u >> v;
        ll ans = 1e18;
        for(edge f : to[u])
            for(edge g : to[v])
                ans = min(ans, val[u] + f.w + dis[f.v][g.v] + g.w + val[v]);
        cout << ans << '\n';
    }
    return 0;
}
