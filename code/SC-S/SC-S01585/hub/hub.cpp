#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e6 + 10;
int c,t,n,k,ans,dep[N],depmn[N],fa[N];
vector<int> e[N];
bool vis[N];
inline int read(){
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
    return x;
}
int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x = find(x),y = find(y);
    fa[x] = y;
}
int dfs(int u,int fa,int mx){
    dep[u] = dep[fa] + 1;
    if(vis[u]) depmn[u] = dep[u];
    else depmn[u] = INF;
    int cnt = 0;
    for(int v : e[u]){
        if(v == fa) continue;
        if(vis[u]) cnt = max(cnt,dfs(v,u,dep[u]));
        else cnt = max(cnt,dfs(v,u,mx));
        depmn[u] = min(depmn[u],depmn[v]);
    }
    if(vis[u]) return cnt;
    return max(cnt,min(depmn[u] - dep[u],dep[u] - mx));
}
void getans(int x,int sum){
    if(sum > k) return;
    if(x > n){
        if(sum != k) return;
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int i = 1;i <= n;i++)
            for(int v : e[i])
                if(vis[i] && vis[v]) merge(i,v);
        int sum = 0;
        for(int i = 1;i <= n;i++)
            if(fa[i] == i && vis[i]) sum++;
        if(sum > 2) return;
        ans = min(ans,dfs(1,0,-INF));
        return;
    }
    getans(x + 1,sum);
    vis[x] = 1;
    getans(x + 1,sum + 1);
    vis[x] = 0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c = read(),t = read();
    while(t--){
        n = read(),k = read();
        for(int i = 1;i <= n;i++) e[i].clear();
        for(int i = 1,u,v;i < n;i++){
            u = read(),v = read();
            e[u].push_back(v),e[v].push_back(u);
        }
        ans = INF,getans(1,0);
        cout << ans << "\n";
    }
    return 0;
}
