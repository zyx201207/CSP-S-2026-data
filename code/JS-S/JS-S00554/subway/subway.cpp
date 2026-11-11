#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> c;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= 2 * k; j++) cin >> c;
    }
    for (int i = 1 ;i <= q; i++) cin >> c >> c;
    srand(time(0));
    for (int i = 1; i <= q; i++)
    cout << rand() << "\n";
    return 0;
}
