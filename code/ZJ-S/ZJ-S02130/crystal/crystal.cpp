#include <bits/stdc++.h>

#define int long long

const int MAXN = 500005;

int n, m;
int a[MAXN];
int sum[MAXN];

bool check(int l, int r) {
    return a[r] * (r - l) - (sum[r] - sum[l]) <= m;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a, a + n);

    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + a[i];

    int ans = 1;

    int i = 0, j = 0;
    while (i < n) {
        while (j < n && a[i] == a[j])
            ++j;

        int l = 0, r = i;
        int as = -1;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid, i)) {
                as = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        ans = std::max(ans, j - as);

        i = j;
    }

    std::cout << ans << '\n';
}