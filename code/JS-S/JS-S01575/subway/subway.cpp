#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const ll oo = 1e18;
int c, n, m, d, q;
ll t[N], e[505][505], dis[505][505];
struct edge {
    int to; ll w;
};
vector<edge> li[N];
void dijkstra(int s) {
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i <= n; ++i) dis[s][i] = oo;
    dis[s][s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int v = 1; v <= n; ++v) {
            if (v != u && e[u][v]) {
                ll w = e[u][v];
                if (dis[s][v] > dis[s][u] + w) {
                    dis[s][v] = dis[s][u] + w;
                    pq.push({-dis[s][v], v});
                }
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a; ll w; cin >> a >> w;
            li[a].push_back({i, w});
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < li[i].size(); ++j) {
            for (int k = 0; k < li[i].size(); ++k) {
                if (j != k) {
                    e[li[i][j].to][li[i][k].to] = e[li[i][k].to][li[i][j].to] = li[i][j].w + li[i][k].w;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) dijkstra(i);
    while (q--) {
        int x, y; cin >> x >> y;
        ll ans = oo;
        for (auto l1 : li[x]) {
            for (auto l2 : li[y]) {
                ans = min(ans, t[x] + t[y] + l1.w + l2.w + dis[l1.to][l2.to]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// [80, 100]
