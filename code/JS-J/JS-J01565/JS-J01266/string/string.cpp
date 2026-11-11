#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n; ll a[N], s[N], ans; char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i]; s[i] = s[i - 1] + a[i];
    }
    for (ll l = 1, r = s[n]; l <= r; ) {
        int p = lower_bound(s + 1, s + 1 + n, l) - s, q = lower_bound(s + 1, s + 1 + n, r) - s, llen = s[p] - l + 1, rlen = r - s[q - 1];
        if (c[p] != c[q]) ans += min(llen, rlen);
        if (llen < rlen) l += llen, r -= llen;
        else l += rlen, r -= rlen;
    }
    cout << ans << endl;
    return 0;
}
// 100
