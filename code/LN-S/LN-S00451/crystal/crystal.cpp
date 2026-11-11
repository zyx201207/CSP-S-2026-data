#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500009], c[500009], m, n, t;
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    t = m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    for (ll i = 2; i <= n; i++) {
        c[i - 1] = a[i] - a[i - 1];
    }
    if (n <= 10000) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
                m = t;
            for (ll j = i + 1; j <= n; j++) {
                if (m - c[j - 1] * (j - 1) >= 0) {
                    m -= c[j - 1] * (j - 1);
                } else {
                    ans = max(ans, j - i);
                    break;
                }
            }
        }
        cout << ans;
        return 0;
    }
    for (ll i = 2; i <= n; i++) {
        if (m - c[i - 1] * (i - 1) >= 0) {
            m -= c[i - 1] * (i - 1);
        } else {
            cout << i - 1;
            return 0;
        }
    }
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
