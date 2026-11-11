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
#define FILENAME "migrate"

const int MAXN = 2000004;
int c, T;
int n, d, x[MAXN], l[MAXN], r[MAXN];
int dis[MAXN], cnt[MAXN];

void solve() {
    std::cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i];
    }
    // for (int i = 2; i <= n; ++i) {
    //     printf("%lld ", x[i] - x[i-1]);
    // }
    for (int i = 1; i <= n; ++i) {
        int L = i + 1, R = n + 1;
        int D = x[i] + d;
        while (L < R) {
            int mid = (L + R) >> 1;
            if (D < x[mid]) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        r[i] = L - 1;
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= r[i]) {
            l[j++] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int p = 1; p <= i; ++p) {
            dis[p] = 0;
            cnt[p] = 0;
        }
        cnt[i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            dis[j] = dis[l[j]] + 1;
            int cur = std::max(l[j], i);
            cnt[j] = 0;
            for (; cur < j && dis[cur] < dis[j]; ++cur) {
                cnt[j] += cnt[cur];
                if (cnt[j] >= 3) break;
            }
            if (cnt[j] == 2) {
                ++ans;
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> c >> T;
    for (int t = 1; t <= T; ++t) {
        solve();
    }
    std::cout.flush();

    fclose(stdin);
    fclose(stdout);
    return 0;
}