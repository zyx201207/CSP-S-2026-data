#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0, flg = 0;
    char c = getchar();
    while (!isdigit(c)) {
        flg |= c == '-';
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return flg ? -x : x;
}
inline void write(int x, char div = '\n') {
    if (!x) {
        putchar('0'), putchar(div);
        return;
    }
    string s = "";
    if (x < 0) {
        putchar('-'), x = -x;
    }
    while (x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    for (char c : s) {
        putchar(c);
    }
    putchar(div);
}
namespace Sub11_12 {
    const int N = 2e6 + 5;
    int n, k, ans;
    int a[N];
    void solve() {
        n = read(), k = read(), ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        if (n == 1) {
            puts("0");
            return;
        }
        int d = a[2] - a[1];
        if (k / d <= 1) {
            ans = 0;
        } else {
            ans = max(ans, n - 2 * (k / d) + 1);
        }
        write(ans);
    }
}
namespace Sub {
    const int N = 5e3 + 5;
    const int inf = 1e18;
    int n, k, ans;
    int a[N];
    int l[N], r[N];
    int f[N][N], g[N][N];
    void solve() {
        n = read(), k = read(), ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        l[1] = 1;
        for (int i = 1, j = 1; i <= n; i++) {
            while (j + 1 <= n && a[j + 1] - a[i] <= k) {
                j++;
                l[j] = i;
            }
            r[i] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                f[i][j] = inf;
                g[i][j] = 0;
            }
            f[i][i] = 0;
        }
        for (int i = 1, j; i <= n; i++) {
            for (int len = 2; i + len - 1 <= n; len++) {
                j = i + len - 1;
                if (r[i] >= j) {
                    f[i][j] = 0;
                } else {
                    for (int l = i + 1; l <= r[i]; l++) {
                        f[i][j] = min(f[i][j], f[l][j] + 1);
                    }
                    for (int r = l[j]; r <= j - 1; r++) {
                        f[i][j] = min(f[i][j], f[i][r] + 1);
                    }
                    for (int l = i + 1; l <= r[i]; l++) {
                        g[i][j] += f[i][j] == f[l][j] + 1;
                    }
                    for (int r = l[j]; r <= j - 1; r++) {
                        g[i][j] += f[i][j] == f[i][r] + 1;
                    }
                }
                ans += g[i][j] == 2;
            }
        }
        write(ans);
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int subtasks = read(), T = read();
    while (T--) {
        if (subtasks >= 11 && subtasks <= 12) {
            Sub11_12::solve();
        } else {
            Sub::solve();
        }
    }
    return 0;
}
