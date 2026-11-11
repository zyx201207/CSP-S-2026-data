#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
using ll = long long;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x += x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x/10);
    putchar('0'+(x%10));
}

int c, n, m, dd, q;
int w[M];
vector<pair<int, int>> g[M+N];
int dis[M+N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), dd = read(), q = read();
    for (int i = 1; i <= m; ++i) {
        w[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        int k = read();
        for (int j = 1; j <= k; ++j) {
            int a, t;
            a = read(), t = read();
            g[m+i].push_back({a, t});
            g[a].push_back({m+i, t});
        }
    }
    priority_queue<pair<ll, int>> qq;
    for (int i = 1; i <= q; ++i) {
        int x, y; x = read(), y = read();
        memset(dis, 0x3f, sizeof(dis));
        qq.push({0, x});
        while (!qq.empty()) {
            int d = qq.top().first, u = qq.top().second;
            qq.pop();
            d = -d;
            if (d > dis[u]) continue;
            for (auto p : g[u]) {
                int v = p.first, w = p.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    qq.push({-dis[v], v});
                }
            }
        }
        write(w[x] + dis[y] + w[y]);
        putchar('\n');
    }
    return 0;
}
