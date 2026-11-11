#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 5e5 + 5;

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
    int n;
    ll m;
    ll a[N], s[N];
    void main() {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
        int ans = 1;
        for (int l = 1, r = 1; r <= n; ++r) {
            while (l < r && 1ll * (r - l + 1) * a[r] - (s[r] - s[l - 1]) > m) ++l;
            ans = max(ans, r - l + 1);
            // debug(l, r);
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Odette::main();
    return 0;
}