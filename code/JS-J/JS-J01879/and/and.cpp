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

int n, m;
uint a[maxn];
bool chosen[2][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("and");

    cin >> n >> m;
    bool cur = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        chosen[cur][i] = true;
    }

    uint ans = (1u << 30u) - 1u;
    for (uint b = 29; true; --b) {
        cur = !cur;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            chosen[cur][i] = false;
            if (chosen[!cur][i] && ((a[i] >> b) & 1)) {
                chosen[cur][i] = true;
                ++cnt;
            }
        }
        
        if (cnt < m) {
            for (int i = 1; i <= n; ++i) {
                chosen[cur][i] = chosen[!cur][i];
            }
            ans ^= 1u << b;
        }

        if (b == 0) {
            break;
        }
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}
