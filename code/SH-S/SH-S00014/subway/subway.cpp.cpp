#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const LL INF = 9e18;
const int N = 510, M = 500010;

bool st[M + N];
LL d[N][M + N];
priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
int c, n, m, dd, q, ww[M], t[N][N], a[N][N], h[2 * M], e[2 * M], ne[2 * M], w[2 * M], idx, k[N];

void Add(int x, int y, int z) {
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

void Dijkstra(int bg) {
    memset(d[bg - m], 0x3f, sizeof(d[bg - m]));
    memset(st, 0, sizeof(st));
    pq.push({ 0, bg });
    d[bg - m][bg] = 0;
    while (!pq.empty()) {
        auto [dist, pos] = pq.top(); pq.pop();
        if (st[pos]) continue;
        st[pos] = true;
        for (int i = h[pos]; i != -1; i = ne[i]) {
            int v = e[i];
            if (d[bg - m][v] > d[bg - m][pos] + w[i]) {
                d[bg - m][v] = d[bg - m][pos] + w[i];
                pq.push({ d[bg - m][v], v });
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &dd, &q);
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= m; ++i) scanf("%d", &ww[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; ++j) {
            scanf("%d%d", &a[i][j], &t[i][j]);
            Add(a[i][j], m + i, t[i][j]);
            Add(m + i, a[i][j], t[i][j]);
        }
    }
    
    for (int i = 1; i <= n; ++i) Dijkstra(m + i);

    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);

        LL ans = INF;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, 0LL + ww[x] + ww[y] + d[i][x] + d[i][y]);
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}
