#include <bits/stdc++.h>
using namespace std;

namespace IO { char ch;
    void rd(int &x) {
        for (ch = getchar(), x = 0; !isdigit(ch); ch = getchar()) ;
        for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    }
} using IO::rd;

using ll = long long;

const int N = 5e5 + 5, M = 505;

int Cid, n, m, d, q, w[N];
vector<pair<int, int> > e[N];

ll dis[M][M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    rd(Cid), rd(n), rd(m), rd(d), rd(q);
    for (int i = 1; i <= m; i++) rd(w[i]);
    for (int i = 1; i <= n; i++) {
        int k; rd(k);
        while (k--) {
            int x, y;
            rd(x), rd(y);
            e[x].push_back({i, y});
        }
    }

    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto &e1 : e[i])
            for (auto &e2 : e[i]) {
                int x = e1.first, y = e2.first;
                dis[x][y] = min(dis[x][y], e1.second + e2.second * 1ll);
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while (q--) {
        int x, y; rd(x), rd(y);
        ll ans = LONG_LONG_MAX;
        for (auto &u : e[x])
            for (auto &v : e[y])
                ans = min(ans, dis[u.first][v.first] + u.second + v.second);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    // fprintf(stderr, "%.3f s\n", clock() * 1.0 / CLOCKS_PER_SEC);

    return 0;
}