#include <cstdio>
#include <vector>
#define db(x...) fprintf(stdout, x)
const int N = 1000005;
std::vector < int > e[N];
int n, m;
int c;
int fla[N];
int fa[N];
int dis[1005][1005];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int check() {
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) {
        if(!fla[i]) continue;
        for(int j : e[i]) {
            if(!fla[j]) continue;
            if(find(i) == find(j)) continue;
            fa[find(j)] = find(i);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(fla[i] && fa[i] == i) cnt++;
    }
    // for(int i = 1; i <= n; i++) if(fla[i]) db("%d ", i);
    // db(": %d\n", cnt);
    if(cnt > 2) return 0;
    return 1;
}
int getans() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(fla[i]) continue;
        int tans = n;
        for(int j = 1; j <= n; j++) {
            if(!fla[j]) continue;
            tans = std::min(tans, dis[i][j]);
        }
        ans = std::max(ans, tans);
    }
    // for(int i = 1; i <= n; i++) if(fla[i]) db("%d ", i);
    // db(": %d\n", ans);
    return ans;
}
int Ans;
void dfs(int x, int lst) {
    if(x == n + 1) {
        if(check() && !lst) Ans = std::min(Ans, getans());
        return ;
    }
    fla[x] = 0;
    dfs(x + 1, lst);
    if(lst) {
        fla[x] = 1;
        dfs(x + 1, lst - 1);
    }
}
void dfs(int u, int fath, int rt, int h) {
    dis[rt][u] = h;
    for(int v : e[u]) {
        if(v == fath) continue;
        dfs(v, u, rt, h + 1);
    }
}
void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if(n == m) {
        puts("0");
        return ;
    }
    if(c == 13 || c == 14) {
        int t = ((n + 1) >> 1) - 1;
        if(m <= t) {
            printf("%d\n", (n - t + 3) / 4 + 1);
        } else {
            puts("1");
        }
        return ;
    }
    for(int i = 1; i <= n; i++) dfs(i, 0, i, 0);
    Ans = n;
    dfs(1, m);
    printf("%d\n", Ans);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T;
    scanf("%d%d", &c, &T);
    while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}