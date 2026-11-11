#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;
inline char gc() {
    if (p1 == p2) {
        p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin);
        if (p1 == p2) return EOF;
    }
    return *p1++;
}
template<typename T>
inline void read(T &t) {
    T f = 1, x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    t = f * x;
}

#define int long long
typedef pair<int, int> PII;
const int MAXN = 505, MAXM = 5e5 + 5;
int c, n, m, d, q, a[MAXM];
vector<PII> g[MAXM];
int dis[MAXN][MAXM];
bool vis[MAXM];
queue<PII> que;

inline void SPFA(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dis[s - m], 0x3f, sizeof(dis[s - m]));
    while (!que.empty()) que.pop();
    que.push({s, 0});
    dis[s - m][s] = 0;
    vis[s] = 1;
    while (!que.empty()) {
        PII tmp1 = que.front();
        int u = tmp1.first, di = tmp1.second;
        que.pop();
        vis[u] = 0;
        for (PII tmp2 : g[u]) {
            int v = tmp2.first, w = tmp2.second;
            if (dis[s - m][v] > dis[s - m][u] + w) {
                dis[s - m][v] = dis[s - m][u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    que.push({v, dis[s - m][v]});
                }
            }
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c); read(n); read(m); read(d); read(q);
    for (int i = 1; i <= m; i++) {
        read(a[i]);
    }
    for (int i = m + 1; i <= m + n; i++) {
        int k; read(k);
        for (int j = 1; j <= k; j++) {
            int x, t;
            read(x); read(t);
            g[x].push_back({i, t});
            g[i].push_back({x, t});
        }
    }
    for (int i = m + 1; i <= m + n; i++) {
        SPFA(i);
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        read(x), read(y);
        int ans = 0x3f3f3f3f3f3f3f3f;
        for (int j = m + 1; j <= m + n; j++) {
            ans = min(ans, dis[j - m][x] + dis[j - m][y]);
        }
        printf("%lld\n", ans + a[x] + a[y]);
    }
    return 0;
}
