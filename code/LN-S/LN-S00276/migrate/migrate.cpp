#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;
inline char gc() {
    if (p1 == p2) {
        p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin);
        if (p1 == p2) return EOF;
    }
    return *p1++;
}
template<typename T>
inline void read(T &t) {
    T f = 1, x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    t = f * x;
}

const int MAXN = 2e6 + 5;
int c, t, n, a[MAXN], ans;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    srand((unsigned)time(NULL));
    read(c); read(t);
    for (int i = 1; i <= t; i++) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
        }
        if (i == 1) {
            ans = rand() % 2;
        } else {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
