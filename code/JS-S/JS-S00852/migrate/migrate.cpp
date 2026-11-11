#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int a[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, T;
    cin >> c >> T;
    if (c == 12 || c == 11) {
        while (T--) {
            int n, d;
            cin >> n >> d;
            int num = 0;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
            }
            int cha = a[2] - a[1];
            if (d < cha) {
                cout << 0 << endl;
                continue;
            }
            if (d < 3 * cha && d > 2 * cha) {
                cout << n - 3 << endl;
                continue;
            }
        }
    }
    while (T--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int num = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 2; j <= n; j++) {
                for (int k = i + 1; k <= j; k++) {
                    if (a[k] - a[i] <= d && a[j] - a[k] <= d) {
                        ans++;
                        if (ans > 2) break;
                    }
                }
                if (ans == 2) {
                    num++;
                }
            }

        }
        cout << num << endl;
    }
    return 0;
}
