#include <bits/stdc++.h>
using namespace std;

int w[510], k[510];
int a[1010][2], t[1010][2];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        ans += w[x] + w[y];
        int mx = 1e9;
        for (int i = 1; i <= n; i++) {
            if (a[i][1] == y) mx = min(mx, w[i] + t[i][1]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i][2] == y) mx = min(mx, w[i] + t[i][1] + t[i][2]);
        }
        cout << ans + mx << "\n";
    }
    return 0;
}

