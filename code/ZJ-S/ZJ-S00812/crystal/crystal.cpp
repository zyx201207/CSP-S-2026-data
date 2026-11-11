#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 5e5 + 5;

i64 n, m, a[N], s[N];

void sol() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    i64 l = 0, r = 0, ans = 0;
    for (; r <= n; r++) {
        i64 cur = a[r] * (r - l + 1) - (s[r] - s[l - 1]);
        while (cur > m) {
            cur -= a[r] - a[l];
            l++;
        }
        ans = std::max(ans, r - l + 1);
    }
    std::cout << ans << "\n";
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // std::cin >> T;
    while (T--) sol();

    return 0;
}