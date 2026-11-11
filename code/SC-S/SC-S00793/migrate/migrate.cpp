#include <bits/stdc++.h>
using namespace std;

ifstream inf("migrate.in");
ofstream ouf("migrate.out");

#define vec vector
using i64 = long long;

void solve() {
    int n; i64 d;
    inf >> n >> d;
    vec<i64> x(n + 1);
    for (int i = 1; i <= n; ++i) inf >> x[i];

    vec<int> pre(n + 1), nxt(n + 1);
    pre[1] = 1;
    for (int i = 2; i <= n; ++i) {
        pre[i] = pre[i - 1];
        while (x[i] - x[pre[i]] > d) ++pre[i];
    }
    nxt[n] = n;
    for (int i = n - 1; i; --i) {
        nxt[i] = nxt[i + 1];
        while (x[nxt[i]] - x[i] > d) --nxt[i];
    }

    vec<array<i64, 2>> f(n + 1), g(n + 1); // f 琛ㄧず i 涓嶆槸璧风偣锛実 琛ㄧず i 鏄捣鐐?
    for (int i = n; i; --i) {
        if (i == 1) f[i][0] = nxt[i] - i;
        else f[i][0] = nxt[i] - nxt[i - 1];
        if (nxt[i] > i && pre[nxt[i]] == i) f[i][0] += f[nxt[i]][0];
        g[i][0] = nxt[i] - i;
        if (nxt[i] > i) g[i][0] += f[nxt[i]][0];
        if (nxt[i] > i && pre[nxt[i]] == i) f[i][1] += f[nxt[i]][1];
        if (nxt[i] > i && nxt[nxt[i]] > nxt[i]) {
            int j = nxt[i], k = nxt[j];
            if (pre[k] == j - 1 && pre[j - 1] == i)
                f[i][1] += f[k][0];
        }
        if (nxt[i] > i + 1) {
            int j = nxt[i];
            if (pre[j - 1] == i)
                f[i][1] += nxt[j - 1] - nxt[j - 2];
        }
        if (nxt[i] > i) g[i][1] += f[nxt[i]][1];
        if (nxt[i] > i && nxt[nxt[i]] > nxt[i]) {
            int j = nxt[i], k = nxt[j];
            if (pre[k] == j - 1)
                g[i][1] += f[k][0];
        }
        if (nxt[i] > i + 1) {
            int j = nxt[i];
            g[i][1] += nxt[j - 1] - nxt[j - 2];
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i) ans += g[i][1];
    ouf << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false), inf.tie(nullptr);

    int c, t;
    inf >> c >> t;
    for (int cas = 1; cas <= t; ++cas) {
        solve();
    }

    ouf.flush();
    return 0;
}