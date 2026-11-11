#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000200;
int ic, T, d, n;
int a[N], nxt[N], pre[N], vl[N], vr[N], tgl[N], tgr[N];
int b[N], t;
void solve() {
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i), tgl[i] = tgr[i] = 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (a[i] - a[j] > d) ++j;
        pre[i] = j;
    }
    for (int i = n, j = n; i >= 1; --i) {
        while (a[j] - a[i] > d) --j;
        nxt[i] = j;
    }
    for (int i = 1; i <= n; ++i) {
        int x = pre[i], y = nxt[i];
        if (x < i && nxt[x] >= i) ++tgr[x];
        if (y > i && pre[y] <= i) ++tgl[y];
    }
    for (int i = n; i >= 1; --i) {
        vr[i] = 1;
        if (i != nxt[i]) {
            vr[i] += tgr[i];
            if (pre[nxt[i]] == i) vr[i] += vr[nxt[i]] - 1;
        }
        tgr[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        vl[i] = 1;
        if (i != pre[i]) {
            vl[i] += tgl[i];
            if (nxt[pre[i]] == i) vl[i] += vl[pre[i]] - 1;
        }
        tgl[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int x = pre[i], y = nxt[i];
        if (x < i - 1 && nxt[x + 1] > i) ++tgr[x + 1];
        if (y > i + 1 && pre[y - 1] < i) ++tgl[y];
    }
    int ans = 0;
    for (int x = 2; x <= n; ++x) {
        int i = pre[x - 1], j = nxt[x];
        if (i == x - 1 || j == x) continue;
        int p = tgl[x], q = tgr[x];
        if (nxt[i] == x) p += vl[i];
        if (pre[j] == x - 1) q += vr[j];
        ans += p * q;
    }
    printf("%lld\n", ans);
    return;
}
signed main() {
    freopen("data.in", "r", stdin);
    freopen("wa.out", "w", stdout);
    scanf("%lld%lld", &ic, &T);
    while (T--) solve();
    return 0;
}