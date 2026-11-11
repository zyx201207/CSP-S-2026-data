#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C,T,n,k,vis[105],fa[105][50],dep[105],ans=2e9;
vector<int> g[105];
void dfs0(int u,int f){
    fa[u][0]=f,dep[u]=dep[f]+1;
    for(int v:g[u]){
        if(v==f) continue;
        dfs0(v,u);
    }
    return;
}
int LCA(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=10;i;i--){
        if(dep[u]-dep[v]<=(1<<i)) u=fa[u][i];
    }
    if(u==v) return u;
    for(int i=10;i;i--){
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
void dfs(int step){
    if(step>k){
        int res=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0) continue;
            for(int j=1;j<=n;j++){
                if(vis[j]==1) continue;
                int dis=dep[i]+dep[j]-2*dep[LCA(i,j)];
                res=max(res,dis);
            }
        }
        ans=min(ans,res);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        dfs(step+1);
        vis[i]=0;
    }
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        memset(fa,0,sizeof fa);
        memset(dep,0,sizeof dep);
        ans=2e9;
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs0(1,0);
        for(int j=1;j<=10;j++){
            for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
