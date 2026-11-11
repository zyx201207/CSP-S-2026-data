/*
轻松了 2h 还不够我 T3T4 部分分？
这个 T3 感觉难度完全凌驾于我之上
部分分的代码看上去都不简单

f[i][j] 表示 i 到 j 的最短路长度和方案数，容易 O(n^3)

好像有 24pts 写试试
感觉好难写啊，估计要分析 2 条最短路的性质，先跳了
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 5, INF = 0x3f3f3f3f;

int c, t, n, d, x[N], f[N][N], g[N][N];

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            f[i][j] = INF, g[i][j] = 0;
    for (int i = 1; i <= n; ++i) f[i][i] = 0, g[i][i] = 1;
    for (int l = 1; l <= n; ++l)
        for (int i = 1, j; (j = i - l + 1) <= n; ++i)
            for (int k )
}

signed main() {

    int c, t; cin >> c >> t;
    while (t--) solve();
    return 0;
}