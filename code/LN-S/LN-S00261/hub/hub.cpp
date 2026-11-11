#include <bits/stdc++.h>
#define sfr return cerr << "safe\n", 0;
#define sfv return cerr << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
using prt = tuple<int, int>;
using tpt = tuple<int, int, int>;
#define FILEIO "hub"

int c, t, n, k;

auto chk(int t) {
    int L = 1 + t, R = n - t;
    if (L > R) return 1;
    for (int i = L; i <= R; ++i) {

    }
}

auto solA() {
    cin >> n >> k;
    for (int i = 1, u; i < n; ++i) cin >> u >> u;
    int mid, L = 0, R = n - 1;
    while (L < R) {
        mid = L + R >> 1;
        if (chk(mid)) R = mid;
        else L = mid + 1;
    }
}

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> t;
    if (c == 13 || c == 14) {
        solA();
    }
}