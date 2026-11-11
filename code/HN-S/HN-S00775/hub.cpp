#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;

#define int i64

namespace io{
    inline int rd() {
        int f = 1, s = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            s = (s << 1) + (s << 3) + (ch - '0');
            ch = getchar();
        }
        return s * f;
    }
    static char cc[91];
    template <class T>
    inline void pt(T x, char c = '\n') {
        int stk = 0;
        if (x < 0) putchar('-'), x *= -1;
        if (x == 0) {
            putchar('0'), putchar(c);
            return ;
        }
        while (x) cc[++stk] = x % 10 + '0', x /= 10;
        for (int i = stk; i; i--) putchar(cc[i]);
        putchar(c);
    }
    inline void ptstr(std::string s) {
        for (auto v : s) putchar(v);
    }
};
using io::rd;
using io::pt;
using io::ptstr;

using vi = std::vector<int> ;
using vI = std::vector<i64> ;
using str = std::string;
using vp = std::vector<std::pair<int, int>> ;
using pii = std::pair<int, int> ;

#define pb push_back
#define eb emplace_back
#define all(s) s.begin(), s.end()
#define rep(i, l, r) for (int i = (l), _ = (r); i <= _; i++)
#define per(i, l, r) for (int i = (l), _ = (r); i >= _; i--)

constexpr int N = 1e3 + 5, inf = (sizeof(int) == 4 ? 1e9 : 1e18), mod = 998244353;

int n, k;
vi e[N];
int vis[N];
int is[N];
inline void dfs1(int u, int p = 0) {
    is[u] = 1;
    for (auto v : e[u]) {
        if (p != v && vis[v] && !is[v]) dfs1(v, u);
    }
}
int dis[N][N];
int rt;
inline void dfs2(int u, int p = 0) {
    dis[rt][u] = dis[rt][p] + 1;
    for (auto v : e[u]) {
        if (v ^ p) dfs2(v, u);
    }
}
int ans = inf;
inline void dfs(int u) {
    if (u > n) {
        int ct = 0;
        rep(i, 1, n) ct += vis[i];
        if (ct != k) return ;
        rep(i, 1, n) is[i] = 0;
        ct = 0;
        rep(i, 1, n) if (vis[i] && !is[i]) ct++, dfs1(i);
        if (ct > 2) return ;
        int nw = 0;
        rep(i, 1, n) {
            int re = inf;
            rep(j, 1, n) if (vis[j]) re = std::min(re, dis[i][j]);
            nw = std::max(nw, re);
        }
        ans = std::min(ans, nw);
        return ;
    }
    rep(i, 0, 1) vis[u] = i, dfs(u + 1);
}

inline void solve() {
    ans = inf;
    n = rd(), k = rd();
    rep(i, 1, n) e[i].clear(), vis[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        u = rd(), v = rd();
        e[u].eb(v), e[v].eb(u);
    }
    rep(i, 1, n) {
        rt = i, dis[i][0] = -1;
        dfs2(i);
    }
    dfs(1);
    pt(ans);
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int c = rd(), t = rd();
    while (t--) solve();

    return (0 ^ 0);
}