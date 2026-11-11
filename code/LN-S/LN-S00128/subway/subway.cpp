#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 505, M = 5e5 + 5;
ll c, n, m, d, q;
ll w[M];
std::vector < ll > a[N], t[N];
std::map < ll, ll > pos[N];
ll f[N][N];
std::vector < std::pair < ll, ll > > mp[M];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; i++) std::cin >> w[i]; // walktime
    for (ll i = 1; i <= n; i++) {
        ll k; std::cin >> k;
        a[i].resize(k + 1); t[i].resize(k + 1);
        for (ll j = 1; j <= k; j++) {
            std::cin >> a[i][j] >> t[i][j]; // station, time
            pos[i][a[i][j]] = j;
            mp[a[i][j]].push_back({i, t[i][j]});
        }
    }
    memset(f, 0x3f, sizeof f);
    for (ll i = 1; i <= n; i++) f[i][i] = 0;
    for (ll i = 1; i <= m; i++) {
        for (std::pair < ll, ll > j : mp[i]) {
            for (std::pair < ll, ll > k : mp[i]) {
                if (j.first != k.first) {
                    f[k.first][j.first] = f[j.first][k.first] = std::min(j.second + k.second, f[j.first][k.first]);
                }
            }
        }
    }
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++) {
                f[i][j] = std::min(f[i][k] + f[k][j], f[i][j]);
            }
    while (q--) {
        ll x, y; std::cin >> x >> y;
        std::vector < ll > st, ed;
        for (std::pair < ll, ll > it : mp[x]) {
            st.push_back(it.first);
        }
        for (std::pair < ll, ll > it : mp[y]) {
            ed.push_back(it.first);
        }
        ll ans = 1e18;
        for (ll i : st) {
            for (ll j : ed) {
                if (f[i][j] + t[i][pos[i][x]] + t[j][pos[j][y]] < ans) {
                    ans = f[i][j] + t[i][pos[i][x]] + t[j][pos[j][y]];
                }
            }
        }
        std::cout << ans + w[x] + w[y] << std::endl;
    }
}