#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000005;

int c, t, n, a[N], d;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int m = a[2] - a[1];
        if (m >= d) {
            cout << 0 << endl;
            continue;
        }
        int t = d / m;
        d = m * t;
        if (t == 2) cout << n - 3 << endl;
        else if (d < 2){
            cout << n - t << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
