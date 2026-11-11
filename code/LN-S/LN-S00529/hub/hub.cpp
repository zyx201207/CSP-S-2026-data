#include<bits/stdc++.h>
#define FILE "hub"
using namespace std;

namespace FakeWilson {
const int N = 105;
int head[N], f[N], dis[N][N];
int cnt;

struct Edge {
    int to, next;
} e[N << 1];

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u) {
    f[u] = false;
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(f[v]) dfs(v);
    }
}

void getDis(int rt, int u, int tar, int fa, int cur) {
    if(u == tar) dis[rt][tar] = cur;
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa) continue;
        getDis(rt, v, tar, u, cur + 1);
    } 
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k), cnt = 0;
    for(int i = 1; i <= n; i++) head[i] = 0;
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    int ans = 1e9;
    for(int S = 0; S < (1 << n); S++) {
        if(__builtin_popcount(S) != k) continue;
        for(int i = 0; i < n; i++) {
            if(S >> i & 1) f[i + 1] = true;
            else f[i + 1] = false;
        }
        int num = 0;
        for(int i = 1; i <= n; i++) if(f[i]) dfs(i), num++;
        if(num > 2) continue;
        for(int i = 0; i < n; i++) {
            if(S >> i & 1) f[i + 1] = true;
            else f[i + 1] = false;
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            int mn = 10000;
            for(int j = 1; j <= n; j++) {
                getDis(i, i, j, 0, 0);
                if(f[j]) mn = min(mn, dis[i][j]);
            }
            mx = max(mx, mn);
        }
        ans = min(ans, mx);
    }
    printf("%d\n", ans);
}

signed main() {
    int c, T;
    scanf("%d%d", &c, &T);
    while(T--) solve();
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}
