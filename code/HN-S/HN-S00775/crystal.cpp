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

int n, m, a[N], sm[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    n = rd(), m = rd();
    rep(i, 1, n) a[i] = rd();
    std::sort(a + 1, a + n + 1);
    rep(i, 1, n) sm[i] = sm[i - 1] + a[i];
    int ans = 0;
    rep(i, 1, n) {
        int L = 1, R = i, id = -1;
        while (L <= R) {
            int mid = L + R >> 1;
            if (a[i] * (i - mid + 1) <= sm[i] - sm[mid - 1] + m) id = mid, R = mid - 1;
            else L = mid + 1;
        }
        ans = std::max(ans, i - id + 1);
    }
    pt(ans);

    return (0 ^ 0);
}