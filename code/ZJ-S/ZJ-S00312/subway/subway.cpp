#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
int c, n, m, d, q, cnt;
int val[N];
struct Node{
    int u, v, w;
} a[N];
int tot;
int fa[N];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return ;
    fa[v] = u;
}
vector <pair <int, int> > G[N];
int dis[N], sz[N], pa[N], dep[N], son[N], top[N];
void dfs1(int u){
    sz[u] = 1, son[u] = -1;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].first, w = G[u][i].second;
        if(v == pa[u]) continue;
        pa[v] = u, dep[v] = dep[u] + 1, dis[v] = dis[u] + w;
        dfs1(v);
        sz[u] += sz[v];
        if(son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int tp){
    top[u] = tp;
    if(son[u] != -1) dfs2(son[u], tp);
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].first, w = G[u][i].second;
        if(v == son[u] || v == pa[u]) continue;
        dfs2(v, v);
    }
}
int lca(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = pa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
#define query(u, v) (dis[u] + dis[v] - 2 * dis[lca(u, v)] + val[u] + val[v])
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q, cnt = m;
    for(int i = 1; i <= m; ++i) cin >> val[i];
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k, ++cnt;
        for(int j = 1; j <= k; ++j){
            int v, w;
            cin >> v >> w;
            a[++tot] = {cnt, v, w};
        }
    }
    std::sort(a + 1, a + tot + 1, [](const Node &x, const Node &y){
        return x.w < y.w;
    });
    for(int i = 1; i <= tot; ++i) fa[i] = i;
    for(int i = 1; i <= tot; ++i){
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if(find(u) != find(v)){
            merge(u, v);
            G[u].emplace_back(v, w), G[v].emplace_back(u, w);
        }
    }
    int rt = find(1);
    dfs1(rt), dfs2(rt, rt);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }
    return 0;
}
