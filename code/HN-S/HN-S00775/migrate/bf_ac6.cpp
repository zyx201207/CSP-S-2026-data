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

constexpr int N = 2e6 + 5, inf = (sizeof(int) == 4 ? 1e9 : 1e18), mod = 998244353;

int n, d, a[N], to[N], c0[N], c1[N];

inline void solve() {
    n = rd(), d = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) to[i] = std::upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    rep(i, 1, n) c0[i] = c1[i] = 0;
    int ans = 0;
    per(i, n, 1) {
        int ct = 0, v = i;
        bool fg = 0;
        int up = -1;
        rep(j, to[i] + 1, n) {
            int nw = ct;
            while (to[to[v]] < j) {
                if (to[to[v]] == to[to[v] - 1]) {
                    ct++, nw++;
                    if (to[v] > 2 && to[to[v]] == to[to[v] - 2]) ct++, nw++;
                } else {
                    up = to[to[to[v] - 1]];
                    fg = 1;
                    // std::cerr << "fg: " << v << ' ' << j << ' ' << up << '\n';
                }
                if (v == to[v]) break;
                v = to[v];
            }
            if (j <= up) continue;
            if (to[to[v]] >= j && to[to[v] - 1] >= j) {
                nw++;
                if (to[v] > 2 && to[to[v] - 2] >= j) nw++;
            }
            if (to[to[v]] < j) break;
            if (ct > 1) break;
            if (nw > 1) continue;
            if (v != i && v >= up && (c0[v] || c1[v])) {
                if (ct) ans += c0[v], c1[i] += c0[v];
                else ans += c1[v], c0[i] += c0[v], c1[i] += c1[v];
                break;
            }
            if (nw == 1) {
                c1[i]++;
                ans++;
            } else {
                c0[i]++;
            }
        }
        // std::cerr << c0[i] << ' ' << c1[i] << '\n';
    }
    pt(ans);
    // std::cerr << '\n';
}
/*
0 1
6 3
0 1 2 3 4 7
*/
signed main() {
    freopen("migrate6.in", "r", stdin);
    freopen("migrate6.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int c = rd(), t = rd();
    while (t--) solve();

    return (0 ^ 0);
}