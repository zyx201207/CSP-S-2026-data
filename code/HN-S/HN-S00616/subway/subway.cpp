#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr int MAXN = 5e5 + 10;
constexpr int MAXM = 1e5 + 10;

int head[MAXN << 1], tot = 0, c, n, m, d, q, a[MAXN], cnt = 0;
ll dis[MAXN << 1], w[MAXN], ans[MAXM];
bool vis[MAXN << 1];
struct edge {int to, nxt; ll w;} edge[MAXN << 1];
struct Query {int u, v, id;} qwqwq[MAXM];

inline void add_edge(int u, int v, ll w) {
    edge[++tot] = {v, head[u], w}, head[u] = tot;
}

inline void dijkstra(int s) {
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0, vis[s] = true;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > qwq;
    qwq.push({0, s});
    
    while (!qwq.empty()) {
        auto [tmp, u] = qwq.top();
        qwq.pop(), vis[u] = false;

        for (register int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to; ll w = edge[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) vis[v] = true, qwq.push({dis[v], v});
            }
        }
    }
}


int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> m >> n >> d >> q;

        for (register int i = 1; i <= n; ++i) cin >> w[i];
        cnt = n + 1;

        while (m--) {
            int k;
            cin >> k;
            for (register int i = 1; i <= k; ++i) {
                ll t;
                cin >> a[i] >> t, add_edge(a[i], cnt, t), add_edge(cnt, a[i], t);
            }
            ++cnt;
        }

        for (register int i = 1; i <= q; ++i) cin >> qwqwq[i].u >> qwqwq[i].v, qwqwq[i].id = i;
        sort(qwqwq + 1, qwqwq + 1 + q, [](const Query &a, const Query &b) {return a.u < b.u;});
        
        for (register int i = 1; i <= q; ++i) {
            auto [u, v, id] = qwqwq[i];
            if (qwqwq[i - 1].u != u) dijkstra(u);
            ans[id] = dis[v] + w[u] + w[v];
        }

        for (register int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    
    return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/