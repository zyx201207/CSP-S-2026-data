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

int n, d, a[N], to[N], c0[N], c1[N], c, t;

inline void solve() {
    n = rd(), d = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) to[i] = std::upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    rep(i, 1, n) c0[i] = c1[i] = 0;
    if (c >= 11 && c <= 12) {
        int d = to[1] - 1, ans = 0;
        if (!d) return pt(0);
        rep(i, 1, n) {
            int v = 2 * d + i - 1;
            if (v <= n && v >= 1 && v - i >= 3) ans++;
        }
        pt(ans);
        // rep(i, 2, n) assert(to[i] == n || to[i] - i == d);
        return ;
    }
    int ans = 0;
    per(i, n, 1) {
        if (to[i] == i) continue;
        int ct = 0, v = i;
        int R = to[to[v] - 1], L = to[to[v] - 2] + 1;
        if (to[v] <= 2) L = to[i] + 1;
        // if (i == n) std::cerr << L << ' ' << R << '\n';
        L = std::max(L, to[i] + 1);
        int l = to[i] + 1, r = std::max(to[to[i]], to[to[to[i]] - 2]);
        // if (i == 7) std::cerr << "AS: " << l << ' ' << r << ' ' << L << ' ' << R << '\n';
        if (L <= R) {
            // std::cerr << "add1: " << ans << ' ' << R - L + 1 << '\n';
            ans += (R - L + 1), c1[i] = R - L + 1, c0[i] = ((r - l + 1) - (R - L + 1));
        } else {
            c1[i] = 0, c0[i] = r - l + 1;
        }
        int up = -1;
        rep(j, r + 1, n) {
            int nw = ct;
            while (to[to[v]] < j) {
                if (to[to[v]] == to[to[v] - 1]) {
                    ct++, nw++;
                    if (to[v] > 2 && to[to[v]] == to[to[v] - 2]) ct++, nw++;
                } else {
                    up = to[to[to[v] - 1]];
                }
                if (v == to[v]) break;
                v = to[v];
            }
            if (c <= 10 && j <= up) continue;
            if (to[to[v]] >= j && to[to[v] - 1] >= j) {
                nw++;
                if (to[v] > 2 && to[to[v] - 2] >= j) nw++;
            }
            if (to[to[v]] < j) break;
            if (ct > 1) break;
            if (nw > 1) continue;
            if (v != i && (c0[v] || c1[v])) {
                if (c > 10 || v >= up) {
                    if (ct) ans += c0[v], c1[i] += c0[v];
                    else ans += c1[v], c0[i] += c0[v], c1[i] += c1[v];
                    break;
                }
            }
            if (nw == 1) {
                c1[i]++;
                ans++;
            // std::cerr << "add3: " << ans << ' ' << R - L + 1 << '\n';
            } else {
                c0[i]++;
            }
        }
        // std::cerr << c0[i] << ' ' << c1[i] << ' '<< to[to[i]] + 1 << '\n';
    }
    pt(ans);
    // std::cerr << '\n';
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
ans:5

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

12 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936

*/
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    c = rd(), t = rd();
    while (t--) solve();

    return (0 ^ 0);
}