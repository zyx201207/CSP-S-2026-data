#include <bits/stdc++.h>

#define int long long

int a[500010];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    int l = 1;
    int ans = 0;
    int req = 0;
    for (int r = 2; r <= n; r++) {
        req += (a[r] - a[r - 1]) * (r - l);
        while (req > m) {
            req -= a[r] - a[l];
            l++;
        }
        ans = std::max(ans, r - l + 1);
    }
    std::cout << ans << '\n';
}
