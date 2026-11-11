#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = 2 * N, INF = 0x3f3f3f3f;

bool st[N];
int n, k, h[N], e[M], ne[M], idx, col[N], d[N];

void Add(int x, int y) {
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

void DFS(int u, int color) {
    col[u] = color;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (st[v] && !col[v]) {
            DFS(v, color);
        }
    }
}

void DFS2(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (d[v] > d[u] + 1) {
            d[v] = d[u] + 1;
            DFS2(v);
        }
    }
}

void Solve() {
    scanf("%d%d", &n, &k);
    memset(h, -1, sizeof(h));
    for (int i = 1, x, y; i <= n - 1; ++i) {
        scanf("%d%d", &x, &y);
        Add(x, y), Add(y, x);
    }

    int ans = INF;
    for (int mask = 0; mask < 1 << n; ++mask) {
        memset(col, 0, (n + 1) * sizeof(int));
        memset(d, 0x3f, (n + 1) * sizeof(int));
        memset(st, 0, (n + 1) * sizeof(bool));
        if (__builtin_popcount(mask) != k) continue;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                st[i + 1] = true;
            }
        }
        int col_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (st[i + 1] && !col[i + 1]) {
                DFS(i + 1, ++col_idx);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (st[i + 1]) {
                d[i + 1] = 0;
                DFS2(i + 1);
            }
        }
        if (col_idx <= 2) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (!(mask >> i & 1)) cnt = max(cnt, d[i + 1]);
            }
            ans = min(ans, cnt);
        }
    }

    printf("%d\n", ans);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) Solve();

    return 0;
}
// rp++
// jbw tql ORZ 
