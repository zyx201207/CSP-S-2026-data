#include <bits/stdc++.h>
using namespace std;
const int N(1e6 + 5);
int n, m, C, T, f[N][25], e[N * 2], nxt[N * 2], head[N], tot, dep[N], lg, ans;
bool in[N];
inline void add(int u, int v){ e[++tot] = v, nxt[tot] = head[u], head[u] = tot;}
void dfs(int u, int fa){
    f[u][0] = fa, dep[u] = dep[fa] + 1;
    for(int i = 1; i <= lg; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for(int i = head[u]; i; i = nxt[i]){
        int v = e[i];
        if(v == fa) continue;
        dfs(v, u);
    }
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = lg; ~i; i--) if(dep[u] - (1 << i) >= dep[v]) u = f[u][i];
    if(u == v) return u;
    for(int i = lg; ~i; i--) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return f[u][0];
}
int dis(int u, int v){ return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
void fd(int u, int sum, int now){
    if(sum < m) return;
    if(u > n){
        if(sum == m && now == 2){
            int mx(0);
            for(int i = 1; i <= n; i++){
                if(in[i]) continue;
                int mn(1e9);
                for(int j = 1; j <= n; j++){
                    if(!in[j]) continue;
                    mn = min(mn, dis(i, j));
                }
                mx = max(mx, mn);
            }
            ans = min(ans, mx);
        }
        return;
    }
    fd(u + 1, sum, now);
    in[u] = 0;
    int cnt(-1);
    for(int i = head[u]; i; i = nxt[i]) if(in[e[i]]) cnt++;
    fd(u + 1, sum - 1, now + cnt);
    in[u] = 1;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &C, &T);
    while(T--){
        scanf("%d%d", &n, &m), tot = 0, lg = log2(n), ans = 1e9;
        for(int i = 1; i <= n; i++) head[i] = 0, in[i] = 1;
        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        dfs(1, 0);
        fd(1, n, 1);
        printf("%d\n", ans);
    }
    return 0;
}
