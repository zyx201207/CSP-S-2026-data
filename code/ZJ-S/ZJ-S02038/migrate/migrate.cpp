#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, ans;
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d, ans = 0;
        vector<int> a(n);
        if (c == 11 || c == 12) {
            for (auto &x : a)
                cin >> x;
            int ad = a[1] - a[0];
            if (d > ad) {
                int r = d % ad, p = d / ad;
                ans = 1 - 2 * p + n;
            }
            cout << max(ans, 0LL) << '\n';
            continue;
        }
        vector<vector<int>> f(n, vector<int>(n)), st(n, vector<int>(n, 0));
        function<void(int, int, int)> dfs = [&](int i, int start, int step) {
            // cout << "dfs(" << i << ", " << start << ", " << step << ")\n";
            if (i > n) return;
            if (st[start][i] == step)
                f[start][i]++; // cout << "++f[" << start << "][" << i << "]\n";
            if (st[start][i] > step) f[start][i] = 1, st[start][i] = step;
            // cout << "f[" << start << "][" << i << "]=1\n";
            if (st[start][i] == 0) f[start][i]++, st[start][i] = step;
            // cout << "++f[" << start << "][" << i << "]\n";
            // cout << "ok\n";
            for (int j = i + 1; a[j] - a[i] <= d && j < n; j++) {
                // cout << "[j]=" << j << '\n';
                dfs(j, start, step + 1);
            }
        };
        for (auto &x : a)
            cin >> x;
        for (int i = 0; i < n - 3; i++)
            dfs(i, i, 1);
        for (int i = 0; i < n - 3; i++)
            for (int j = i + 3; j < n; j++)
                if (f[i][j] == 2)
                    ans++; // cout << "f[" << i << "][" << j << "]ok\n";
        cout << ans << '\n';
    }
    return 0;
}