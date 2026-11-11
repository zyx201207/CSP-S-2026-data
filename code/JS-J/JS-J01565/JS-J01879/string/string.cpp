#include <bits/stdc++.h>
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

constexpr int maxn = 200001;

int n;
ll a[maxn];
char ch[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("string");

    cin >> n;
    ll t = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> ch[i];
        t += a[i];
    }

    int li = 1, ri = n;
    ll l = 0, r = 0;
    ll ans = 0;
    while (li <= ri) {
        if (l < r) {
            if (ch[li] != ch[ri + 1]) {
                ans += min(a[li], r - l);
            }
            l += a[li];
            ++li;
        } else {
            if (ch[ri] != ch[li - 1]) {
                ans += min(a[ri], l - r);
            }
            r += a[ri];
            --ri;
        }
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}
