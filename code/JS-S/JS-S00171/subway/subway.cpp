#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pll pair <int, int>
#define int long long
#define endl '\n'
using namespace std;
constexpr int N = 5e5 + 505, Q = 1e5 + 10;
inline int input() {
    char c = gc();
    int x = 0, f = 1;
    while (c < '0' or c > '9') {
        if (c == '-') f = -f;
        c = gc();
    }
    while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = gc();
    return x * f;
}
void print(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) print(x / 10);
    pc(x % 10 + '0');
}
int testc, n, m, d, T, w[N], dis[N], ans[Q];
struct ask{
    int u, v, idx;
} req[Q];
bool vis[N];
struct node {
    int v, w;
};
vector <node> g[N];
void Dijkstra(int s) {
    priority_queue <pll, vector<pll>, greater<pll> > q; 
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) q.pop();
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto e : g[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    return ;
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    testc = input(), n = input(), m = input(), d = input(), T = input();
    for (int i = 1; i <= m; i++) w[i] = input();
    int k;
    for (int i = 1; i <= n; i++) {
        k = input();
        int u, t, v = m + i;
        for (int j = 1; j <= k; j++) {
            u = input(), t = input();
            g[u].emplace_back(node{v, t});
            g[v].emplace_back(node{u, t});
        }
    }
    int u, v;
    for (int i = 1; i <= T; i++) {
        u = input(), v = input();
        if (u > v) swap(u, v);
        req[i] = ask{u, v, i};
    }
    sort(req + 1, req + 1 + T, [](ask x, ask y) {
        return x.u < y.u;
    });
    for (int i = 1; i <= T; i++) {
        int u = req[i].u, v = req[i].v, idx = req[i].idx;
        if (i == 1 or u != req[i - 1].u) {
            Dijkstra(u);
        }
        ans[idx] = dis[v] + w[u] + w[v];
    }
    for (int i = 1; i <= T; i++) {
        print(ans[i]);
        pc('\n');
    }
    return 0;
}
