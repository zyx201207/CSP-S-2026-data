#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

const int M = 10005, INF = 1e10;
int c, n, m, d, q;
ll w[M];
vector<pair<int, ll>> g[M];
ll dist[M][M];
ll dep[M], up[M][20], dis[M];

void dfs(int u, int fa, int w){
    dep[u] = dep[fa] + 1;
    dis[u] = dis[fa] + w;
    up[u][0] = fa;
    for(int j = 1;j < 20;j++){
        up[u][j] = up[up[u][j-1]][j-1];
    }
    for(auto p : g[u]){
        int v = p.first, w = p.second;
        if(v == fa) continue;
        dfs(v, u, w);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int j = 20;j >= 0;j--){
        if(dep[up[u][j]] >= dep[v]) u = up[u][j];
    }
    if(u == v) return u;
    for(int j = 20;j >= 0;j--){
        if(up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

int query(int u, int v){
    return dis[u] + dis[v] - dis[lca(u, v)] * 2;
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1;i <= m;i++) w[i] = read();
    for(int i = 1;i <= n + m;i++){
        for(int j = 1;j <= n + m;j++){
            if(i == j) dist[i][i] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 1+m;i <= n+m;i++){
        int k = read();
        for(int j = 0;j < k;j++){
            int a = read();
            ll t = read();
            g[a].push_back({i, t});
            g[i].push_back({a, t});
            dist[a][i] = dist[i][a] = t;
        }
    }
    if(c <= 6){
        for(int k = 1;k <= n + m;k++){
            for(int i = 1;i <= n + m;i++){
                for(int j = 1;j <= n + m;j++){
                    if(dist[i][k] >= INF / 2 || dist[k][j] >= INF / 2) continue;
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
        while(q--){
            int x = read(), y = read();
            cout << dist[x][y] + w[x] + w[y] << '\n';
        }
    }else if(c >= 7 && c <= 11){
        dfs(1, 0, 0);
        while(q--){
            int x = read(), y = read();
            cout << query(x, y) + w[x] + w[y] << '\n';
        }
    }
    return 0;
}
