#include <bits/stdc++.h>
using ll = long long;

const int Siz = 1 << 25;
char gbuf[Siz], *gpos = gbuf + Siz;
char gc() {
    if (gpos == gbuf + Siz) { fread(gbuf, 1, Siz, stdin); gpos = gbuf; }
    return *(gpos++);
}

template<typename T>
void read(T &x) {
    x = 0; char c = gc(); int r = 1;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') { r = -1; c = gc(); }
    while (isdigit(c)) { x = x * 10 + c - '0'; c = gc(); }
    x *= r;
}

const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    read(n); read(m);
    for (int i = 1; i <= n; ++i) read(a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    int ans = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        while (a[i] * (i - j) - (s[i] - s[j]) > m) ++j;
        ans = std::max(ans, i - j);
    }
    printf("%d\n", ans);
    return 0;
}
