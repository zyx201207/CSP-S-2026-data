#include <bits/stdc++.h>
#define Mem(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define eb emplace_back
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
using i128 = __int128;
using namespace std;
constexpr int N = 3e6 + 15, mod = 998244353;
constexpr i64 inf = 1e18;

int n, m, d, q;
int w[N];
int head[N], to[N << 1], val[N << 1], nxt[N << 1], idx;
i64 dis[N];
bool vis[N];
struct node {
    int u;
    i64 w;
    inline bool operator < (const node &x) const {
        return x.w < w;
    }
};

inline int get_id(int x, int op) {
    if (op == 0) return x;//地铁口
    else if (op == 1) return x + m;//站厅
    else return x + 2 * m;//站台
}

inline void add (int u, int v, int w) {
    to[idx] = v;
    val[idx] = w;
    nxt[idx] = head[u];
    head[u] = idx ++;
}

inline void Dijkstra(int s) {
    for (int i = 0; i <= n + 2 * m; ++ i) dis[i] = inf, vis[i] = 0;
    priority_queue<node> q;
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i], w = val[i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

#define filename "subway"

int main () {
#ifdef filename
    freopen (filename ".in", "r", stdin);
    freopen (filename ".out", "w", stdout);
#endif
    Mem (head, -1);
    int _;
    scanf ("%d%d%d%d%d", &_, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++ i) {
        scanf ("%d", &w[i]);
        int u = get_id(i, 0), v = get_id(i, 1);
        add (u, v, w[i]);
        add (v, u, w[i]);
    }
    for (int i = 1; i <= n; ++ i) {
        int k;
        scanf ("%d", &k);
        for (int j = 1; j <= k; ++ j) {
            int u, t;
            scanf ("%d%d", &u, &t);
            u = get_id(u, 1);
            int v = get_id(i, 2);
            add (u, v, t);
            add (v, u, t);
        }
    }
    while (q --) {
        int s, t;
        scanf ("%d%d", &s, &t);
        Dijkstra(s);
        printf ("%lld\n", dis[t]);
    }
    return 0;
}
/*
离线求问：最短路树怎么建

……
所以，重要的不是经历，是选择。
很多很多，只有您才能做出的选择。

我们之前聊过，有关背负责任之人的话题吧。
那时我还不懂，但现在，我理解了。
身为大人所需承担的责任与义务，以及在其延长线上的，您作出的选择。
甚至还有，您作出那份选择时的那份心情。

……

所以，请一定要……
把我们的缘分，和我们所有珍贵的回忆，珍藏起来。
是的。因为珍贵的东西绝不会消失，
就像“奇迹”一样。

所以，回去吧，老师。
回到所有属于我们的“爱”所停留的地方。

而且，只有这才是，
通过无法理解之物，理解我们自身的唯一方法。

……

一直以来谢谢你了，
老师。
*/