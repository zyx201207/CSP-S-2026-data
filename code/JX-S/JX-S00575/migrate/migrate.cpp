#include <iostream>
#include <vector>
#define int long long

signed main() {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);
    int c, t;
    std::cin >> c >> t;

    while (t--) {
        int n, d;
        std::cin >> n >> d;

        std::vector<int> a(n + 1);
        int dd = 0;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (i == 2) dd = a[i] - a[i - 1];
            if (i > 2 && a[i] - a[i - 1] != dd) flag = false;

        }

        if (flag && n >= 2) {
            if (dd > d) {
                std::cout << 0 << '\n';
                continue;
            }
            int k = d / dd;
            if (k == 1) {
                std::cout << 0 << '\n';
                continue;
            }
            if (n < 2 * k) {
                std::cout << 0 << '\n';
                continue;
            }
            std::cout << n - 2 * k + 1 << '\n';

            continue;
        }
        std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1, 0));
        int answer = 0;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i < j; ++i) {
                int cnt = 0;
                int minn = 5 * 1e18;
                for (int k = i; k < j; ++k) {
                    if (a[j] - a[k] > d) continue;
                    if (ans[i][k] < minn) {
                        minn = ans[i][k];
                        cnt = 1;
                    } else if(ans[i][k] == minn) {
                        ++cnt;
                    }
                }
                ans[i][j] = minn + 1;
                if (cnt == 2) ++answer;
            }
        }
        std::cout << answer << '\n';
    }
}
