#include <bits/stdc++.h>
long long n, m, a[500005], sum, ans, j = 1;
int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout), std::cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; ++i) {
        sum -= a[i - 1];
        while (a[j + 1] * (j + 1 - i + 1) <= m + sum)
            ++j, ans = std::max(ans, j - i + 1), sum += a[j];
        if (j > n)
            break;
    }
    std::cout << ans;
    return 0;
}
