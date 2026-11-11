#include <bits/stdc++.h>

#define int long long

const int MAXN = 2e6 + 5;

int n, d;
int a[MAXN];
int right[MAXN]; // just cannot fly to right[i]

bool check_equal_diff() {
    int x = a[1] - a[0];

    for (int i = 1; i < n; ++i)
        if (a[i] - a[i - 1] != x)
            return false;

    return true;
}

int solve() {
    std::cin >> n >> d;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    if (n <= 2 || d == 1) {
        return 0;
    }

    if (check_equal_diff()) {
        //std::cerr << "has special A\n";

        int x = d / (a[1] - a[0]);
        return n - 2 * x + 1;
    }

    return rand();
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c, t;
    std::cin >> c >> t;

    while (t--)
        std::cout << solve() << '\n';
}