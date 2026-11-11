#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int c, n, m, d, q;
int w[N], k[N];
int a[N], t[N];

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> a[i] >> t[i];
        }
    }

    while(q--) {
        int ans = 0;
        int x, y;
        cin >> x >> y;
        ans += w[x] + t[y];
        cout << ans << endl;
    }

    return 0;
}
