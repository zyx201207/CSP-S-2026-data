#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 5e6 + 5;
int a[N], dist[N], val[N], p[N], si[N];
vector <pair<int, int> > g[N];

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

inline void dij (int s) {
    memset(val, 0, sizeof val);
    memset(p, 0, sizeof p);
    memset(dist, 0x7f, sizeof dist);
    memset(si, 0, sizeof si);
    dist[s] = 0;
    priority_queue <pair<int, int>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto j = pq.top(); pq.pop();
        int u = j.second;
        if(val[u]) {
            continue;
        }
        val[u] = 1;
        for (auto i : g[u]) {
            int v = i.first, w = i.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                p[v] = 0;
                si[v] = si[u] + 1;
                pq.push({-dist[v], v});
            } else {
                if ((dist[v] == dist[u] + w) && (si[v] == si[u] + 1)) {
                    p[v] ++;
                }
            }
        }
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    c = read(), t = read();
    while (t --) {
        int n, d;
        n = read(), d = read();
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if (a[j] - a[i] <= d) {
                    g[i].push_back({j, a[j] - a[i]});
                }
            }
        }
        map <pair<int, int>, int> ma;
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            dij(i);
            for (int j = 1; j <= n; j ++) {
                if (i == j) continue;
                if (p[j] == 1 && ma[{min(i, j), max(i, j)}] != 1) {
                    ans ++, ma[{min(i, j), max(i, j)}] = 1;
                }
            }
        }
        printf("%d\n", ans);
    }
}
