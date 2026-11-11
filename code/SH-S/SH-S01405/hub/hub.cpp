#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5, M = 10, INF = 2e9;
int c, t, n, m, ans, cnt, maxu, maxdep, head[N], dep[N], pos[N], f[N], dist[M][M];
bool pv[N], vis[N];
struct node{
    int v, nxt;
}e[N << 1];
void add(int u, int v){
    e[++cnt] = (node){v, head[u]};
    head[u] = cnt;
}
void init(){
    for (int i = 1; i <= cnt; i++){
        e[i].v = e[i].nxt = 0;
    }
    for (int i = 1; i <= n; i++){
        head[i] = f[i] = dep[i] = 0;
    }
    cnt = 0, ans = INF;
}
void dfs_dep(int u, int fa){
    dep[u] = dep[fa] + 1;
    if (dep[u] > dep[maxu]){
        maxu = u, maxdep = dep[u];
    }
    for (int i = head[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if (v == fa){
            continue;
        }
        dfs_dep(v, u);
    }
}
void dfs(int u, int fa){
    f[u] = fa;
    for (int i = head[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
int dis(int u, int v){
    int res = 0;
    if (dep[u] < dep[v]){
        swap(u, v);
    }
    while (dep[u] > dep[v]){
        res++;
        u = f[u];
    }
    if (u == v){
        return res;
    }
    while (u != v){
        res += 2;
        u = f[u], v = f[v];
    }
    return res;
}
int calc(){
    int maxn = 0;
    for (int i = 1; i <= n; i++){
        int minn = 2e9;
        for (int j = 1; j <= m; j++){
            minn = min(minn, dist[i][pos[j]]);
        }
        maxn = max(maxn, minn);
    }
    return maxn;
}
void flood(int u){
    if (!vis[u]){
        vis[u] = true;
    }
    for (int i = head[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if (pv[v] && !vis[v]){
            flood(v);
        }
    }
}
bool check(){
    for (int i = 1; i <= n; i++){
        vis[i] = pv[i] = false;
    }
    for (int i = 1; i <= m; i++){
        pv[pos[i]] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        if (!vis[pos[i]]){
            cnt++;
            flood(pos[i]);
        }
    }
    return cnt <= 2;
}
void find(int k, int cnt){
    if (m - cnt > n - k + 1){
        return;
    }
    if (k == n + 1){
        if (cnt == m && check()){
            ans = min(ans, calc());
        }
        return;
    }
    find(k + 1, cnt);
    pos[cnt + 1] = k;
    find(k + 1, cnt + 1);
    pos[cnt + 1] = 0;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--){
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        if (c <= 3){
            dfs(1, 0);
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    dist[i][j] = dis(i, j);
                }
            }
            find(1, 0);
            printf("%d\n", ans);
            continue;
        }
        if (m == 2){
            maxu = 0, maxdep = 0;
            dfs_dep(1, 0);
            int p = maxu;
            maxu = 0;
            dep[p] = 0, maxdep = 0;
            dfs_dep(p, 0);
            printf("%d\n", maxdep / 4);
            continue;
        }
    }
}