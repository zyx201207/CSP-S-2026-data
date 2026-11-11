#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n,k,ans;
vector<int> g[N];
bool vis[N];
int dist[N];
void init(){
    for (int i = 0;i < n;i++){
        g[i].clear();
    }
}
void dfs(int u,int f,int mask){
    vis[u] = true;
    for (int v : g[u]){
        if (v == f || !(mask >> v & 1)) continue;
        dfs(v,u,mask);
    }
    return ;
}
void dfs2(int u,int f){
    dist[u] = min(dist[u],dist[f] + 1);
    for (int v : g[u]){
        if (v == f) continue;
        dfs2(v,u);
    }
}
void solve(){
    ans = 0x3fffffff;
    scanf("%d%d",&n,&k),init();
    for (int i = 1,u,v;i < n;i++){
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int mask = 0;mask < (1 << n);mask++){
        if (__builtin_popcount(mask) != k) continue;
        for (int i = 0;i < n;i++) vis[i] = false;
        int cnt = 0;
        for (int i = 0;i < n;i++){
            if ((mask >> i & 1) && !vis[i]){
                dfs(i,-1,mask),cnt++;
            }
        }
        if (cnt > 2) continue;
        for (int i = 0;i < n;i++){
            if (mask >> i & 1) dist[i] = 0;
            else dist[i] = 0x3fffffff;
        }
        for (int i = 0;i < n;i++){
            if (mask >> i & 1) dfs2(i,0);
        }
        int res = 0;
        for (int i = 0;i < n;i++) res = max(res,dist[i]);
        ans = min(ans,res);
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if (c <= 3){
        while(t--) solve();
    }
    return 0;
}