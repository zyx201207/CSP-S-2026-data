#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
const int N = 5e5 + 10;
int w[N];
int k[510];
int a[510][N], t[510][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << w[x] + t[1][1] + t[1][1] + w[y] << endl;
    }

    return 0;
}
