#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2000005];
int L[2000005], R[2000005];
// int dp[2000005];
// int is[2000005];

int lst[2000005], nxt[2000005];


struct SG{
    struct node{
        int l1 = 0, l2 = 0;//fuzhi, jia
        int sum = 0;
    }tr[200005];
    void init(int x, int l, int r) {
        tr[x].l1 = tr[x].l2 = 0;
        if (l == r) {
            tr[x].sum = 1e9;
            return;
        }
        int m = (l + r) / 2;
        init(x << 1, l, m);
        init((x << 1) | 1, m + 1, r);
        tr[x].sum = tr[x << 1].sum + tr[(x << 1) | 1].sum;
        return;
    }
    void pushdown(int x, int l, int r) {
        int m = (l + r) / 2;
        if (tr[x].l1) {
            tr[x << 1].sum = (m - l + 1) * tr[x].l1;
            tr[x << 1].l1 = tr[x].l1;
            tr[(x << 1) | 1].sum = (r - m) * tr[x].l1;
            tr[(x << 1) | 1].l1 = tr[x].l1;
            tr[x].l1 = 0;
        }
        if (tr[x].l2) {
            tr[x << 1].sum += (m - l + 1) * tr[x].l2;
            tr[x << 1].l2 += tr[x].l2;
            tr[(x << 1) | 1].sum += (r - m) * tr[x].l2;
            tr[(x << 1) | 1].l2 += tr[x].l2;
            tr[x].l2 = 0;
        }
        return;
    }
    void change1(int x, int l, int r, int L, int R, int v) {
        if (L <= l && r <= R) {
            tr[x].sum += (r - l + 1) * v;
            tr[x].l2 += v;
            return;
        }
        pushdown(x, l, r);
        int m = (l + r) / 2;
        if (L <= m) {
            change1(x << 1, l, m, L, R, v);
        }
        if (R > m) {
            change1((x << 1) | 1, m + 1, r, L, R, v);
        }
        tr[x].sum = tr[x << 1].sum + tr[(x << 1) | 1].sum;
        return;
    }
    void change2(int x, int l, int r, int L, int R, int v) {
        if (L <= l && r <= R) {
            tr[x].sum = (r - l + 1) * v;
            tr[x].l1 = v;
            tr[x].l2 = 0;
            return;
        }
        pushdown(x, l, r);
        int m = (l + r) / 2;
        if (L <= m) {
            change2(x << 1, l, m, L, R, v);
        }
        if (R > m) {
            change2((x << 1) | 1, m + 1, r, L, R, v);
        }
        tr[x].sum = tr[x << 1].sum + tr[(x << 1) | 1].sum;
        return;
    }
    int ask(int x, int l, int r, int id) {
        if (l == r)return tr[x].sum;
        pushdown(x, l, r);
        int m = (l + r) / 2;
        if (id <= m)return ask(x << 1, l, m, id);
        return ask((x << 1) | 1, m + 1, r, id);
    }
    
}dp, is;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;cin >> c >> t;
    while (t--) {
        int n;ll d;
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            while (a[i] - a[l] > d) {
                l++;
            }
            while (r < n && a[r + 1] - a[i] <= d) {
                r++;
            }
            L[i] = l;R[i] = r;
        }
        int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 dp[j] = 1e9;
//                 is[j] = 1;
//             }
//             dp[i] = 0;
//             for (int j = i; j <= n; j++) {
//                 if (dp[j] >= 1e9)break;
// //                cout << i << " " << j << " " << dp[j] << "and" << is[j] << endl;
//                 is[j] = min(is[j], 3);
//                 if (is[j] == 2)ans++;
                
//                 for (int k = max(L[j], j + 1); k <= R[j]; k++) {
// //                    cout << dp[j] + 1 << "and" << dp[k] << endl;
//                     if (dp[j] + 1 < dp[k]) {
//                         dp[k] = dp[j] + 1;
//                         is[k] = is[j];
//                     }else if (dp[j] + 1 == dp[k]) {
//                         is[k] += is[j];
//                     }
//                 }
//             }
            
//         }
        for (int i = 1; i <= n; i++) {
            dp.init(1, 1, n);is.init(1, 1, n);
            for (int j = i; j <= n; j++) {
                int vdp, vis;
                if (j != i)vdp = dp.ask(1, 1, n, j);
                else vdp = 0;
                if (j != i)vis = is.ask(1, 1, n, j);
                else vis = 1;
                
                vis = min(vis, 3);
                if (vdp >= 1e9)break;
                if (vis == 2)ans++;
                
                //dp dizeng
                //erfen <kde
                int l = max(L[j], j + 1), r = R[j], tmp = R[j] + 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (vdp + 1 < dp.ask(1, 1, n, mid)) {
                        tmp = mid;
                        r = mid - 1;
                    }else {
                        l = mid + 1;
                    }
                }

                //qvjianfuzhi
                if (tmp <= R[j]) {
//                    cout << tmp << "**" << R[j] << endl;
                    dp.change2(1, 1, n, tmp, R[j], vdp + 1);
                    is.change2(1, 1, n, tmp, R[j], vis);
                }
                int tt = tmp - 1;
                l = max(L[j], j + 1), r = tmp - 1;
                tmp = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (vdp + 1 == dp.ask(1, 1, n, mid)) {
                        tmp = mid;
                        r = mid - 1;
                    }else {
                        l = mid + 1;
                    }
                }
                if (tmp != -1) {
                    is.change1(1, 1, n, tmp, tt, vis);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*

//                    cout << i << ":" << j << endl;
                    // if (j != i) {
                    //     if (dp[j] == dp[j - 1]) {
                    //         for (int k = j + 1; k <= R[j - 1]; k++) {
                    //             is[k] = 1;
                    //         }
                    //         for (int k = R[j - 1] + 1; k <= R[j]; k++) {
                    //             dp[k] = dp[j] + 1;
                    //             is[k] = 0;
                    //         }
                    //     }else {
                    //         for (int k = R[j - 1] + 1; k <= R[j]; k++) {
                    //             dp[k] = dp[j] + 1;
                    //             is[k] = 0;
                    //         }
                    //     }
                    // }else {
                    //     for (int k = i + 1; k <= R[j]; k++) {
                    //         dp[k] = dp[j] + 1;
                    //         is[k] = 0;
                    //     }
                    // }

*/