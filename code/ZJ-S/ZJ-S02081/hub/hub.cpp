#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 5;
int n, K, fm[N], ans, deg[N], dis[N];
vector<int> e[N];

void process(int x, int y) {
    for (int i = 1; i <= n; ++i) {
        fm[i] = 0;
        for (const auto& j: e[i])
            fm[i] ^= j;
    }
    for (int i = 1; i <= n; ++i) deg[i] = (int)e[i].size();
    fm[x] ^= y; fm[y] ^= x; --deg[x]; --deg[y];

    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 1) { dis[i] = 1; Q.push(i); }

    int timer = n - K, res = 0;
    while (timer--) {
        int u = Q.front(); Q.pop();
        if (fm[u] == 0) { ++timer; continue; }
        res = dis[u];
        dis[fm[u]] = dis[u] + 1;
        --deg[fm[u]]; fm[fm[u]] ^= u;
        if (deg[fm[u]] == 1) Q.push(fm[u]);
    }
    ans = min(ans, res);
}

void solve() {
    read(n); read(K); ans = n + 1;
    for (int i = 1; i < n; ++i) {
        int u, v; read(u); read(v);
        e[u].push_back(v); e[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        for (const auto& j: e[i])
            if (i < j) process(i, j);
    printf("%d\n", ans);

    memset(fm + 1, 0, sizeof(int) * n);
    for (int i = 1; i <= n; ++i) e[i].clear();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int T; read(T); read(T);
    while (T--) solve();
    return 0;
}
