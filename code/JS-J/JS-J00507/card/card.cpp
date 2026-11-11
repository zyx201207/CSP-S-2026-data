#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    if (x > 9)
        write (x / 10);
    putchar_unlocked ((x % 10 + '0'));
}
int n, m;
int a[500010];
int p[500010];
vector <int> f[500010];
int ans[500010];
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = n; i >= 1; i--) {
        if (p[a[i]] == 0) {
            f[i] = f[i + 1];
            f[i].push_back (a[i]);
            p[a[i]] = i;
        }
        else {
            f[i] = f[p[a[i]] + 1];
            f[i].push_back (a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (auto y : f[i])
            ans[y]++;
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
