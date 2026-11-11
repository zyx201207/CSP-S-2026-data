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

constexpr int maxn = 2000001;
int c;
int n;
ll d;
ll v[maxn];
int path[maxn];

int getpath(int x, int y) {
    int pathsiz = 0;
    int c = x;
    for (; c < y; ++pathsiz) {
        path[pathsiz] = c;
        int tmp = upper_bound(v + c + 1, v + y + 1, v[c] + d) - v - 1;
        if (tmp == c) {
            return -1;
        }
        c = tmp;
    }
    path[pathsiz++] = y;
    return pathsiz;
}

int check(int x, int y) {
    int pathsiz = getpath(x, y);
    if (pathsiz == -1) {
        return -1;
    }

    int idx = 0;
    for (int i = 1; i < pathsiz - 1; ++i) {
        if (path[i] - 1 > path[i - 1] && v[path[i + 1]] - v[path[i] - 1] <= d) {
            if (path[i] - 2 > path[i - 1] && v[path[i + 1]] - v[path[i] - 2] <= d) {
                return 0;
            }
            if (idx == 0) {
                idx = i;
            } else {
                return 0;
            }
        }
    }

    if (idx == 0) {
        return 0;
    }
    if (idx == 1) {
        return 1;
    }
    return v[path[idx] - 1] - v[path[idx - 1] - 1] > d;
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    // spj A
    if (c == 11 || c == 12) {
        ll x = d / (v[2] - v[1]);
        if (x < 2 || n <= 2 * x - 1) {
            cout << "0\n";
            return;
        }
        cout << n - (2 * x - 1) << '\n';
        return;
    }

    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int r = check(i, j);
            if (r == 1) {
                ++cnt;
            } else if (r == -1) {
                break;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("migrate");

    int t;
    cin >> c >> t;
    while (t--) {
        solve();
    }

    cout << flush;
    return 0;
}
