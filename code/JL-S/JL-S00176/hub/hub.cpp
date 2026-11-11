#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2e5 + 10;
int c, n, m;
void Solve() {
    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
    }
    cout << max(n / m - 1, 0) << '\n';
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    int c, T = 1; cin >> c >> T;
    while (T--) Solve();
    return 0;
}
