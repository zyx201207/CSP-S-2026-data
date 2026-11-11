#include <bits/stdc++.h>
using ll = long long;
using namespace std;

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

const int N = 505, M = 5e5 + 5;
int n, m, q;
ll w0[M], f[N][N];
vector<pair<int, ll>> e[M];

void ckmn(ll &x, ll y) { if (y < x) x = y; }

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int tmp;
    read(tmp); read(n); read(m); read(tmp); read(q);
    for (int i = 1; i <= m; ++i) read(w0[i]);
    for (int i = 1; i <= n; ++i) {
        int k; read(k);
        for (int j = 1; j <= k; ++j) {
            int x; ll t; read(x); read(t);
            e[x].emplace_back(i, t);
        }
    }

    memset(f, 0x0f, sizeof(f));
    for (int i = 1; i <= n; ++i) f[i][i] = 0;
    for (int i = 1; i <= m; ++i)
        for (const auto& tmp0: e[i]) {
            int x; ll t0; tie(x, t0) = tmp0;
            for (const auto& tmp1: e[i]) {
                int y; ll t1; tie(y, t1) = tmp1;
                ckmn(f[x][y], t0 + t1);
            }
        }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                ckmn(f[i][j], f[i][k] + f[k][j]);

    while (q--) {
        int u, v; read(u); read(v);
        ll ans = 1e18;
        for (const auto& tmp0: e[u]) {
            int x; ll t0; tie(x, t0) = tmp0;
            for (const auto& tmp1: e[v]) {
                int y; ll t1; tie(y, t1) = tmp1;
                ckmn(ans, f[x][y] + t0 + t1);
            }
        }
        write(ans + w0[u] + w0[v]); pc('\n');
    }
    fwrite(pbuf, 1, ppos - pbuf, stdout); return 0;
}
