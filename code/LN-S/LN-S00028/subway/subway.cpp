// Play CYAN METRO!!!

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr int N = 500, M = 5e5, D = 20;

int c, n, m, _, q;

i64 e[N][N], d[N][N], w[M];

i64 cn[M][D][2], deg[M];

void Floyd() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = e[i][j];
    for (int aux = 0; aux < n; aux++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][aux] + d[aux][j]);
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> _ >> q;
    for (int i = 0; i < m; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        int dg; cin >> dg;
        for (int k = 0; k < dg; k++) {
            int x, t; cin >> x >> t, x--;
            int id = (deg[x]++);
            cn[x][id][0] = i, cn[x][id][1] = t;
        }
    }

    memset(d, 0x3f, sizeof(d)); memset(e, 0x3f, sizeof(e));
    for (int i = 0; i < n; i++) d[i][i] = e[i][i] = 0;
    for (int i = 0; i < m; i++) {
        for (int i0 = 0; i0 < deg[i]; i0++)
            for (int i1 = 0; i1 < deg[i]; i1++) {
                i64 u = cn[i][i0][0], v = cn[i][i1][0], w0 = cn[i][i0][1], w1 = cn[i][i1][1];
                e[u][v] = min(e[u][v], w0 + w1);
            }
    }

    Floyd();

    for (int x, y; q; q--) {
        cin >> x >> y, x--, y--;
        i64 bs = w[x] + w[y], ans = 1e18;
        for (int i0 = 0; i0 < deg[x]; i0++)
            for (int i1 = 0; i1 < deg[y]; i1++) {
                i64 u = cn[x][i0][0], v = cn[y][i1][0], w0 = cn[x][i0][1], w1 = cn[y][i1][1];
                ans = min(ans, d[u][v] + w0 + w1);
            }
        cout << bs + ans << endl;
    }
}