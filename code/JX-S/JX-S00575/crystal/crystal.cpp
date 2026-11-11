// main
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

signed main() {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    bool flag1 = true;
    bool flag2 = true;
    std::vector<int> a(n + 1, -10000000000000LL);
    std::vector<int> b(n + 1, 0);
    std::vector<int> c(n + 1, 0);

    int dd;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (i == 2) dd = a[i] - a[i - 1];
        if (i > 2 && a[i] - a[i - 1] != dd) flag2 = false;
        if (a[i] != i) flag1 = false;
    }

    if (flag1) {
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            if (i * (i - 1) > 2 * m) break;
            else ans = i;
        }
        std::cout << ans;
        return 0;
    }
    if (flag2) {
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            if (i * dd * (i - 1) > 2 * m) break;
            else ans = i;
        }
        std::cout << ans;
        return 0;
    }
    std::sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; ++i) {
        b[i] = a[i] - a[i - 1];
        c[i] = c[i - 1] + b[i];
    }

    int ans = 1;
    std::vector<int> d(n + 1, 1);
    if (d[2] <= m) d[2] = 2;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            d[i] = d[i - 1] + 1;
            ans = std::max(d[i] + 1, ans);
            continue;
        }
        int now = b[i];
        for (int j = 2; j < i; ++j) {
            now = now + c[i] - c[i - j];
            if (now > m) break;
            ans = std::max(ans, j + 1);
            d[i] = j;
        }
    }


    std::cout << ans;
}
