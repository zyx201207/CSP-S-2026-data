#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e6 + 10;

int n, head[MAXN], tot = 0, dis[MAXN], cnt[MAXN];
ll x[MAXN], d;
bool vis[MAXN];
struct node {int to, nxt;} edge[MAXN << 2];

inline void add_edge(int u, int v) {edge[++tot] = {v, head[u]}, head[u] = tot;}

inline int dijkstra(int s) {
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qwq;
    dis[s] = 0, qwq.push({0, s}), cnt[s] = 1;

    while (!qwq.empty()) {
        auto [tmp, u] = qwq.top();
        qwq.pop();

        for (register int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] >= dis[u] + 1) {
                if (dis[v] == dis[u] + 1) ++cnt[v];
                else dis[v] = dis[u] + 1, cnt[v] = 1;
                qwq.push({dis[v], v});
            }
        }
    }

    int sum = 0;
    for (register int i = 1; i <= n; ++i) if (cnt[i] == 2) ++sum;
    return sum;
}

inline void solve1() {
    cin >> n >> d, tot = 0;
    for (register int i = 1; i <= n; ++i) head[i] = 0;
    ll ans = 0;
    for (register int i = 1; i <= n; ++i) cin >> x[i];
    for (register int i = 1; i <= n; ++i) for (register int j = i + 1; j <= n && x[j] - x[i] <= d; ++j) add_edge(i, j);
    for (register int i = 1; i <= n; ++i) ans += dijkstra(i);
    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--) solve1();
    return 0;
}

/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/