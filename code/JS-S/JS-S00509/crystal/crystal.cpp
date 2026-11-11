#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 7;
ll a[N], n, m;
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
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    read(n), read(m);
    for (ll i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + 1 + n);
    ll ans = 1;
    for (ll l = 1, r = 2, sum = a[1]; r <= n; ++r) {
        sum += a[r];
        while (m < (a[r] * (r - l + 1)) - sum) sum -= a[l++];
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
