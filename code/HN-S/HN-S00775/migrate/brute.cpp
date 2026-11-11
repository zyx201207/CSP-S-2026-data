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

int n, d, a[N], to[N];

inline int chk(int u, int v) {
    int nw = u;
    vi tp;
    while (nw < v) {
        if (to[nw] == nw) break;
        tp.eb(nw);
        nw = to[nw];
    }
    if (nw < v) return -1;//不可达
    int ct = 0;
    tp.pop_back();
    int id = -1;
    per(j, tp.size() - 1, 0) {
        int i = tp[j];
        if (i != tp.back()) {
            if (to[to[i]] == to[to[i] - 1]) {
                ct++;
                id = to[i] - 1;
                if (to[i] > 2 && to[to[i]] == to[to[i] - 2]) return 0;
            } else if (id != -1 && to[to[i] - 1] >= id) {
                return 0;
            }
        } else {
            if (to[to[i]] >= v && to[to[i] - 1] >= v) {
                ct++;
                id = to[i] - 1;
                if (to[i] > 2 && to[to[i] - 2] >= v) return 0;
            } 
        }
    } 
    // for (auto i : tp) {
    //     if (i != tp.back()) {
    //         if (to[to[i]] == to[to[i] - 1]) {
    //             ct++;
    //             if (to[i] > 2 && to[to[i]] == to[to[i] - 2]) return 0;
    //         }
    //     } else {
    //         if (to[to[i]] >= v && to[to[i] - 1] >= v) {
    //             ct++;
    //             if (to[i] > 2 && to[to[i] - 2] >= v) return 0;
    //         }
    //     }
    // }
    return (ct == 1);
}

inline void solve() {
    n = rd(), d = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) to[i] = std::upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n) {
        int res = chk(i, j);
        if (res == -1) break;
        if (res) std::cerr << i << ' ' << j << '\n', ans++;
    }
    pt(ans);
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

ans:5
*/

signed main() {
    freopen("migrate3.in", "r", stdin);
    freopen("migrate3.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int c = rd(), t = rd();
    while (t--) solve();

    return (0 ^ 0);
}