#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<pair<int, int>>> num;
vector<vector<ll>> dis;
vector<int> w;
int c, n, m, d, q;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    w.resize(m + 1);
    num.resize(m + 1);
    dis.assign(n + 1, vector<ll>(n + 1, 1e18));
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int to, w;
            cin >> to >> w;
            num[to].push_back({i, w});
        }
        dis[i][i] = 0;
    }
    for (int p = 1; p <= m; p ++) {
        for (int i = 0; i < num[p].size(); i ++) {
            for (int j = i + 1; j < num[p].size(); j ++) {
                int u = num[p][i].first, v = num[p][j].first;
                int w = num[p][i].second + num[p][j].second;
                dis[u][v] = dis[v][u] = w;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int u, v;
        ll ans = 1e18;
        cin >> u >> v;
        for (auto l : num[u]) {
            for (auto r : num[v]) {
                ans = min(ans, (ll)w[u] + (ll)w[v] + dis[l.first][r.first] + (ll)l.second + (ll)r.second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}