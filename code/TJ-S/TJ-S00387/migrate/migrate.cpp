#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    auto solve1 = []() {
        int n, d;
        cin >> n >> d;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        if (n == 1) cout << 0 << "\n";
        
        vector<vector<int>> f(n, vector<int>(n, inf)), cnt(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            f[i][i] = 0, cnt[i][i] = 1;
            vector<int> tmp(n, 0);
            tmp[0]++;
            int mn = 0;
            for (int j = i + 1, l = i; j < n; j++) {
                while (x[j] - x[l] > d) tmp[f[i][l]] -= cnt[i][l], l++;
                if (l == j) break;
                while (!tmp[mn]) mn++;
                tmp[f[i][j] = mn + 1] += (cnt[i][j] = tmp[mn]);
                ans += (cnt[i][j] == 2);
            }
        }
        cout << ans << "\n";
    };

    auto solve2 = []() {
        int n, d;
        cin >> n >> d;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        if (n == 1) { cout << 0 << "\n"; return; }

        int len = d / (x[1] - x[0]);
        if (len <= 1) { cout << 0 << "\n"; return; }
        cout << max(0ll, n - 2 * len + 1) << "\n";
    };
    
    int c, _;
    cin >> c >> _;
    while (_--) {
        if (c <= 10) solve1();
        else if (c <= 12) solve2();
    }

    return 0;
}