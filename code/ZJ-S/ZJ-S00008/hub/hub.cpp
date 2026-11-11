#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int M=20;
int c,T,n,k,cnt,tot,f[maxn][M+5],dep[maxn],ans;
bool vis[maxn];
vector<int>e[maxn];
void init(){
    for(int i=1;i<=n;i++) e[i].clear();
    dep[1]=1;
    ans=n+1;
}
int LCA(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    int d=dep[y]-dep[x];
    for(int i=0;i<=M;i++){
        if(d&(1<<i)) y=f[i][y];
    }
    if(x==y) return x;
    for(int i=M;i>=0;i--){
        if(f[i][x]!=f[i][y]){
            x=f[i][x];
            y=f[i][y];
        }
    }
    return f[0][x];
}
int calc(int x,int y){
    int z=LCA(x,y);
    return dep[x]+dep[y]-2*dep[z];
}
void dfs1(int x){
    for(int v:e[x]){
        if(v==f[0][x]) continue;
        dep[v]=dep[x]+1;
        f[0][v]=x;
        dfs1(v);
    }
}
void upd(){
    int mx=0;
    for(int i=1;i<=n;i++){
        int d=n+1;
        for(int j=1;j<=n;j++){
            if(vis[j]) d=min(d,calc(i,j));
        }
        mx=max(mx,d);
    }
    ans=min(ans,mx);
}
void dfs2(int x){
    if(x>n){
        if(cnt==k){
            tot=0;
            for(int i=1;i<=n;i++){
                if(!vis[f[0][i]] && vis[i]) tot++;
            }
            if(tot<=2) upd();
        }
        return;
    }
    vis[x]=true;
    cnt++;
    dfs2(x+1);
    vis[x]=false;
    cnt--;
    dfs2(x+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs1(1);
        for(int i=1;i<=M;i++){
            for(int j=1;j<=n;j++) f[i][j]=f[i-1][f[i-1][j]];
        }
        dfs2(1);
        cout<<ans<<"\n";
    }
    return 0;
}