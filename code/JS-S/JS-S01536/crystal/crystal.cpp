#ifndef ENABLE_DEBUG
#define NDEBUG
#endif
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ui128 = __uint128_t;
#define amin(x, y) x = min(x, y)
#define amax(x, y) x = max(x, y)
#define gcd(x, y) __gcd(x, y)
#ifdef NO_FILE
#define file(x) (void)0
#else
#define file(x) auto _ = freopen(x ".in", "r", stdin); \
                     _ = freopen(x ".out", "w", stdout); \
                (void)_;
#endif

constexpr int maxn = 500001;

int n;
ll m;

ll a[maxn];
ll sum[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("crystal");

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) / 2;
            if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        assert(l == r);
        amax(ans, i - l + 1);
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}
