#include <bits/stdc++.h>
using namespace std;

constexpr int N = 524, M = 500024;
typedef long long ll;

int c, n, m, d, q, w[M], ecnt;
ll dis[N][N];
vector<pair<int, int>> ent[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int u, t;
            cin >> u >> t;
            ent[u].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto pu : ent[i]) {
            for (auto pv : ent[i]) {
                int u = pu.first, ut = pu.second;
                int v = pv.first, vt = pv.second;
                dis[u][v] = min<ll>(dis[u][v], ut + vt);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min<ll>(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        int ou, ov;
        cin >> ou >> ov;
        ll ans = 0x3f3f3f3f3f3f3f3fll;
        for (auto pu : ent[ou]) {
            for (auto pv : ent[ov]) {
                int u = pu.first, ut = pu.second;
                int v = pv.first, vt = pv.second;
                ans = min<ll>(ans, ut + dis[u][v] + vt);
            }
        }
        ans += w[ou] + w[ov];
        cout << ans << '\n';
    }
    return 0;
}

// timestamp: 2026/10/31 15:12 (UTC+8)
