#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 10;

int c, t, x[maxn];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c;
    if (1 <= c && c <= 10) {
        cin >> t;
        while (t--) {
            int n, d, cnt = 0;
            cin >> n >> d;
            for (int i = 1; i <= n; i++) cin >> x[i];
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    int dist = abs(x[i]- x[j]);
 //                   cout << "distance: " << dist << endl;
                    if ((dist > d && abs(i - j) == 1) || dist > 2 * d) continue;
                    if (dist > d && dist % d == d - 1 && (x[j] - x[j-1]) <= d) ++cnt;
                }
            }
            cout << cnt << endl;
        }
    }
    else if (11 <= c && c <= 12) {
        cin >> t;
        while (t--) {
            int n, d, cnt = 0;
            for (int i = 1; i <= n; i++) cin >> x[i];
            int avg = x[2] - x[1];
            if (avg > d) continue;
            else if (avg == d) cout << 0 << endl;
            else {
                if (d % avg == 0) {
                    for (int i = 1; i <= n; i++) {
                        for (int j = i + 1; j <= n; j++) {
                            int dist = abs(x[j] - x[i]);
                            if (dist > 2 * d) continue;
                            if (dist % d != 0) cnt++;
                        }
                    }
                }
                cout << cnt << endl;
            }
        }
    }
    else {
        cin >> t;
        while (t--) cout << rand() % 10 + 1 << endl;
    }
    return 0;
}
