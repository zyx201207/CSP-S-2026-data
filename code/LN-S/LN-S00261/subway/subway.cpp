#include <bits/stdc++.h>
#define sfr return cerr << "safe\n", 0;
#define sfv return cerr << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<ll, ll>;
using prt = tuple<int, int>;
using tpt = tuple<int, int, int>;
#define FILEIO "subway"
const int M = 5e5 + 10, N = 510;

int c, n, m, d, q, w[M];
vector<pr> E[N + M];
vector<pr> ycl[M]; // y id
priority_queue<pr, vector<pr>, greater<pr> > Q;
ll dis[M + N], ans[M];

auto dij(int st) -> void {
    fill(dis + 1, dis + m + n + 1, 1e18);
    Q.emplace(0, st), dis[st] = 0;
    while (!Q.empty()) {
        auto [val, u] = Q.top(); Q.pop();
        if (val != dis[u]) continue;
        for (auto &[v, w] : E[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.emplace(dis[v], v);
            }
        }
    }
}

auto sol1to11() {
    for (int k, i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, t; cin >> a >> t;
            E[i + m].emplace_back(a, t), E[a].emplace_back(i + m, t);
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x, y; cin >> x >> y;
        ycl[x].emplace_back(y, i);
    }
    for (int i = 1; i <= m; ++i) {
        if (ycl[i].empty()) continue;
        dij(i);
        for (auto &[y, id] : ycl[i]) {
            ans[id] = w[i] + w[y] + dis[y];
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n"; // [i == q];
}

ll f[N][N];
vector<int> G[M];

auto solB() {
    int T;
    // vector<int> tmp;
    memset(f, 0x3f, sizeof f);
    // sfv
    for (int k, i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, t; cin >> a >> t, T = t;
            G[a].emplace_back(i);
            // tmp.emplace_back(a);
            // E[i + m].emplace_back(a, t), E[a].emplace_back(i + m, t);
        }
        // continue;
        // for (int i = 0; i < k; ++i) {
        //     for (int j = i + 1; j < k; ++j) {
        //         auto u = tmp[i], v = tmp[j];
        //         f[u][v] = f[v][u] = 2 * T;
        //     }
        // }
        // tmp.clear();
    }
    // sfv
    // for (int i = 1; i <= n; ++i) f[i][i] = 0;
    for (int uu = 1; uu <= m; ++uu) {
        int k = G[uu].size();
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                auto u = G[uu][i], v = G[uu][j];
                f[u][v] = f[v][u] = 2 * T;
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int x, y, i = 1; i <= q; ++i) {
        cin >> x >> y;
        ll ans = 1e18;
        for (auto &v1 : G[x]) {
            for (auto &v2 : G[y]) {
                if (v1 == v2) ans = min(ans, 2ll * T + w[x] + w[y]);
                else ans = min(ans, 2ll * T + f[v1][v2] + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
}

vector<pr> GG[M];

auto sol() {
    // int T;
    // vector<int> tmp;
    memset(f, 0x3f, sizeof f);
    // sfv
    for (int k, i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, t; cin >> a >> t; // T = t;
            GG[a].emplace_back(i, t);
            // tmp.emplace_back(a);
            // E[i + m].emplace_back(a, t), E[a].emplace_back(i + m, t);
        }
        // continue;
        // for (int i = 0; i < k; ++i) {
        //     for (int j = i + 1; j < k; ++j) {
        //         auto u = tmp[i], v = tmp[j];
        //         f[u][v] = f[v][u] = 2 * T;
        //     }
        // }
        // tmp.clear();
    }
    // sfv
    // for (int i = 1; i <= n; ++i) f[i][i] = 0;
    for (int uu = 1; uu <= m; ++uu) {
        int k = GG[uu].size();
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                auto [u, w1] = GG[uu][i]; auto [v, w2] = GG[uu][j];
                f[u][v] = f[v][u] = w1 + w2;
                // cerr << w1 + w2 << " ";
            }
        }
    }
    // cerr << "\n";
    for (int i = 1; i <= n; ++i) f[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    // for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cerr << f[i][j] << " \n"[j == n];
    for (int x, y, i = 1; i <= q; ++i) {
        cin >> x >> y;
        ll ans = 1e18;
        for (auto &[v1, w1] : GG[x]) {
            for (auto &[v2, w2] : GG[y]) {
                if (v1 == v2) ans = min(ans, w1 + w2 + w[x] + w[y]);
                else ans = min(ans, w1 + w2 + f[v1][v2] + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
}

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
        // freopen(FILEIO ".err", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    // if (c <= 11) {
    //     sol1to11();
    // } else if (c <= 19) {
    //     solB();
    // }
    sol();
}