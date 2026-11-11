#include <bits/stdc++.h>
using namespace std;

const int N = 500, M = 5e5, D = 20, Q = 1e5, W = 1e9, T = 1e9;

int w[M + 5], a[M + 5], t[M + 5];
long long dis[3005][3005];
bool vis[M + 5];

vector<pair<int, long long>> graph[M + 5];

void dfs(int st, int u, long long ww) {
    vis[u] = true;
    dis[st][u] = dis[u][st] = ww;
    for (pair<int, int> t : graph[u]) {
        int v, w;
        tie(v, w) = t;
        if (vis[v])
            continue;
        if (ww + w < dis[st][v])
            dfs(st, v, ww + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
            cin >> a[j] >> t[j];
        for (int j = 1; j < k; j++)
            for (int l = j + 1; l <= k; l++) {
                graph[a[j]].push_back({a[l], t[j] + t[l]});
                graph[a[l]].push_back({a[j], t[j] + t[l]});
            }
    }
    for (int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i, 0);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] + dis[x][y] << '\n';
    }
    return 0;
}
