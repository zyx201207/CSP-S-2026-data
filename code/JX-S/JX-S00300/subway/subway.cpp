#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using edge = pair<int, ll>;

const int N = 5e5 + 5, D = 25, ND = 2000 + 5;
const ll INF = 1e18;

int c, n, m, d, q;
vector<int> sts[N];
ll w[N];
vector<edge> a[N];
ll G[ND][ND];
int zhall[N], zt[N][D], ntot;

void floyd() {
    for (int k = 1; k <= ntot; k++) {
        for (int i = 1; i <= ntot; i++) {
            for (int j = 1; j <= ntot; j++) {
                G[i][j] = min(G[i][j], G[k][i] + G[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int an, at;
            cin >> an >> at;
            sts[an].push_back(i);
            a[i].emplace_back(an, at);
        }
    }
    for (int i = 1; i <= m; i++) {
        zhall[i] = ++ntot;
        for (int j = 0; j < sts[i].size(); j++) {
            zt[i][j] = ++ntot;
        }
    }
    for (int i = 1; i <= ntot; i++) {
        for (int j = 1; j <= ntot; j++) {
            G[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < a[i].size(); j++) {
            int x = a[i][j - 1].first, y = a[i][j].first;
            int u = lower_bound(sts[x].begin(), sts[x].end(), i) - sts[x].begin();
            int v = lower_bound(sts[y].begin(), sts[y].end(), i) - sts[y].begin();
            G[zt[x][u]][zt[y][v]] = 0;
            G[zt[y][v]][zt[x][u]] = 0;
        }
        for (int j = 0; j < a[i].size(); j++) {
            int x = a[i][j].first;
            ll w = a[i][j].second;
            int y = lower_bound(sts[x].begin(), sts[x].end(), i) - sts[x].begin();
            G[zhall[x]][zt[x][y]] = G[zt[x][y]][zhall[x]] = min(G[zt[x][y]][zhall[x]], w);
        }
    }
    floyd();
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << G[zhall[u]][zhall[v]] + w[u] + w[v] << '\n';
    }
    return 0;
}

// Can Floyd AC testcases 9~11? I think it can.
// [32, 44]pts.