#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7,INF=2e9;
int fa[N][27],dp[N],nxt[N],vis[N];
int c,t,n,m,ans;
vector<int>G[N];
void Init(){
    ans=INF;
    for(int i=1;i<=n;i++) G[i].clear();
}
void dfs(int u,int f){
    fa[u][0]=f;
    dp[u]=dp[f]+1;
    for(int i=1;i<=21;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v: G[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dp[u]<dp[v]) swap(u,v);
    for(int i=21;i>=0;i--) if((dp[u]-dp[v])&(1<<i)) u=fa[u][i];
    if(u==v) return u;
    for(int i=21;i>=0;i--) if(fa[u][i]!=fa[v][i]){
        u=fa[u][i];
        v=fa[v][i];
    }
    return fa[u][0];
}
int calc_dis(int u,int v){
    int f=lca(u,v);
    return dp[u]+dp[v]-(dp[f]<<1);
}
int find(int u){
    if(u==nxt[u]) return u;
    return nxt[u]=find(nxt[u]);
}
void Union(int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v) nxt[v]=u;
}
void solve(){
    scanf("%d%d",&n,&m);
    Init();
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<(1<<n);i++){
        int cnt=0;
        for(int j=1;j<=n;j++) if(i&(1<<(j-1))) cnt++;
        if(cnt!=m) continue;
        for(int j=1;j<=n;j++) vis[j]=(1&(i>>(j-1)));
        for(int j=1;j<=n;j++) nxt[j]=j;
        for(int j=1;j<=n;j++) for(int k: G[j]) if(vis[j]&&vis[k]) Union(j,k);
        cnt=0;
        for(int j=1;j<=n;j++) if(vis[j]&&j==find(j)) cnt++;
        if(cnt>2) continue;
        int mx=0;
        for(int j=1;j<=n;j++){
            int mn=INF;
            for(int k=1;k<=n;k++) if(vis[k]) mn=min(mn,calc_dis(j,k));
            mx=max(mx,mn);
        }
        ans=min(ans,mx);
    }
    printf("%d\n",ans);
}
void Files(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
}
int main(){
    Files();
    scanf("%d%d",&c,&t);
    while(t--) solve();
    return 0;
}
