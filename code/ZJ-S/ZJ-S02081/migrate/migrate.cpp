#include <bits/stdc++.h>
using ll = long long;

const int Siz = 1 << 25;
char gbuf[Siz], *gpos = gbuf + Siz, pbuf[Siz], *ppos = pbuf, stk[100];
char gc() {
    if (gpos == gbuf + Siz) { fread(gbuf, 1, Siz, stdin); gpos = gbuf; }
    return *(gpos++);
}
void pc(const char &c) {
    if (ppos == pbuf + Siz) { fwrite(pbuf, 1, Siz, stdout); ppos = pbuf; }
    *(ppos++) = c;
}

template<typename T>
void read(T &x) {
    x = 0; char c = gc(); int r = 1;
    while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') { r = -1; c = gc(); }
    while (isdigit(c)) { x = x * 10 + c - '0'; c = gc(); }
    x *= r;
}

void write(ll x) {
    if (x == 0) { pc('0'); return; }
    char *tp = stk;
    while (x) { *(tp++) = char(x % 10) + '0'; x /= 10; }
    while (tp != stk) pc(*(--tp));
}

const int N = 2e6 + 5;
int n, le[N], ri[N], f0[N], f1[N], g0[N], g1[N];
ll d, p[N];

void solve() {
    read(n); read(d);
    for (int i = 1; i <= n; ++i) read(p[i]);

    int t = 1;
    for (int i = 1; i <= n; ++i) {
        while (p[i] - p[t] > d) ++t;
        le[i] = t;
    }
    t = n;
    for (int i = n; i >= 1; --i) {
        while (p[t] - p[i] > d) --t;
        ri[i] = t;
    }

    le[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        f0[i] = (le[i + 1] > i ? i : le[i + 1]) - le[i];
        g0[i] = 0; if (f0[i]) g0[i] = f0[i] + g0[le[i]];
    }
    for (int i = n; i >= 1; --i) {
        f1[i] = ri[i] - (ri[i - 1] < i ? i : ri[i - 1]);
        g1[i] = 0; if (f1[i]) g1[i] = f1[i] + g1[ri[i]];
    }

    ll ans = 0;
    for (int i = 2; i <= n - 2; ++i) {
        if (p[i + 1] - p[i] > d) continue;
        int h0 = (le[i + 2] > i ? i : le[i + 2]) - le[i + 1];
        int h1 = ri[i] - (ri[i - 1] < i + 1 ? i + 1 : ri[i - 1]);
        if (h0 < 1 || h1 < 1) continue;

        int tmp0 = h0 + (f0[i] == 0 ? g0[le[i + 1]] : 0);
        int tmp1 = h1 + (f1[i + 1] == 0 ? g1[ri[i]] : 0);
        ans += 1ll * tmp0 * tmp1;
    }
    write(ans); pc('\n');
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int T; read(T); read(T);
    while (T--) solve();
    fwrite(pbuf, 1, ppos - pbuf, stdout); return 0;
}
