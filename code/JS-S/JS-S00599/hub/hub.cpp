#include<bits/stdc++.h>
using namespace std;

int C,T;

int n,k;
vector<int>e[1000010];

int dep[100010],anc[100010][30];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    anc[x][0]=fa;
    for(int j=1;j<=20;++j){
        anc[x][j]=anc[anc[x][j-1]][j-1];
    }
    for(auto i:e[x]){
        if(i==fa){
            continue;
        }
        dfs(i,x);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    for(int j=20;j>=0;--j){
        if(dep[anc[u][j]]>=dep[v]){
            u=anc[u][j];
        }
    }
    if(u==v){
        return u;
    }
    for(int j=20;j>=0;--j){
        if(anc[u][j]!=anc[v][j]){
            u=anc[u][j];
            v=anc[v][j];
        }
    }
    return anc[u][0];
}
int lenth(int u,int v){
    int l=lca(u,v);
    return dep[u]-dep[l]+dep[v]-dep[l];
}

void clear(){
    for(int i=1;i<=n;++i){
        e[i].clear();
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int ans=1e9;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int mx=0;
            for(int k=1;k<=n;++k){
                mx=max(mx,min(lenth(i,k),lenth(j,k)));
            }
            ans=min(ans,mx);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        clear();
        solve();
    }
}