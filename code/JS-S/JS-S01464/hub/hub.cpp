#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 1e5 + 5;

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
    int n, k, ans;
    int vis;
    vector<int> g[N];
    int dis[N];
    void dfs(const int u, const int fa, const int st) {
        if (!(st & (1 << u))) return;
        vis |= 1 << u;
        for (const int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u, st);
        }
    }
    void check(const int st) {
        vis = 0;
        int ct = 0;
        for (int i = 1; i <= n; ++i) if ((st & (1 << i)) && !(vis & (1 << i))) dfs(i, 0, st), ++ct;
        if (st != vis || ct != 2) return;
        memset(dis, 0x3f, sizeof dis);
        queue<int> que;
        for (int i = 1; i <= n; ++i) if (st & (1 << i)) que.emplace(i), dis[i] = 0;
        while (!que.empty()) {
            const int u = que.front(); que.pop();
            for (const int v : g[u]) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    que.emplace(v);
                }
            }
        }
        int c = 0;
        for (int i = 1; i <= n; ++i) c = max(c, dis[i]);
        ans = min(ans, c);
    }
    void main() {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1, u, v; i < n; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
        ans = 0x3f3f3f3f;
        for (int i = 1; i < 1 << n; ++i) {
            if (__builtin_popcount(i) == k) check(i << 1);
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t >> t; for (int _ = 1; _ <= t; ++_) Odette::main();
    return 0;
}