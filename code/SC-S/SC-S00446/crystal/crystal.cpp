#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cctype>
#include <cmath>
#include <set>

#define int long long
#define FILENAME "crystal"

const int MAXN = 500000+4;
int a[MAXN], n, m;

int safe_add(int x, int y) {
    if (LLONG_MAX - x >= y) return x + y;
    return -1;
}
int safe_mul(int x, int y) {
    if (LLONG_MAX / y >= x) return x * y;
    return -1;
}

signed main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    int ans = 0, tot = 0, l = 1;
    for (int i = 1; i <= n; ++i) {
        int diff = a[i] - a[i-1];
        while (l < i) {
            int add = safe_mul(diff, i - l);
            if (add == -1) {
                tot -= a[i-1] - a[l];
                ++l;
                continue;
            }
            int newtot = safe_add(add, tot);
            if (newtot == -1) {
                tot -= a[i-1] - a[l];
                ++l;
                continue;
            }
            if (newtot > m) {
                tot -= a[i-1] - a[l];
                ++l;
                continue;
            }
            tot = newtot;
            break;
        }
        // printf("For %lld, max is %lld, tot = %lld\n", i, l, tot);
        ans = std::max(ans, i - l + 1);
    }
    std::cout << ans << std::endl;
    std::cout.flush();


    fclose(stdin);
    fclose(stdout);
    return 0;
}