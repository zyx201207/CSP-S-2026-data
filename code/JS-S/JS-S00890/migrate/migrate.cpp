#include <bits/stdc++.h>
long long c, ttt, n, d, x[2000005], l[2000005], r[2000005], rr[2000005], ans;
void solve() {
    std::cin >> n >> d, ans = 0, rr[n + 1] = n + 1;
    for (long long i = 1; i <= n; ++i)
        std::cin >> x[i];
    for (long long i = 1; i < n; ++i)
        r[i] = std::upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
    for (long long i = n; i; --i)
        l[i] = std::lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    for (long long i = n; i; --i)
        if (x[i + 1] - x[i] <= d && x[i + 2] - x[i] > d)
            rr[i] = rr[i + 1];
        else
            rr[i] = i;
    for (long long i = 1; i <= n; ++i)
        if (r[rr[i]] < n)
            ans += (rr[std::upper_bound(l + 1, l + n + 1, r[rr[i]] - 1) - l] - (std::lower_bound(l + 1, l + n + 1, r[rr[i]] - 1) - l)) * (rr[i] - i + 1);
    std::cout << ans << '\n';
}
int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout), std::cin >> c >> ttt;
    while (ttt--)
        solve();
    return 0;
}
