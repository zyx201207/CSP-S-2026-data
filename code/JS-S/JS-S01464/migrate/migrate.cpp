#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 300 + 5;

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
    ll d;
    ll x[N];
    int p[N];
    int f[N][N][N];
    void main() {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int l = 1, r = 1; r <= n; ++r) {
            while (x[r] - x[l] > d) ++l;
            p[r] = l;
        }
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 0; k < n; ++k) f[i][j][k] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = p[i]; j < i; ++j) {
                ++f[j][i][1];
            }
        }
        for (int v = 1; v <= n; ++v) {
            for (int w = p[v]; w < v; ++w) {
                for (int l = 2; l <= n - 1; ++l) {
                    for (int u = 1; u < v; ++u) {
                        f[u][v][l] += f[u][w][l - 1];
                    }
                }
            }
        }
        int ans = 0;
        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                for (int l = 1; l < n; ++l) {
                    if (f[u][v][l]) {
                        if (f[u][v][l] == 2) ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t >> t; for (int _ = 1; _ <= t; ++_) Odette::main();
    return 0;
}

























/*
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

constexpr ll N = 300 + 5;

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
    ll d;
    ll x[N];
    int p[N];
    int f[N][N][N];
    void main() {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 0; k < n; ++k) f[i][j][k] = 0;
        for (int l = 1, r = 1; r <= n; ++r) {
            while (x[r] - x[l] > d) ++l;
            p[r] = l;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = p[i]; j < i; ++j) {
                ++f[j][i][1];
            }
        }
        for (int v = 1; v <= n; ++v) {
            for (int w = p[v]; w < v; ++w) {
                for (int l = 2; l <= n - 1; ++l) {
                    for (int u = 1; u < v; ++u) {
                        f[u][v][l] += f[u][w][l - 1];
                    }
                }
            }
        }
        int ans = 0;
        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                for (int l = 1; l < n; ++l) {
                    if (f[u][v][l]) {
                        if (f[u][v][l] == 2) ans++, debug(u, v);
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
        debug(__LINE__, "ciallo~");
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t >> t; for (int _ = 1; _ <= t; ++_) Odette::main();
    return 0;
}
*/
