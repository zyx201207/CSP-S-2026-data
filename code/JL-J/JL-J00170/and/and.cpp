#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5, l = 30;
struct Number {
    int val, bbl = 0;
    friend bool operator < (const Number &l, const Number &r) {
        if (l.bbl == r.bbl)
            return l.val > r.val;
        return l.bbl > r.bbl;
    }
} s[N];
int n, m, f[N], a[N], ans = 0;

inline int pow31(int k = 1) {
    for (int i = 1; i <= 31; i++)
        k *= 2;
    return k - 1;
}

inline bool check1() {
    for (int i = 1; i <= n; i++)
        if (a[i] != i - 1)
            return false;
    return true;
}

inline int idxxx() {
    int k = pow31() + 1;
    for (int i = 31; i; i--, k /= 2) {
        if (n >= k)
            return k;
    }
    return -1;
}

inline void dfs(int i, int cnt, int sum) {
    if (cnt == m) {
        ans = max(ans, sum);
        return;
    }
    if (i > n)
        return;
    dfs(i + 1, cnt, sum);
    dfs(i + 1, cnt + 1, sum & a[i]);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1) {
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
        cout << ans << '\n';
        return 0;
    }
    if (m == 2) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = max(a[i] & a[j], ans);
        cout << ans << '\n';
        return 0;
    }
    if (m == n) {
        ans = pow31();
        for (int i = 1; i <= n; i++)
            ans &= a[i];
        cout << ans << '\n';
        return 0;
    }
    if (check1()) {
        ans = idxxx() - m;
        cout << ans << '\n';
        return 0;
    }
    if (n <= 20) {
        dfs(1, 0, pow31());
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        s[i].val = a[i];
        for (int j = 0; j <= l; j++)
            if ((s[i].val >> j) & 1)
                s[i].bbl++;
    }
    sort(s + 1, s + 1 + n); ans = pow31();
    for (int i = 1; i <= m; i++)
        ans &= s[i].val;
    cout << ans << '\n';
    return 0;
}
// 10:17 为什么我把暴力打完了之后写了个骗分代码过大样例了？