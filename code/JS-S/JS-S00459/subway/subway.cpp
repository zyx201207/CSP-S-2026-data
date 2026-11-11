#include<bits/stdc++.h>
using namespace std;

long long w[125005], a[505][505];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long c, n, m, d, q, k, t, a, x, y;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    if (c >= 12 && c <= 19) {
        for (int i = 1; i <= n; i++) {
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> a[i][j] >> t;
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> x >> y;
            cout << (max(x, y) - min(x, y)) * t << '\n';
        }
    }
    return 0;
}
