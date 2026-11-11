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

constexpr int maxn = 500001;
constexpr int maxm = 300001;

int n, m;
int a[maxn];
int cur[maxm];

int lowbit(int x) {
    return x & (-x);
}

struct BIT {
    int v[maxn + 1];

    void update(int x, int off) {
        for (; x <= n; x += lowbit(x)) {
            v[x] += off;
        }
    }

    int query(int x) {
        int ans = 0;
        for (; x; x -= lowbit(x)) {
            ans += v[x];
        }
        return ans;
    }
} bit;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("card");

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cur[a[i]] = i;
        bit.update(i, 1);
    }

    for (int i = 1; i <= n; ++i) {
        if (cur[a[i]] != i) {
            int v = bit.query(i);
            bit.update(i + 1, -v);
            bit.update(cur[a[i]], v);
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << bit.query(cur[i]) << ' ';
    }
    cout << '\n';

    cout << flush;
    return 0;
}
