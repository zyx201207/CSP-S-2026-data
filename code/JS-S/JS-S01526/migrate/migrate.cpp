#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define il inline
#define rg register
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
const int N = 2000005;
const int INF = 0x7ffffffffff;

il int read() {
    short f = 1;
    int x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f *= (-1);
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = gc();
    }
    return x * f;
}

void wit(int x) {
    if (x == 0) return ;
    wit(x / 10);
    pc(x % 10 + '0');
    return ;
}

void write(int x, bool edl) {
    if (x <= 0) {
        if (x == 0) pc('0');
        else {
            pc('-');
            wit(x * (-1));
        }
    }
    else wit(x);
    if (edl) pc('\n');
    else pc(' ');
    return ;
}

int c, t, n, d, a[N], ans = 0, mi[N], s[N];

void dfs(int step, int lst) {
    if (mi[lst]) {
        if (step < mi[lst]) {
            mi[lst] = step;
            s[lst] = 1;
        }
        else if (step == mi[lst]) s[lst]++;
    }
    else {
        mi[lst] = step;
        s[lst] = 1;
    }
    for (int i = lst + 1; i <= n; i++) {
        if (a[i] - a[lst] <= d) dfs(step + 1, i);
        else break;
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    c = read(); t = read();
    if (c == 11 || c == 12) {
        while (t--) {
            n = read(); d = read();
            for (int i = 1; i <= n; i++) a[i] = read();
            if (d < a[3] - a[1] || (d / (a[2] - a[1]) * 2 - 1 >= n)) write(0, 1);
            else write(n - d / (a[2] - a[1]) * 2 + 1, 1);
        }
        return 0;
    }
    else {
        while (t--) {
            ans = 0;
            n = read(); d = read();
            for (int i = 1; i <= n; i++) a[i] = read();
            for (int i = 1; i < n; i++) {
                for (int i = 1; i <= n; i++) {
                    s[i] = 0;
                    mi[i] = INF;
                }
                dfs(0, i);
                for (int j = i + 2; j <= n; j++) {
                    if (s[j] == 2) ans++;
                }
            }
            write(ans, 1);
        }
    }
    
    return 0;
}
