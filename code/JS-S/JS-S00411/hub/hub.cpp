#include<bits/stdc++.h>
using namespace std;
const int A=1e6+5;
int n,k;
vector<int>g[A];
int f[A],d[A],son[A],top[A],siz[A];
int ff[A];
int find(int x){
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    f[u]=fa;
    int sonn=0;
    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[sonn]) sonn=v;
    }
    son[u]=sonn;
}
void dfs1(int u,int tp){
    top[u]=tp;
    if(son[u]){
        dfs1(son[u],tp);
    }
    for(int v:g[u]){
        if(v==son[u]||v==f[u]) continue;
        dfs1(v,v);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(d[x]<d[y]) swap(x,y);
        x=fa[top[x]];
    }
    return d[x]<d[y]?x:y;
}
void sol(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,1);
    for(int i=1;i<(1<<n);i++){
        for(int i=1;i<=n;i++) f[i]=i;
        int cnt=0;
        vector<int>aa;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
            cnt++;
            aa.push_back(j+1);
        }
        if(cnt!=k) continue;
        for(int i=1;i<aa.size();i++){
            for(int j=i+1;j<aa.size();j++){

            }
        }

    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout)
    int c,t;cin>>c>>t;
    while(t--){
        sol();
    }
    return 0;
}
