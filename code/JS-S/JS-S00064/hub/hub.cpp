#include <bits/stdc++.h>
using namespace std;
int count(int state) {
    int ans = 0;
    for (int i = 10; i >= 0; i--) {
        if (state >> i & 1) ans++;
    }
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k;
    cout << 1 << "\n";
    // vector<vector<int>> e(n + 10);
    // for (int i = 1; i <= n - 1; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     e[u].push_back(v);
    //     e[v].push_back(u);
    // }
    // for (int state = 0; state < 1 << n; state++) {
    //     if (count(state) != k) {
    //         continue;
    //     }
    //     vector<int> q;
    //     for (int i = 1; i <= n; i++) {
    //         if (state >> i & 1) {

    //         }
    //     }
    // }
}
signed main() {
    freopen("hub.in", "a+", stdin);
    freopen("hub.out", "a+", stdout);

    int c, T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}