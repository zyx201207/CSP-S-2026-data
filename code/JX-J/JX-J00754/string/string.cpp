#include <bits/stdc++.h>
using namespace std;

long long a[200005], n, l, r, ans, x;
char c[200005];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    l = 1, r = n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    while (l <= r) {
        x = min(a[l], a[r]);
        a[l] -= x, a[r] -= x;
        if (c[l] != c[r]) ans += x;
        if (a[l] == 0) ++ l;
        if (a[r] == 0) -- r;
        if (l == r) break;
    }
    cout << ans;
    return 0;
}