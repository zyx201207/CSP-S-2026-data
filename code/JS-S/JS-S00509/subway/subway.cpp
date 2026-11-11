#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int N = 5e5 + 7, M = 507, D = 27; // tot: N + M
const ll INF = 0x3F3F3F3F3F3F3F3F;
ll w[N], mp[M][M], gk[N], c, n, m, d, q;
bool vis[N + M];
pll g[N][D];
void read(ll& res) {
    res = 0;
    int ch = getchar_unlocked();
    bool neg = 0;
    while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) ch = getchar_unlocked();
    if (ch == EOF) return;
    if (ch == '-') neg = 1, ch = getchar_unlocked();
    while ('0' <= ch && ch <= '9') res = res * 10 + ch - 48, ch = getchar_unlocked();
    if (ch != EOF) ungetc(ch, stdin);
    if (neg) res = -res;
}
signed main() {
    ios::sync_with_stdio(false), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c), read(m), read(n), read(d), read(q);
    for (ll i = 1; i <= n; ++i) read(w[i]);
    for (ll i = 1; i <= m; ++i) {
        ll k;
        read(k);
        while (k--) {
            ll t, s;
            read(t), read(s);
            g[t][++gk[t]] = make_pair(i, s);
        }
    }
    memset(mp, 0x3F, sizeof mp);
    for (ll i = 1; i <= m; ++i) mp[i][i] = 0;
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 2; i <= gk[k]; ++i) {
            for (ll j = 1; j < i; ++j) {
                mp[g[k][i].first][g[k][j].first] = mp[g[k][j].first][g[k][i].first] = g[k][i].second + g[k][j].second;
            }
        }
    }
    for (ll k = 1; k <= m; ++k) {
        for (ll i = 1; i <= m; ++i) {
            for (ll j = 1; j <= m; ++j) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    while (q--) {
        ll s, t, res = LLONG_MAX;
        read(s), read(t);
        for (ll i = 1; i <= gk[s]; ++i) {
            for (ll j = 1; j <= gk[t]; ++j) {
                res = min(res, g[s][i].second + g[t][j].second + mp[g[s][i].first][g[t][j].first]);
            }
        }
        cout << (res + w[s] + w[t]) << '\n';
    }
    return 0;
}
