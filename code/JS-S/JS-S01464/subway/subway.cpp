#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 500 + 5, M = 5e5 + 5, Q = 1e5 + 5, D = 21;

namespace Odette {
    inline namespace Vodyanitsa {
#ifdef Odette_Vodyanitsa
        inline void debug() { cerr << '\n'; }
        template<class T, class... R> void debug(T x, R... r) { cerr << x << '\t'; debug(r...); }
#define seq(i, s, t, a) do { for (int i = (s); i <= (t); ++i) cerr << (a) << '\t'; cerr << '\n'; } while (0)
#else
        template<class... R> void debug(R... r) {}
#define seq(i, s, t, a) do ; while (0)
#endif
    }
    int n, m, d, q;
    ll w[M];

    vector<pair<int, ll>> sw[M];

    struct edge { int v; ll w; int nxt; } g[D * M * 2];
    int head[N], gcnt;
    void add(const int u, const int v, const ll w) { g[++gcnt] = {v, w, head[u]}, head[u] = gcnt; }

    struct Qs { int u, v, i; } qs[Q];
    ll ans[Q];

    struct node {
        int u; ll w;
        explicit node(const int u = 0, const ll w = 0) : u(u), w(w) {}
        bool operator<(const node &o) const { return w < o.w; }
        bool operator>(const node &o) const { return w > o.w; }
    };
    priority_queue<node, vector<node>, greater<>> pq;
    ll dis[N][N];
    void dijkstra(const int s) {
        memset(dis[s], 0x3f, sizeof dis[s]);
        pq.emplace(s, 0);
        dis[s][s] = 0;
        while (!pq.empty()) {
            const int u = pq.top().u;
            const ll w = pq.top().w;
            pq.pop();
            if (w > dis[s][u]) continue;
            for (int q = head[u]; q; q = g[q].nxt) {
                const int v = g[q].v;
                const ll nw = g[q].w;
                if (dis[s][v] > dis[s][u] + nw) {
                    dis[s][v] = dis[s][u] + nw;
                    pq.emplace(v, dis[s][v]);
                }
            }
        }
    }

    void main() {
        cin >> n >> n >> m >> d >> q;
        for (int i = 1; i <= m; ++i) cin >> w[i];
        for (int i = 1; i <= n; ++i) {
            int k; cin >> k;
            for (int j = 1; j <= k; ++j) {
                int a; ll t; cin >> a >> t;
                sw[a].emplace_back(i, t);
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (ull j = 0; j < sw[i].size(); ++j) {
                for (ull k = 0; k < sw[i].size(); ++k) {
                    if (j == k) continue;
                    add(sw[i][j].first, sw[i][k].first, sw[i][j].second + sw[i][k].second);
                    add(sw[i][k].first, sw[i][j].first, sw[i][j].second + sw[i][k].second);
                }
            }
        }
        for (int i = 1; i <= q; ++i) {
            cin >> qs[i].u >> qs[i].v;
            qs[i].i = i;
        }
        for (int i = 1; i <= n; ++i) dijkstra(i);
        sort(qs + 1, qs + q + 1, [&](const Qs &a, const Qs &b) { return a.u < b.u; });
        for (int i = 1; i <= q; ++i) {
            ll c = 0x3f3f3f3f3f3f3f3f;
            const int u = qs[i].u, v = qs[i].v;
            for (ull j = 0; j < sw[u].size(); ++j) {
                for (ull k = 0; k < sw[v].size(); ++k) {
                    c = min(c, dis[sw[u][j].first][sw[v][k].first] + sw[u][j].second + sw[v][k].second);
                }
            }
            ans[qs[i].i] = c + w[qs[i].u] + w[qs[i].v];
        }
        for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Odette::main();
    return 0;
}


























/*
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 500 + 5, M = 5e5 + 5, Q = 1e5 + 5;

namespace Odette {
    inline namespace Vodyanitsa {
#ifdef Odette_Vodyanitsa
        inline void debug() { cerr << '\n'; }
        template<class T, class... R> void debug(T x, R... r) { cerr << x << '\t'; debug(r...); }
#define seq(i, s, t, a) do { for (int i = (s); i <= (t); ++i) cerr << (a) << '\t'; cerr << '\n'; } while (0)
#else
        template<class... R> void debug(R... r) {}
#define seq(i, s, t, a) do ; while (0)
#endif
    }
    int n, m, d, q;
    ll w[M];

    struct edge { int v; ll w; int nxt; } g[M * 6 * 2];
    int head[M * 2], gcnt, ncnt;
    void add(const int u, const int v, const ll w) { g[++gcnt] = {v, w, head[u]}, head[u] = gcnt; }

    struct Qs { int u, v, i; } qs[Q];
    ll ans[Q];

    struct node {
        int u; ll w;
        explicit node(const int u = 0, const ll w = 0) : u(u), w(w) {}
        bool operator<(const node &o) const { return w < o.w; }
        bool operator>(const node &o) const { return w > o.w; }
    };
    priority_queue<node, vector<node>, greater<>> pq;
    ll dis[M];
    void dijkstra(const int s) {
        memset(dis, 0x3f, sizeof dis);
        pq.emplace(s, 0);
        dis[s] = 0;
        while (!pq.empty()) {
            const int u = pq.top().u;
            const ll w = pq.top().w;
            pq.pop();
            if (w > dis[u]) continue;
            for (int q = head[u]; q; q = g[q].nxt) {
                const int v = g[q].v;
                const ll nw = g[q].w;
                if (dis[v] > dis[u] + nw) {
                    dis[v] = dis[u] + nw;
                    pq.emplace(v, dis[v]);
                }
            }
        }
    }

    void main() {
        cin >> n >> n >> m >> d >> q;
        for (int i = 1; i <= m; ++i) cin >> w[i];
        ncnt = m;
        for (int i = 1; i <= n; ++i) {
            int k; cin >> k;
            for (int j = 1, lst = 0; j <= k; ++j) {
                int a; ll t; cin >> a >> t;
                ++ncnt;
                if (lst) add(lst, ncnt, 0), add(ncnt, lst, 0);
                add(a, ncnt, t), add(ncnt, a, t);
                lst = ncnt;
            }
        }
        for (int i = 1; i <= q; ++i) {
            cin >> qs[i].u >> qs[i].v;
            qs[i].i = i;
        }
        sort(qs + 1, qs + q + 1, [&](const Qs &a, const Qs &b) { return a.u < b.u; });
        for (int i = 1, cur = 0; i <= q; ++i) {
            if (cur != qs[i].u) dijkstra(qs[i].u), cur = qs[i].u;
            ans[qs[i].i] = dis[qs[i].v] + w[qs[i].u] + w[qs[i].v];
        }
        for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Odette::main();
    return 0;
}
*/