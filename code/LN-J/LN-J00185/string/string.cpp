#include <bits/stdc++.h>

using namespace std;

#define int long long
#define up(i, a, b) for(int i = a;i <= b; i++)

const int N = 2e5 + 101;
int n, a[N];
char c[N];

inline void solve(){
    cin >> n;
    up (i, 1, n) {
        cin >> a[i];
        cin >> c[i];
    }
    int l = 1, r = n, ans = 0, rlen = 0, llen = 0;
    while (l <= r) {
        int lint = a[l] - llen;
        int rint = a[r] - rlen;
        int minlen = min(lint, rint);
        if (c[l] != c[r]) ans += minlen;
        // 如果我希望确实可以实现的话
        llen += minlen;
        rlen += minlen;
        if (lint == minlen) {
            l ++;
            llen = 0;
        } if (rint == minlen) {
            r --;
            rlen = 0;
        }
        // cout << l << ' ' << r << ' ' << llen << ' ' << rlen << ' ' << minlen << '\n';
    }
    cout << ans << '\n';
}
signed main () {
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
    return 0;
    // CSP AK!!!
}
