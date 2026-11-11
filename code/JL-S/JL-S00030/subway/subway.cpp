#include<bits/stdc++.h>
using namespace std;
const int N = 500005, Q = 100005;
int c, n, m, d, q, t[N], k, x, y;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> k;
        for (int j = 1; j <= 2 * k; j ++) {
            cin >> t[i];
        }
    }
    for (int i = 1; i <= q; i ++) {
        cin >> x >> y;

    }
    return 0;
}
