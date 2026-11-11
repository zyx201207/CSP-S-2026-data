#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e+6 + 6;
int ovo, T, n, d;
int a[maxn], nxt[maxn];
inline void GOGOGO() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[j] - a[i] <= d) j++;
        nxt[i] = j - 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = 0;
        int p = i + 1, nkh = nxt[i];
        // cerr << "i: " << i << " nxt[i]: " << nxt[i] << '\n';
        for (int j = nxt[nxt[i]]; j <= n; nkh = nxt[nkh], j = nxt[j]) {
            if (j == nkh) break;
            // cerr << "nkh: " << nkh << " j: " << j << " n: " << n << '\n';
            for (int k = nkh + 1; k <= j; k++) {
                while (p < nkh && a[k] - a[p] > d) p++;
                if (nkh - p == 0) {
                    if (flag) ans++;
                } else if (nkh - p == 1 && !flag) {
                    ans++;
                    if (k == j) flag = 1;
                } else if (k == j) goto oo;
            }
        }
        oo:;
    }
    cout << ans << '\n';
}
//inline void GOGO2() {
//    cin >> n >> d;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1, j = 1; i <= n; i++) {
//        while (j <= n && a[j] - a[i] <= d) j++;
//        nxt[i] = j - 1;
//    }
//    for (int i = n, j = n; i; i--) {
//        while (j && a[i] - a[j] <= d) j--;
//        pre[i] = j + 1;
////        cout << "i: " << i << " j: " << j << '\n';
//    }
//    int ans = 0, cnt = 0;
//    for (int i = nxt[1], j = 1; i != j; i = nxt[i], j = nxt[j]) {
//        cnt++;
//        for (int k = j + 1; k <= i; k++) mp[cnt][pre[k]]++;
//        L[cnt] = j + 1, R[cnt] = i + 1;
////        cout << "cnt: " << cnt << " L: " << L[cnt] << " R: " << R[cnt] << '\n';
//    }
//    for (int i = 1; i <= n; i++) {
//        bool flag = 0;
//        int nkh = nxt[i];
////        cout << "i: " << i << " pre[i]: " << pre[i] << '\n';
//        for (int j = nxt[nxt[i]], o = 2; j <= n; nkh = nxt[nkh], j = nxt[j], o++) {
//            if (j == nkh) break;
//            if (flag) ans += mp[o][nkh];
//            else ans += mp[o][nkh - 1];
////            cout << "j: " << j << " nkh: " << nkh << '\n';
//            if (nkh - pre[j] == 1) {
//                if (flag) break;
//                else flag = 1;
//            } else if (nkh - pre[j] > 1) break;
//        }
//        L[1]++;
//        for (int j = i, k = nxt[i], o = 1; j != k; j = nxt[j], k = nxt[k], o++) {
//            while (R[o] <= n && a[R[o]] - a[L[o] - 1] <= d) {
//                mp[o + 1][pre[R[o]]]--;
//                mp[o][pre[R[o]]]++;
//                R[o]++;
//                L[o + 1]++;
//            }
////            cout << "i: " << i << " o: " << o << " L[o]: " << L[o] << " R[o]: " << R[o] << '\n';
//        }
//    }
//    cout << ans << '\n';
//    for (int i = 1; i <= cnt; i++) mp[i].clear();
//}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> ovo >> T;
    while (T--) GOGOGO();
    return 0;
}

