#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out". "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m);
    vector<int> ks(n);
    vector<vector<int>> a(n), t(n);
    vector<pair<int, int>> xy(q);
    for (int i = 0;p i < m; i ++) cin >> w[i];
    for (int i = 0; i < n; i ++) {
        int k; cin >> k;
        a[i].resize(k); t[i].resize(k);
        for (int j = 0; j < k; j ++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 0; i < q; i ++) {
        int x, y; cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    
}