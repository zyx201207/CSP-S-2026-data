#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 100, M = 1e5 + 100;
#define int long long
struct Edge {
    int v, w;
};
vector<Edge> g[2*M];
int node = 0;
int dijkstra(int s, int t) {
    int dis[M];
    bool vis[M];
    for (int i = 1; i <= node; i ++) dis[i] = 1e17, vis[i] = false;
    dis[s] = 0;
    priority_queue <pair<int, int> > pq;
    pq.push({0, s});
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue ;
        vis[u] = true;
        for (auto x : g[u]) {
            int v = x.v, w = x.w;
            if (dis[v] >= dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
    return dis[t];
}
int w[N];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    node = m;
    for (int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++) {
        int k; cin >> k;
        int pre = 0;
        for (int i = 1; i <= k; i ++) {
            int a, t; cin >> a >> t;
            node ++;
            if (pre != 0) {
                g[node].push_back({pre, 0});
                g[pre].push_back({node, 0});
            }
            pre = node;
            g[node].push_back({a, t});
            g[a].push_back({node, t});
        }
    }
    while (q --) {
        int s, t; cin >> s >> t;
        cout << dijkstra(s, t) + w[s] + w[t] << endl;
    }
    return 0;
}
/*

*/
