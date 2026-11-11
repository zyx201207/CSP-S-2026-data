#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int N = 5e5 + 1000;
ll c, n, m, d, q, w[N], dis[N];
bool vis[N];
vector<pll> g[N];
vector<pll> ask[N];
ll ans[N];
template <class T>
inline void read(T& x) {
    T s = 0, w = 1; char ch = getchar();
    while (!isdigit(ch))
        w = (ch == '-' ? -1 : 1), ch = getchar();
    while (isdigit(ch))
        s = s * 10 + ch - '0', ch = getchar();
    x = s * w;
    return;
}
inline void rd() { return; }
template <class T, class... Args>
inline void rd(T& x, Args&... args) {
    read(x), rd(args...);
    return;
}
inline void add(int u, int v, ll wt) {
    g[u].push_back({v, wt});
    g[v].push_back({u, wt});
    return;
}
inline void dijkstra(int s) {
    for (int i = 1; i <= m + n; i++) {
        dis[i] = 0x7f7f7f7f7f7f7f7f;
        vis[i] = false;
    }
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({dis[s] = 0, s});
    while (q.size()) {
        pll now = q.top(); q.pop();
        int u = now.second; ll ud = now.first;
        if (vis[u])
            continue;
        vis[u] = true;
        for (pll e : g[u]) {
            int v = e.first; ll wt = e.second;
            ll nd = dis[u] + wt;
            if (nd < dis[v])
                q.push({dis[v] = nd, v});
        }
    }
    return;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x7f, sizeof dis);
    memset(vis, false, sizeof vis);
    rd(c, n, m, d, q);
    for (int i = 1; i <= m; i++)
        rd(w[i]);
    for (int i = 1; i <= n; i++) {
        int k;
        rd(k);
        for (int j = 1; j <= k; j++) {
            int u; ll t;
            rd(u, t);
            add(m + i, u, t);
        }
    }
    for (int i = 1; i <= q; i++) {
        ll u, v;
        rd(u, v);
        ask[u].push_back({v, i});
    }
    for (int i = 1; i <= m; i++) {
        if (!ask[i].size())
            continue;
        dijkstra(i);
        // // debug
        // for (int j = 1; j <= m + n; j++)
        //     printf("%d -> %d : %lld\n", i, j, dis[j]);
        for (pll x : ask[i]) {
            ll id = x.second, v = x.first;
            ans[id] = dis[v] + w[i] + w[v];
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}