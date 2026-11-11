#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define int long long

template<class T> inline void ckmin(T& x, T y) { if(x > y) x = y; }
template<class T> inline void ckmax(T& x, T y) { if(x < y) x = y; }
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
static constexpr int N = 5e5 + 5, M = 505, inf = 0x3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[N], dp[M][M];
vector<pair<int, int>> v[M], g[N];
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
signed main() {
    (cin.tie(0), cout.tie(0)) -> sync_with_stdio(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        while(k --> 0) {
            int a, t; cin >> a >> t;
            v[i].emplace_back(a, t);
            g[a].emplace_back(i, t);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= m; i++) {
        for(auto ix : g[i]) for(auto iy : g[i]) {
            if(ix.first != iy.first) {
                ckmin(dp[ix.first][iy.first], ix.second + iy.second);
            }
        }
    }

    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j || j == k || i == k) continue;
                ckmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q --> 0) {
        int x, y; cin >> x >> y;
        int base = w[x] + w[y];
        if(x == y) {
            cout << 0 << '\n';
            continue;
        }

        int ans = inf;
        for(auto ix : g[x]) for(auto iy : g[y]) {
            // cerr << ix.first << ' ' << ix.second << "; " << iy.first << ' ' << iy.second << '\n';
            int add = ix.second + iy.second + dp[ix.first][iy.first];
            // cerr << ix.second + iy.second << ' ' << dp[ix.first][iy.first] << '\n';
            ckmin(ans, base + add);
        }
        cout << ans << '\n';
    }

    // cerr << 1. * clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}