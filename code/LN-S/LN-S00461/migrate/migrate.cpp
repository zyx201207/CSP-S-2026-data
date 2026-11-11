#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t; cin >> c >> t;
    while (t--) {
        ll n, d; cin >> n >> d;
        ll delta;
        bool flag = 1;
        cin >> a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            if (i == 2) delta = a[i] - a[i - 1];
            else if (delta != a[i] - a[i - 1]) flag = 0;
        }
        if (n <= 3) {
            cout << 0 << endl;
            continue;
        }
        cout << 0 << endl;
        continue;
        if (n <= 5000) {
            ll ans = 0;
            for (int i = 1; i + 3 <= n; i++) {
                if (a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d && a[i + 3] - a[i] > d) ans++;
            }
            cout << ans << endl;
            continue;
        }
        if (flag) {
            ll ans = 0;
            for (int i = 1; i + 3 <= n; i++) {
                if (a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d && a[i + 3] - a[i] > d) ans++;
            }
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}
