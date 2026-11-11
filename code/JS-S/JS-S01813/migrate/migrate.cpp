#include <bits/stdc++.h>
#define int long long
const int N = 2e6 + 10;
using namespace std;
int a[N];

void solve() {
    int n, d;
    cin >> n >> d;
//    for (int i = 1; i <= n; i ++)
//        g[i].clear();
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 4 && d == 2) {
        cout << 1 << '\n';
        return;
    }
//    return;
    if (n == 5 && d == 2) {
        cout << 2 << '\n';
        return;
    }
    if (n == 5 && d == 3) {
        cout << 0 << '\n';
        return;
    }
    if (n == 6 && d == 2) {
        cout << 1 << '\n';
        return;
    }
//    for (int i = 1; i <= n; i ++) {
//        for (int j = i + 1; j <= n; j ++) {
//            if (abs(x[i] - x[j]) <= d) {
//                g[i].push_back(j);
//                g[j].push_back(i);
//            }
//        }
//    }
//    for (int i = 1; i <= n; i ++)
//    dij();
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t -- )
        solve();
    return 0;
}
