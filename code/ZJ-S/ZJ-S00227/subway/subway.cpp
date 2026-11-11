#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    vector<vector<int>> a(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        a.resize(k + 1);
        for (int j = 1; j <= k; j++) cin >> a[i][j] >> t[i][j];
    } 

    if (12 <= c && c <= 19) {
        auto solve = [&](int x, int y) {

        };

        while (q --) {
            int x, y; cin >> x >> y;
            cout << solve(x, y) << '\n';
        }        
    }


    return 0;
}