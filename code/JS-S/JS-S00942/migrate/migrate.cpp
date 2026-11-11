#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, tt, n, d, a[2000005], lft[2000005], rgt[2000005], sum[2000005];
int nxtl[2000005], nxtr[2000005], nxtr_[2000005];
int f[2000005], g[2000005];
bool ok(int x, int y) {
    return abs(a[x] - a[y]) <= d;
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lft[i] = rgt[i] = sum[i] = nxtl[i] = nxtr[i] = 0;
        f[i] = g[i] = nxtr_[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int v;
        if (a[i] - a[1] <= d) {
            v = i;
            lft[i] = v;
            if (i != n) {
                int pos = lower_bound(a + 1, a + n + 1, a[i + 1] - d) - a;
                lft[i] = max(0ll, pos - 1) + 1;
            }
        } else {
            int pos = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
            v = i - pos + 1;
            lft[i] = v;
            if (i != n) {
                int pos2 = lower_bound(a + 1, a + n + 1, a[i + 1] - d) - a;
                lft[i] = max(1ll, pos2 - pos);
                if (a[i + 1] - a[i] <= d) {
                    lft[i]++;
                }
            }
            if (pos != i) {
                nxtl[i] = pos;
                //if we can jump to another lft point
                if (nxtl[pos] && (i == n || !ok(i + 1, nxtl[i]))) {
                    int ban = pos + 1;
                    if (!ok(ban, nxtl[pos])) {
                        f[i] += f[pos];
                    }
                    int v2 = nxtl[pos + 1];
                    int len = v2 - nxtl[pos];
                    f[i] += len;
                }
                // cout << i << "iii  " << f[i] << "\n";
                if (!ok(i + 1, nxtl[i])) {
                    // if (a[i] == 28) {
                    //     cout << "ok\n";
                    // }
                    int nxtt;
                    if (a[pos] - a[1] <= d) {
                        nxtt = 1;
                    } else {
                        nxtt = lower_bound(a + 1, a + n + 1, a[pos] - d) - a + 1;
                    }
                    if (nxtl[pos]) {
                        nxtt = max(nxtt, nxtl[pos] + 1);
                    }
                    int nxt2;
                    if (a[pos + 1] - a[1] <= d) {
                        nxt2 = 1;
                    } else {
                        nxt2 = lower_bound(a + 1, a + n + 1, a[pos + 1] - d) - a;
                    }
                    // if (a[i] == 63) {
                    //     cout << "qqqq " << nxt2 << " " << nxtt << "\n";
                    // }
                    f[i] += nxt2 - nxtt;
                }
            }
            lft[i] += f[i];
        }
    }
    for (int i = n; i >= 1; i--) {
        int v;
        if (a[n] - a[i] <= d) {
            v = n - i + 1;
            rgt[i] = v;
            if (i != n) {
                nxtr_[i] = n;
            }
            if (i != 1) {
                int p2 = upper_bound(a + 1, a + n + 1, a[i - 1] + d) - a - 1;
                rgt[i] = max(0ll, n - p2) + 1;
            }
        } else {
            int pos = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            v = pos - i + 1;
            rgt[i] = v;
            if (i != 1) {
                int p2 = upper_bound(a + 1, a + n + 1, a[i - 1] + d) - a - 1;
                rgt[i] = max(1ll, pos - p2);
                if (a[i] - a[i - 1] <= d) {
                    rgt[i]++;
                }
            }
            if (pos != i) {
                nxtr[i] = nxtr_[i] = pos;
                if (nxtr[pos] && (i == 1 || !ok(i - 1, nxtr[i]))) {
                    int ban = pos - 1;
                    if (!ok(ban, nxtr[pos])) {
                        g[i] += g[pos];
                    }
                    int v2 = nxtr[pos - 1];
                    g[i] += nxtr[pos] - v2;
                }
                if (!ok(i - 1, nxtr[i])) {
                    // if (a[i] == 28) {
                    //     cout << "ok\n";
                    // }
                    int nxtt;
                    if (a[n] - a[pos] <= d) {
                        nxtt = n;
                    } else {
                        nxtt = upper_bound(a + 1, a + n + 1, a[pos - 1] + d) - a - 1;
                    }
                    if (nxtr[pos]) {
                        nxtt = min(nxtt, nxtr[pos] - 1);
                    }
                    int nxt2;
                    if (a[n] - a[pos - 1] <= d) {
                        nxt2 = n;
                    } else {
                        nxt2 = upper_bound(a + 1, a + n + 1, a[pos - 1] + d) - a - 1;
                    }
                    // if (a[i] == 63) {
                    //     cout << "qqqq " << nxt2 << " " << nxtt << "\n";
                    // }
                    g[i] += nxtt - nxt2;
                }
            }
            rgt[i] += g[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        // lft[i]++, rgt[i]++;
        // cout << lft[i] << " " << rgt[i] << "\n";
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + rgt[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int v = nxtr[i];
        // cout << "# " << i << " " << v << " " << nxtr_[v] << "\n";
        if (!v || v == n) {
            continue;
        }
        if (v == i + 1) {
            continue;
        }
        // if (!ok(v - 1, nxtr_[v]) || ok(v - 2, nxtr_[v])) {
        //     continue;
        // }
        int okl, okr;
        if (v == i + 2) {
            int t = nxtr_[i + 1];
            okl = v + 1, okr = t;
        } else {
            okl = nxtr_[v - 2] + 1, okr = nxtr_[v - 1];
        }
        // cout << "## " << okl << " " << okr << "\n";
        ans += lft[i] * (sum[okr] - sum[okl - 1]);
        // cout <<  "ans " << ans << "\n";
    }
    cout << ans << "\n";
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/
/*
0 1
5 2
1 2 3 4 5
*/
/*
0 1
5 3
-3 0 2 3 4
*/
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/