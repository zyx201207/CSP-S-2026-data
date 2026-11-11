#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int u[N], v[N], flag[N], fa[N], f[N], dep[N];
vector<int>g[N];
int n, k, ans = 1e9, inf = 1e9; 
int getd(int x, int y) {
    int res = 0;
    if(dep[x] > dep[y]) swap(x, y);
    while(dep[y] > dep[x]) {
        res++;
        y = fa[y];
    }
    while(x != y) {
        res += 2;
        x = fa[x]; y = fa[y];
    }
    // printf("%d %d %d\n", x, y, res);
    return res;
}
int father(int x) {
    return x == f[x] ? x : f[x] = father(f[x]);
}
void combine(int x, int y) {
    int fx = father(x), fy = father(y);
    f[fx] = fy;
}
void cal() {
    int res = 0;    
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i < n; i++) {
        if(flag[u[i]] && flag[v[i]]) combine(u[i], v[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        // if(flag[2] == 1 && flag[3] == 1 && flag[6] == 1 && flag[8] == 1 && flag[4] == 1 && flag[5] == 1) printf("%d %d\n", i, father(i));
        if(father(i) == i && flag[i]) cnt++;
    } 
    if(cnt >= 3) return;
    for(int i = 1; i <= n; i++) {
        if(flag[i]) continue;
        int mn = inf;
        for(int j = 1; j <= n; j++) {
            if(!flag[j]) continue;
            // printf("%d %d\n", i, j);
            mn = min(mn, getd(i, j));
            // if(flag[2] == 1 && flag[3] == 1 && flag[6] == 1 && flag[8] == 1 && flag[4] == 1 && flag[5] == 1) printf("%d %d %d\n", i, j, getd(i, j));
            // printf("%d %d %d\n", i, j, res);
            // printf("%d %d\n", i, j);
        }
        res = max(res, mn);
    }
    // printf("%d\n", res);
    ans = min(ans, res);
}
void dfs(int dep, int rem) {
    if(dep == n + 1) {
        if(rem == 0) cal();
        return;
    }
    if(rem > 0) {
        flag[dep] = 1;
        dfs(dep + 1, rem - 1);
    }
    flag[dep] = 0;
    dfs(dep + 1, rem);
}
void dfs2(int now, int las) {
    fa[now] = las; dep[now] = dep[las] + 1;
    for(int nxt : g[now]) {
        if(nxt == las) continue;
        dfs2(nxt, now);
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t; scanf("%d%d", &c, &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            flag[i] = 0; fa[i] = 0; dep[i] = 0;
            g[i].clear();
            ans = inf;
        }
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u[i], &v[i]);
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
        // printf("---\n");
        dfs2(1, 0);
        // printf("---\n");
        dfs(1, k);
        printf("%d\n", ans);
    }
}