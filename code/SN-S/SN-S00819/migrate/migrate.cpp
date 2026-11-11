#include <bits/stdc++.h>

#define int long long

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    std::cin >> c >> t;
    while (t--) {
        int n, d;
        std::cin >> n >> d;
        std::vector<int> x(n + 1);
        std::vector<int> last(n + 1);
        std::vector<int> dis(n + 1);
        x[0] = LONG_LONG_MIN;
        for (int i = 1; i <= n; i++) {
            std::cin >> x[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            last[i] = i;
            dis[i] = 0;
            int cnt = 0;
            for (int j = i + 1; j <= n; j++) {
                last[j] = last[j - 1];
                while (x[last[j]] < x[j] - d) {
                    last[j]++;
                }
                dis[j] = dis[last[j]] + 1;
                if (x[j] - x[j - 1] > d) {
                    break;
                }
                if (j - 3 >= i && x[j] - x[j - 3] <= d) {
                    break;
                }
                if (j - 2 >= i && x[j] - x[j - 2] <= d && dis[j - 2] == dis[j - 1]) {
                    cnt++;
                }
                if (cnt == 1) {
                    ans++;
                }
            }
        }
        std::cout << ans << '\n';
    }
}
