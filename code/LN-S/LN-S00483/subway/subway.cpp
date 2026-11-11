# include <algorithm>
# include <iostream>
# include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int to;
    ll w;
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);

    int tid, n, m, Did, Q;
    cin >> tid >> n >> m >> Did >> Q;

    vector<ll> endp(m);
    for (auto &a: endp) {
        cin >> a;
    }

    vector<vector<edge>> conS(m);

    for (int u = 0; u < n; ++u) {
        int cnt;
        cin >> cnt;

        for (int _ = 0; _ < cnt; ++_) {
            int x;
            ll w;
            cin >> x >> w;
            x -= 1;

            conS[x].push_back({u, w});
        }
    }

    vector<vector<ll>> dis(n, vector<ll>(n, inf));
    
    for (int u = 0; u < n; ++u) {
        dis[u][u] = 0;
    }

    for (int x = 0; x < m; ++x) {
        for (auto e1: conS[x]) {
            for (auto e2: conS[x]) {
                dis[e1.to][e2.to] = std::min(dis[e1.to][e2.to], e1.w + e2.w);
                dis[e2.to][e1.to] = std::min(dis[e2.to][e1.to], e1.w + e2.w);
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                dis[u][v] = std::min(dis[u][v], dis[u][x] + dis[x][v]);
            }
        }
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;

        ll ans = inf;
        for (auto e1: conS[u]) {
            for (auto e2: conS[v]) {
                ans = std::min(ans, dis[e1.to][e2.to] + e1.w + e2.w);
            }
        }

        cout << ans + endp[u] + endp[v] << "\n";
    }

    return 0;
}
