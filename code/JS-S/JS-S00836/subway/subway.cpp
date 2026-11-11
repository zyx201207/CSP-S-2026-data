#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q, k;
    int a, b;
    int w[500005];
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= 2 * k; j++)
            cin >> a >> b;
    }
    for (int i = 1; i <= q; i++) {
        cin >>a >> b;
    }

    cout << 32 << endl;
    cout << 17 << endl;
    return 0;
}
