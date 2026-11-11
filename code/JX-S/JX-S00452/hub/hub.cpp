#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
const int LG = 8;
int c, T;
int n, k;
vector<int> e[N];
int Fa[N][LG], dep[N];
int fa[N];
bool jz[N];
void dfs1(int u, int f){
    dep[u] = dep[f] + 1;
    Fa[u][0] = f;
    for(int i = 1; i < LG; i++){
        Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
    }
    for(int v : e[u]){
        if(v == f) continue;
        dfs1(v, u);
    }
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = LG - 1; i >= 0; i--){
        if(dep[Fa[u][i]] >= dep[v]){
            u = Fa[u][i];
        }
    }
    if(u == v) return u;
    for(int i = LG - 1; i >= 0; i--){
        if(Fa[u][i] != Fa[v][i]){
            u = Fa[u][i];
            v = Fa[v][i];
        }
    }
    return Fa[u][0];
}
int find(int x){ return (x == fa[x] ? x : fa[x] = find(fa[x])); }
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return ;
    fa[u] = v;
}
void dfs2(int u, int f){
    for(int v : e[u]){
        if(v == f || !jz[v]) continue;
        merge(u, v);
        dfs2(v, u);
    }
}
int dist(int x, int y){ return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    int ans = 1e9;
    for(int msk = 0; msk < (1 << n); msk++){
        if(__builtin_popcount(msk) != k) continue;
        for(int i = 1; i <= n; i++) jz[i] = false;
        for(int i = 1; i <= n; i++){
            if(msk >> (i - 1) & 1) jz[i] = true;
        }
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n; i++){
            if(jz[i] && fa[i] == i) dfs2(i, -1);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += (jz[i] && fa[i] == i);
        if(cnt > 2) continue;
        int uans = 0;
        for(int i = 1; i <= n; i++){
            if(jz[i]) continue;
            int uuans = 1e9;
            for(int j = 1; j <= n; j++){
                if(jz[j]) uuans = min(uuans, dist(i, j));
            }
            uans = max(uans, uuans);
        }
        ans = min(uans, ans);
    }
    cout << ans << '\n';
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
