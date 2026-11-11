// tuxiaolai
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace TIO {
    const int siz = 1 << 20;
    char buf[siz], *p1 = buf, *p2 = p1, c;
    int f;
    void gc() { c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, siz, stdin), p1 == p2)) ? EOF : *p1++; }
    struct IN {
        template<typename T>
        IN &operator>>(T &x) {
            x = 0, f = 1, gc();
            while ('0' > c || c > '9') {
                if (c == '-') f = -1;
                gc();
            }
            while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + c - '0', gc();
            x *= f;
            return *this;
        }
    } tin;
}
using TIO::tin;

const int M = 5e5 + 10, N = 520, D = 35;

int c, n, m, d, q, w[M];
struct Edge {
    int v;
    ll w;
};
vector<Edge> adj[M];
ll dis[N][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // const double start = -clock();

    memset(dis, 0x3f, sizeof dis);

    tin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        tin >> w[i];
    }
    ll t;
    for (int i = 1, k, j, a; i <= n; i++) {
        dis[i][i] = 0;
        tin >> k;
        for (j = 1; j <= k; j++) {
            tin >> a >> t;
            adj[a].push_back({i, t});
        }
    }

    for (int i = 1; i <= m; i++) {
        for (const Edge &u: adj[i]) {
            for (const Edge &v: adj[i]) {
                dis[u.v][v.v] = min(dis[u.v][v.v], u.w + v.w);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // cout << "part1 time = " << (clock() + start) / 1000 << '\n';

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            const ll r = dis[i][k];
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], r + dis[k][j]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    
    // cout << "part2 time = " << (clock() + start) / 1000 << '\n';

    // ll ans = 0;

    for (int i = 1, u, v; i <= q; i++) {
        tin >> u >> v;
        ll res = 1e18;
        for (const Edge &e1: adj[u]) {
            for (const Edge &e2: adj[v]) {
                res = min(res, e1.w + e2.w + dis[e1.v][e2.v]);
            }
        }
        res += w[u] + w[v];
        // ans += res;
        cout << res << '\n';
    }
    // cout << ans << '\n';

    // cout << "tot time = " << (clock() + start) / 1000 << '\n';
    
    return 0;
} // g++ subway.cpp -o subway -O2 -std=c++14 -Wall -Wextra -Wshadow -Wconversion -Wl,--stack=512000000