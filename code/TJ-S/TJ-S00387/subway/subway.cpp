#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m);
    vector<vector<pair<int, int>>> a(n), bel(m);
    for (int i = 0; i < m; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].assign(k, {0, 0});
        for (int j = 0; j < k; j++) {
            cin >> a[i][j].first >> a[i][j].second, a[i][j].first--;
            bel[a[i][j].first].push_back({i, a[i][j].second});
        }
    }

    auto dist = [&]() -> vector<vector<int>> {
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < m; i++)
            for (auto [u, wu] : bel[i])
                for (auto [v, wv] : bel[i])
                    dist[u][v] = min(dist[u][v], wu + wv);
        
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;
    }();

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        int ans = inf;
        for (auto [us, wu] : bel[u])
            for (auto [vs, wv] : bel[v])
                ans = min(ans, wu + wv + dist[us][vs]);
        cout << ans + w[u] + w[v] << "\n";
    }

    return 0;
}