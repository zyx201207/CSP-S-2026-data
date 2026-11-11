// Za you T le ?????????????
#include <bits/stdc++.h>
using namespace std;
const int N = 510, K = 5e5 + 10;
const long long inf = 1e17;
struct way { int v, w; };
struct subway {
    int u, s; long long w;
    friend bool operator < (subway A, subway B) { return A.w > B.w; }
};
int c, n, m, d, q;
int w[K];
long long dis[N][K + N];
vector <way> G[N + K];
void connect (int u, int v, int w) { G[u].push_back ((way) {v, w}); }
void dij () {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m + n; j++) dis[i][j] = inf;
    priority_queue < subway > q;
    for (int i = 1; i <= n; i++) {
        dis[i][i + m] = 0;
        q.push ({i + m, i, 0});
    }
    while (!q.empty ()) {
        subway now = q.top (); q.pop ();
        int u = now.u, s = now.s;
        if (now.w != dis[s][u]) continue;
        for (auto it : G[u]) {
            int v = it.v, w = it.w;
            if (dis[s][v] > dis[s][u] + w) {
                dis[s][v] = dis[s][u] + w;
                q.push ({v, s, dis[s][v]});
            }
        }
    }
}
int main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int len; cin >> len;
        connect (0, m + i, 0);
        for (int j = 1; j <= len; j++) {
            int v, t; cin >> v >> t;
            connect (m + i, v, t), connect (v, m + i, t);
        }
    }
    dij ();
    while (q--) {
        int u, v; cin >> u >> v;
        long long res = inf;
        for (int i = 1; i <= n; i++) res = min (res, dis[i][u] + dis[i][v] + w[u] + w[v]);
        cout << res << "\n";
    }
    return 0;
}
