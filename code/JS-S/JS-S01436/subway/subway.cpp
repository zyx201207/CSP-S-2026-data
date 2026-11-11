#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int rd[501][501];
int a[501];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rd[i][j] = 2147483647;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        int tot[x + 1], totv[x + 1];
        for (int j = 1; j <= x; j++) {
            cin >> tot[j] >> totv[j];
        }
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= x; k++) {
                if (j != k)
                    rd[j][k] = min(rd[j][k], totv[j] + totv[k]);
            }
        }

    }for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << a[x] + a[y] + rd[x][y] << endl;
    }
}
