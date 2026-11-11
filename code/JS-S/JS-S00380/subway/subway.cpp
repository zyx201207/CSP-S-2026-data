#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i, a, b) for(int i = (a);i <= (b);++i)
#define _For(i, a, b) for(int i = (a);i >= (b);--i)
const int maxm = 5e5 + 5, maxn = 5e2 + 5, maxq = 1e5 + 5, maxx = maxm + maxn;
int c, n, m, d, q, k, x, y, cur = 0;
int w[maxm];
int fa[maxx], top[maxx], dep[maxx], son[maxx], siz[maxx];
int dis[maxx];

struct Edge{
    int to, nxt, w;
}e[maxm << 2];
int head[maxx], tot = 0, pcnt;

il void add_edge(int u, int v, int w){
    ++tot;
    e[tot].to = v;
    e[tot].w = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}

il void dfs1(int u, int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    for(int i = head[u], v;i;i = e[i].nxt){
        v = e[i].to;
        if(v != f){
            dis[v] = dis[u] + e[i].w;
            dfs1(v, u);
            if(siz[v] > siz[son[u]])  son[u] = v;
        }
    }
}

il void dfs2(int x, int topx){
    top[x] = topx;
    if(!son[x])  return ;
    dfs2(son[x], topx);
    for(int i = head[x], y;i;i = e[i].nxt){
        y = e[i].to;
        if(y != son[x] && y != fa[x])  dfs2(y, y);
    }
}

il int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]])  swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    pcnt = m;
    For(i, 1, m)  cin>>w[i];
    For(i, 1, n){
        cin>>k;
        ++pcnt;
        For(j, 1, k){
            cin>>x>>y;
            add_edge(pcnt, x, y);
            add_edge(x, pcnt, y);
        }
    }
    dfs1(1, 0);
    dfs2(1, 1);
    For(i, 1, q){
        cin>>x>>y;
        int lca = LCA(x, y);
        cout<<(dis[x] + dis[y] - (dis[lca] * 2)) + w[x] + w[y]<<'\n';
    }
    return 0;
}
