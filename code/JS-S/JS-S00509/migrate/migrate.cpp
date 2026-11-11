#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
const int N = 2e6 + 7;
ll a[N], cnt[N], cntver[N], dis[N], disver[N], ver;
void solve() {
    ll n, ans = 0, d;
    read(n), read(d);
    for (ll i = 1; i <= n; ++i) read(a[i]);
    // for (ll i = 1; i <= n; ++i) {
    //     ll j;
    //     for (j = i; j <= n && a[j] - a[i] <= d; ++j);
    //     cout << j - 1 << " \n"[i == n];
    // }
    for (ll i = 1; i < n; ++i) {
        ++ver;
        dis[i] = 0, disver[i] = ver, cnt[i] = 1, cntver[i] = ver;
        for (ll j = i; j <= n; ++j) {
            ans += (cnt[j] == 2) && (cntver[j] == ver);
            if (a[j + 1] - a[j] > d) break;
            for (ll k = j + 1; k <= n && a[k] - a[j] <= d; ++k) {
                if (disver[k] != ver) {
                    disver[k] = ver, dis[k] = dis[j] + 1, cnt[k] = cnt[j], cntver[k] = ver;
                } else if (dis[k] == dis[j] + 1) cnt[k] += cnt[j];
            }
        }
    }
    cout << ans << '\n';
}
namespace SubA {
    void solve() {
        ll n, d, step;
        read(n), read(d);
        for (ll i = 1; i <= n; ++i) read(a[i]);
        step = d / (a[2] - a[1]);
        cout << (n / step - 1) << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, T;
    read(c), read(T);
    if (11 <= c && c <= 12) {
        while (T--) SubA::solve();
        return 0;
    }
    while (T--) solve();
    // solve();
    return 0;
}
