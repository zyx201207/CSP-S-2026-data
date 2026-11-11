#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N1 = 5e7, N2 = 5e5 + 5;
int n, m, d, q, w[N2], val[N1], dist[N1], c;
vector <pair<int, int> > g[N1], isaped[N2];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void dij(int s) {
    memset(dist, 0x7f, sizeof dist);
    priority_queue <pair<int, int>> pq;
    for (auto i : isaped[s]) {
        dist[i.first * N2 +  s] = i.second;
        pq.push({-i.second, i.first * N2 + s});
    }
    while (pq.size()) {
        auto j = pq.top(); pq.pop();
        int u = j.second;
        if (val[u]) {
            continue;
        }
        val[u] = 1;
        for (auto i : g[u]) {
            int v = i.first, w = i.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i ++) {
        w[i] = read();
    }

    for (int i = 1; i <= n; i ++) {
        int k, la;
        k = read();
        for (int j = 1; j <= 2 * k; i ++) {
            int a, t;
            a = read(), t = read();
            if (j != 1) {
                g[la + i * N2].push_back({a + i * N2, 0});
            }
            la = a;
            for(auto l : isaped[a]) {
                g[a + i * N2].push_back({l.first * N2 +  a, l.second + t});
                g[l.first * N2 + a].push_back({a + N2 * i, l.second + t});
            }
            isaped[a].push_back({i, t});
        }
    }

    for (int i = 1; i <= q; i ++) {
        int s, t;
        s = read(), t = read();
        dij(s);
        int ans = 1 << 31;
        for (int j = 1; j <= n; j ++) {
            ans = min(ans, dist[j * N2 + t]);
        }
        printf("%d\n", ans + w[s] + w[t]);
    }
}
