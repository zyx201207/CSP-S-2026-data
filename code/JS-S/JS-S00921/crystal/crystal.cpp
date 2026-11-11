// chennie ls bless me
// cubber ls bless me
// Oct31==Dec25?

#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <numeric>
#include <iomanip>
#include <queue>
#include <random>
#include <time.h>
using i64 = long long;
#define sz(x) (int)x.size()
#define IO(s) assert(freopen(s".in", "r", stdin)); assert(freopen(s".out", "w", stdout))
const int N = 5e5 + 10;
i64 n, m;
i64 a[N], sum[N];

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (j <= i && m < a[i] * (i - j + 1) - (sum[i] - sum[j - 1])) j++;
        ans = std::max(ans, i - j + 1);
    }
    std::cout << ans << '\n';
}

int main() {
    IO("crystal");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--) solve();
    return 0;
}