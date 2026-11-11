#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 8, N = 5e2 + 8;
struct node {
    int u;
    long long d;
    bool operator < (const node &rhs) const {
        return d > rhs.d;
    }
};
int TEST, n, m, D, T, st, ed;
int spsolve[3][M];
long long w[M], dis[N + M];
bool vis[N + M];
vector <pair <int, long long> > g[N + M];
void dijkstra() {
    priority_queue <node> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push({st, 0ll});
    dis[st] = 0ll;
    while (!q.empty()) {
        node cur = q.top();
        q.pop();
        int u = cur.u, disu = cur.d;
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == ed) return;
        for (pair <int, int> pr : g[u]) {
            int v = pr.first, wv = pr.second;
            if (dis[v] > disu + wv) {
                dis[v] = disu + wv;
                q.push({v, dis[v]});
            }
        }
    }
    return;
}
void solve() {
    int tmp, a, x;
    memset(spsolve, 0x3f, sizeof spsolve);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        while (tmp--) scanf("%d%d", &a, &x), spsolve[i][a] = x;
    }
    if (n == 1) {
        while (T--) {
            scanf("%d%d", &st, &ed);
            printf("%lld\n", w[st] + w[ed] + spsolve[1][st] + spsolve[1][ed]);
        }
    } else if (n == 2) {
        long long minn = 1e18;
        for (int i = 1; i <= m; i++)
            minn = min(minn, 0ll + spsolve[1][i] + spsolve[2][i]);
        while (T--) {
            scanf("%d%d", &st, &ed);
            printf("%lld\n", min({w[st] + w[ed] + spsolve[1][st] + spsolve[1][ed], w[st] + w[ed] + spsolve[2][st] + spsolve[2][ed], w[st] + w[ed] + spsolve[1][st] + spsolve[2][ed] + minn, w[st] + w[ed] + spsolve[2][st]  + spsolve[1][ed]}));
        }
    }
    return;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &TEST, &n, &m, &D, &T);
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    if (TEST >= 20 && TEST <= 21) {
        solve();
        return 0;
    }
    int tmp, a, x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        while (tmp--) {
            scanf("%d%d", &a, &x);
            g[m + i].push_back({a, x});
            g[a].push_back({m + i, x});
        }
    }
    while (T--) {
        scanf("%d%d", &st, &ed);
        dijkstra();
        printf("%lld\n", w[st] + w[ed] + dis[ed]);
    }
    return 0;
}
