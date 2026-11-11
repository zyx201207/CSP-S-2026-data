#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read () {
    int x = 0, f = 1;
    char ch;
    ch = getchar_unlocked ();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar_unlocked ();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar_unlocked ();
    }
    return x * f;
}
inline void write (int x) {
    if (x < 0) {
        putchar_unlocked ('-');
        x = -x;
    }
    if (x >= 10)
        write (x / 10);
    putchar_unlocked ((x % 10 + '0'));
}
int n, m;
int a[1000010];
int lst[1000010];
int ans = 0;
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort (a + 1, a + n + 1);
    lst[0] = 0;
    for (int i = 1; i <= n; i++)
        lst[i] = lst[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            int now = lst[i] - lst[mid - 1];
            int tot = (i - mid + 1) * a[i];
            int sum = tot - now;
            if (sum <= m)
                r = mid;
            else
                l = mid;
        }
        int res = i - r + 1;
        ans = max (ans, res);
    }
    write (ans);
    putchar_unlocked('\n');
    return 0;
}
