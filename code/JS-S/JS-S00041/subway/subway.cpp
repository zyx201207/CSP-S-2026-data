#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10, M = 5e2 + 10;
int c, n, m, d, qu, k[M], a;
ll w[N];
ll dis[M][M], t;
vector<pair<int,ll> > node[N];
//vector<pair<int,int> > g[M];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> qu;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a >> t;
            node[a].push_back({i, t});
        }

    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < node[i].size(); j++) {
            for (int k = j + 1; k < node[i].size(); k++) {
                int u = node[i][j].first, v = node[i][k].first;
                ll w = node[i][j].second + node[i][k].second;
                // g[u].push_back({v, w});
                // g[v].push_back({u, w});
                dis[u][v] = w;
                dis[v][u] = w;
            }
        }
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = dis[i][j];
            }
        }
    }
    // cout << dis[1][2] << '\n';
    // for (int i = 1; i <= m; i++) {
    //     for (pair<int,int> x : node[m]) {
    //         cout << x.first << ' ' << x.second << endl;
    //     }
    // }
    while (qu--) {
        int x, y;
        ll ans = LONG_LONG_MAX;
        cin >> x >> y;
        for (int i = 0; i < node[x].size(); i++) {
            int u = node[x][i].first;
            for (int j = 0; j < node[y].size(); j++) {
                int v = node[y][j].first;
                // cout << u << ' ' << v << '\n';
                // cout << node[x][i].second << ' ' << node[y][j].second << '\n';
                ans = min(ans, dis[u][v] + node[x][i].second + node[y][j].second);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
// 0 2 5 20 2
// 4 1 9 2 5
// 3 1 5 2 7 4 6
// 3 2 3 3 4 5 7
// 1 3
// 1 2
