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

constexpr int N = 5e5 + 5, inf = (sizeof(int) == 4 ? 1e9 : 1e18), mod = 998244353;

int dis[505][505];
vp e[N], s[N];
int c, n, m, d, q;
int w[N];
int k[N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    rep(i, 1, m) w[i] = rd();
    rep(i, 1, n) {
        k[i] = rd();
        rep(j, 1, k[i]) {
            int v = rd(), t = rd();
            s[i].eb(v, t), e[v].eb(i, t);
        }
    }
    rep(i, 1, n) rep(j, 1, n) dis[i][j] = inf;
    rep(i, 1, m) {
        // assert(e[i].size() <= d);
        for (auto x1 : e[i]) {
            for (auto x2 : e[i]) {
                int i1 = x1.first, w1 = x1.second;
                int i2 = x2.first, w2 = x2.second;
                dis[i1][i2] = std::min(dis[i1][i2], w1 + w2);
                dis[i2][i1] = std::min(dis[i2][i1], w1 + w2);
            }
        }
    }
    rep(i, 1, n) dis[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    for (int i = 1, x, y; i <= q; i++) {
        x = rd(), y = rd();
        int ans = inf;
        for (auto u : e[x]) {
            for (auto v : e[y]) {
                ans = std::min(ans, u.second + v.second + dis[u.first][v.first]);
            }
        }
        pt(ans + w[x] + w[y]);
    }

    return (0 ^ 0);
}