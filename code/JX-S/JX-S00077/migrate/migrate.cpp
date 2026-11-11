#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        ll ans = 0;
        for (ll i = 1, a1 = 0, a2 = 0, a3 = 1; i <= n; i++, a1 = a2) {
            cin >> a2;
            if (i == 1) {
                a1 = a2;
            }
            else {
                if (a2 - a1 == d) {
                    a3++;
                }
                if (a3 == 1) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//AFO li wo bu yuan le.
