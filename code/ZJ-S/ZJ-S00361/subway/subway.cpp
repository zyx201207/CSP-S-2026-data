#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    using ll = long long;
    using pii = pair<int, int>;
    const int N = 505;
    const int M = 2e4 + 5;
    const int D = 25;
    int c, n, m, d, q;
    int w[M];
    int k[N];
    bitset<M> vis;
    ll dis[N][M];
    vector<int> g[M];
    vector<pii> line[N];
    inline void spfa(int s) {
        // s 起点
        memset(dis, 0x3f, sizeof(dis));
        vis.reset();
        queue<pii> q;
        for (int idx : g[s]) {
            for (auto [a, t] : line[idx]) {
                if (a == s) {
                    dis[idx][s] = t;
                    q.push({s, idx});
                    break;
                }
            }
        }
        while (q.size()) {
            auto [u, id] = q.front(); q.pop();
            for (int idx : g[u]) {
                int len = 0;
                for (auto [a, t] : line[idx]) {
                    if (dis[idx][a] > dis[id][u] + t + len) {
                        dis[idx][a] = dis[id][u] + t + len;
                        q.push({a, idx});
                    }
                }
            }
        }
    }
    inline void solve() {
        cin >> c >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
            for (int j = 1; j <= k[i]; j++) {
                int a, t; cin >> a >> t;
                line[i].push_back({a, t});
                g[a].push_back(i);
            }
        }
        for (int i = 1; i <= q; i++) {
            int x, y; cin >> x >> y;
            int ans = w[x] + w[y];
            spfa(x);
            ll res = 1e18;
            for (int i = 1; i <= n; i++) {
                res = min(res, dis[i][y]);
            }
            cout << ans + res << '\n';
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

15:21 开 T2，我真的能场切吗？我问我自己。
15:37 什么（）题面，我已急哭。
15:49 似乎有了一个做法。话说去年考 MST，今年考最短路，CCF 是不是对于在 T2 放图论有什么执念。时间复杂度感觉有点对了。查询似乎是 O(\log n) 的，暂时没有想到反例。
造一些虚拟点，作为转移的点，边权设为 0。
15:57 好像不是很对，先去打 T3,T4 暴力了。
17:26 再一次开始看 T2 我能场切吗？我问我自己。如果拿不到高分就完蛋了。
*/