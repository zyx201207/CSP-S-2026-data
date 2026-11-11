#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <queue>
#define int long long
using namespace std;
const int M = 2e4 + 5, N = 505, INF = 1e18, M1 = 5e5 + 5, N1 = 5;
int C, n, m, D, Q, w[M1], k[N1], dis[N][M + N], vis[M1 + N1], dis1[N1][M1 + N1];
struct Node {
    int v, w;
    bool operator < (const Node& t) const {
        return t.w < w;
    }
};
vector<Node> g[M + N];
void Dijkstra(int s) {
    if (C >= 20 && C <= 21) {
        for (int i = 1; i <= m + n; i++) vis[i] = 0, dis1[s][i] = INF;
        dis1[s][m + s] = 0;
        priority_queue<Node> q;
        q.push({m + s, 0});
        while (!q.empty()) {
            Node u = q.top();
            q.pop();
            if (vis[u.v]) continue;
            vis[u.v] = 1;
            for (Node v: g[u.v]) {
                if (dis1[s][u.v] + v.w < dis1[s][v.v]) {
                    dis1[s][v.v] = dis1[s][u.v] + v.w;
                    q.push({v.v, dis1[s][v.v]});
                }
            }
        }
        return;
    }
    for (int i = 1; i <= m + n; i++) vis[i] = 0, dis[s][i] = INF;
    dis[s][m + s] = 0;
    priority_queue<Node> q;
    q.push({m + s, 0});
    while (!q.empty()) {
        Node u = q.top();
        q.pop();
        if (vis[u.v]) continue;
        vis[u.v] = 1;
        for (Node v: g[u.v]) {
            if (dis[s][u.v] + v.w < dis[s][v.v]) {
                dis[s][v.v] = dis[s][u.v] + v.w;
                q.push({v.v, dis[s][v.v]});
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> C >> n >> m >> D >> Q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int v, t;
            cin >> v >> t;
            g[v].push_back({m + i, t});
            g[m + i].push_back({v, t});
        }
    }
    for (int i = 1; i <= n; i++) Dijkstra(i);
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++) cerr << i << "->" << j << ": " << dis[i][j] << '\n';
    for (int i = 1; i <= Q; i++) {
        int x, y, ans = 1e18; cin >> x >> y;
        for (Node v: g[x])
            ans = min(ans, v.w + dis[v.v - m][y]);
        cout << w[x] + w[y] + ans << '\n';
    }
    return 0;
}