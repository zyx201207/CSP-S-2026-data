#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int a[N];
    int c, t;
    cin >> c >> t;
    while (t--) {
        ll n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int k = a[2]- a[1];
        if (k > d) {
            cout << 0 << "\n";
            continue;
        }
        int res;
        for (int i = 1; i <= n; i++) {
            if (k * i > d) {
                res = i;
                break;
            }
        }
        cout << max(0ll, n - res) << "\n";
}



return 0;
}
