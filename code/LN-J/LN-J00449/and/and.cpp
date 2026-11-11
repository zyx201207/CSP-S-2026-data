#include <bits/stdc++.h>
#define sfr return cout << "safe\n", 0;
#define sf_void return cout << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
#define FILEIO "and"
const int N = 2e5 + 10, M = 32;

int n, m, a[N];
int tot, ch[N * M][2], cnt[N * M], yu[N * M], val[N * M];

// auto ins(int s) {
//     int p = 0;
//     // if (!cnt[p]) yu[p] = s;
//     // else yu[p] &= s;
//     // ++cnt[p];
//     int cur = 0;
//     for (int tgt, i = 30; i >= 0; --i) {
//         tgt = (s >> i) & 1;
//         if (!ch[p][tgt]) ch[p][tgt] = ++tot;
//         p = ch[p][tgt];
//         if (!cnt[p]) yu[p] = s;
//         else yu[p] &= s;
//         ++cnt[p];
//         cur += s & (1 << i);
//         val[p] = cur;
//     }
// }

// auto qry(int pos, int yl) -> int {
//     if (yl == cnt[pos]) return yu[pos];
//     // int ret = 0;
//     if (cnt[ch[pos][1]] >= yl) return qry(ch[pos][1], yl);
//     else {
//         return val[pos];
//         // cerr << val[pos] << "\n";
//     }
// }

// int lst[N];

// auto bf(int pos) -> int {
//     if (pos == m + 1) {
//         int ret = a[lst[1]];
//         for (int i = 2; i <= m; ++i) ret &= a[lst[i]];
//         return ret;
//     }
//     int ret = 0;
//     for (int i = lst[pos - 1] + 1; i <= n; ++i) {
//         lst[pos] = i;
//         ret = max(ret, bf(pos + 1));
//         lst[pos] = 0;
//     }
//     return ret;
// }

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i]; // ins(a[i]);
    // if (m == 1) {
    //     return cout << *max_element(a + 1, a + n + 1) << "\n", 0;
    // }
    // if (m == n) {
    //     int tmp = a[1];
    //     for (int i = 2; i <= n; ++i) tmp &= a[i];
    //     return cout << tmp << "\n", 0;
    // }
    // if (m == 2 && n <= 10000) {
    //     int ans = 0;
    //     for (int i = 1; i <= n; ++i) {
    //         for (int j = i + 1; j <= n; ++j) {
    //             ans = max(ans, a[i] & a[i + 1]);
    //         }
    //     }
    //     return cout << ans << "\n", 0;
    // }
    // if (n <= 20) {
    //     return cout << bf(1) << "\n", 0;
    // }
    int cur = 0;
    for (int w = 30; w >= 0; --w) {
        int c1 = 0, c = 0;
        for (int i = 1; i <= n; ++i) {
            if ((cur & a[i]) != cur) continue;
            c1 += (a[i] >> w) & 1, c++;
        }
        if (c1 >= m) cur += (1 << w);
    }
    cout << cur << "\n";
}