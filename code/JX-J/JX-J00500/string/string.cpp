#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 2e5 + 5;
int n, a[N];
char c[N];
ll s[N], ans;
int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        s[i] = a[i] + s[i - 1];
    }
    ll mid = (s[n] + 1) / 2, l, r;
    if (s[n] & 1ll) l = mid - 1, r = mid + 1;
    else l = mid, r = mid + 1;
    int il = lower_bound(s + 1, s + n + 1, l) - s, 
    ir = lower_bound(s + 1, s + n + 1, r) - s;
    while (l > 0 && r <= s[n]) {
        ll x = min(l - s[il - 1], s[ir] - r + 1);
        if (c[il] != c[ir]) ans += x;
        l -= x; r += x;
        if (l == s[il - 1]) il--;
        if (r > s[ir]) ir++;
    }
    cout << ans << endl;
    return 0;
}