#include <bits/stdc++.h>
#define int long long
const int N = 5e5 + 10;
using namespace std;
int a[505][505], t[505][505];
int w[N];
vector<pair<int, int> > g[505];
int dis[505], vis[505];

void dij(int s) {
    priority_queue<pair<int, int> > q;
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0 ,sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto to : g[x]) {
            int y = to.first, z = to.second;
            if (dis[x] + z < dis[y]) {
                dis[y] = dis[x] + z;
                if (!vis[y])
                q.push({-dis[y], y});
            }
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    if (c == 0) {

    }
    for (int i = 1; i <= m; i ++)
        cin >> w[i];
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            int u, v;
            cin >> u >> v;
            a[i][j] = u;
            t[i][j] = v;
//            g[u].push_back(v);
//            g[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            int u = a[i][j], v = t[i][j];
            g[u].push_back({v, t[u][v] + t[v][v]});
        }
    }
    while (q --) {
        int x, y;
        cin >> x >> y;
        dij(x);
        cout << dis[y] + w[x] + w[y] << '\n';
    }
    return 0;
}
