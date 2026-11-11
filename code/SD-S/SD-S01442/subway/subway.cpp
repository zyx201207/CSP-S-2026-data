#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m, a[500010], c[500010], z[500010], dis[100010];
bool vis[100010];
vector<pair<int, int>> g[100010];

int encode(int x, int y) {
    return (x - 1) * (n + 1) + y;
}

pair<int, int> decode(int x) {
    return {x / (n + 1), x % (n + 1)};
}

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(int) * ((n + 1) * (m + 1) + 514));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto &i : g[u]) {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc, d, q;
    cin >> tc >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> z[i];
    }
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        for (int j = 1; j <= h; j++) {
            cin >> a[j] >> c[j];
            g[encode(a[j], 0)].push_back({encode(a[j], i), c[j]});
            g[encode(a[j], i)].push_back({encode(a[j], 0), c[j]});
        }
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= h; k++) {
                g[encode(a[j], i)].push_back({encode(a[k], i), 0});
                g[encode(a[k], i)].push_back({encode(a[j], i), 0});
            }
        }
    }
    while (q--) {
        int ui, vi;
        cin >> ui >> vi;
        dijkstra(encode(ui, 0));
        cout << z[ui] + z[vi] + dis[encode(vi, 0)] << '\n';
    }
    return 0;
}
