#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

inline ll readf() {
    ll x = 0; char c = getchar_unlocked();
    for(; !isdigit(c); c = getchar_unlocked());
    for(; isdigit(c); c = getchar_unlocked()) x = x * 10 + (c ^ 48);
    return x;
}

int tcs, n, m, d, q, x, y, sz; ll t, ans; ll w[500009];
ll f[509][509]; vector < pair <int, ll> > v[500009];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    tcs = readf(), n = readf(), m = readf(), d = readf(), q = readf();
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) f[i][j] = inf;
    for(int i = 1; i <= m; i++) w[i] = readf();
    for(int i = 1; i <= n; i++) {
        sz = readf(); for(int j = 1; j <= sz; j++) {
            x = readf(), t = readf();
            for(auto [j, tj] : v[x]) f[i][j] = min(f[i][j], t + tj), f[j][i] = min(f[j][i], t + tj);
            v[x].emplace_back(i, t);
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= n; k++) f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
    for(int i = 1; i <= q; i++) {
        x = readf(), y = readf();
        ans = inf; for(auto [a, ta] : v[x]) for(auto [b, tb] : v[y]) ans = min(ans, f[a][b] + ta + tb);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}