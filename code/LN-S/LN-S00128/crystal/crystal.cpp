#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 5e5 + 5;
ll a[N], sum[N];
ll n, m;
bool check(ll x)
{
    for (int i = 1; i + x - 1 <= n; i++) {
        if (sum[i + x - 2] - sum[i - 1] + m >= a[i + x - 1] * (x - 1)) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll l = 1, r = n;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ans << std::endl;
}