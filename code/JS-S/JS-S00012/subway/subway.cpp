#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q, xr, yr;
int a[N], t[N], w[N], x[N], y[N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a[j] >> t[j];
        }
    }
    for(int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
    }
    return 0;
}
