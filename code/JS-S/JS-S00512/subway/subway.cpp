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
inline void write (long long x) {
    if (x < 0) {
        putchar_unlocked ('-');
        x = -x;
    }
    if (x >= 10)
        write (x / 10);
    putchar_unlocked ((x % 10 + '0'));
}
int trash, n, m, q;
int w[1000010];
vector <pair <int, int>> e[1000010];
long long d[1000010];
long long s[510][510];
const long long INF = 2e18;
priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> p;
int l;
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    trash = read();
    n = read ();
    m = read ();
    trash = read ();
    q = read ();
    for (int i = 1; i <= m; i++)
        w[i] = read ();
    for (int i = 1; i <= n; i++) {
        l = read ();
        for (int j = 1; j <= l; j++) {
            int x, y;
            x = read ();
            y = read ();
            e[m + i].push_back ({x, y});
            e[x].push_back ({m + i, y});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                s[i][j] = INF;
    for (int i = 1; i <= n; i++) {
        int x = m + i;
        for (int j = 1; j <= n + m; j++)
            d[j] = INF;
        for (auto y : e[x])
            d[y.first] = y.second;
        for (int j = 1; j <= n; j++)
            for (auto y : e[m + j])
                s[i][j] = min (s[i][j], y.second + d[y.first]);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                s[i][j] = min (s[i][k] + s[k][j], s[i][j]);
    while (q--) {
        int x, y;
        x = read ();
        y = read ();
        long long ans = INF;
        for (auto i : e[x]) {
            for (auto j : e[y]) {
                long long shake = s[i.first - m][j.first - m] + i.second + j.second;
                ans = min (ans, shake);
            }
        }
        long long tot = ans + w[x] + w[y];
        write (tot);
        putchar_unlocked ('\n');
    }
    return 0;
}
