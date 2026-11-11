#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int f1,f2;
bool vis[1000005];
int dep[1000005],f[1000005][21];
vector<int>g[1000005];
vector<int>can;
int lca(int u,int v){
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    for(int j=20;j>=0;j--){
        if(dep[f[v][j]]>=dep[u]){
            v=f[v][j];
        }
    }
    if(u==v){
        return u;
    }
    for(int j=20;j>=0;j++){
        if(f[u][j]!=f[v][j]){
            u=f[u][j];v=f[v][j];
        }
    }
    return f[u][0];
}
int dis(int u,int v){
    int ll=lca(u,v);
    return dep[u]+dep[v]-2*dep[ll];
}
void dfs(int u,int fa){
    f[u][0]=fa;
    for(int v:g[u]){
        if(v==fa){
            continue;
        }
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
void findlen(){
    dep[1]=1;
    dfs(1,0);
    int mx=0,pos;
    for(int i=1;i<=n;i++){
        if(dep[i]>mx){
            mx=dep[i];
            pos=i;
        }
    }
    f1=pos;
    dep[pos]=1;
    dfs(pos,0);
    mx=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>mx){
            mx=dep[i];
            pos=i;
        }
    }
    f2=pos;
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
void init(){
    ans=0;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        g[i].clear();
        for(int j=0;j<=20;j++){
            f[i][j]=0;
        }
    }
    can.clear();
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        findlen();
        k-=2;
        if(!k){
            for(int i=1;i<=n;i++){
                if(i==f1||i==f2){
                    continue;
                }
                ans=max(ans,min(dis(i,f1),dis(i,f2)));
            }
            cout<<ans<<"\n";
            continue;
        }
        vis[f1]=vis[f2]=1;
        can.push_back(f1);
        can.push_back(f2);
        for(int i=1;i<=k;i++){
            int mn=1e9,nxt,rem;
            for(int u:can){
                vector<int>tmp;
                for(int v:g[u]){
                    if(!vis[v]){
                        tmp.push_back(v);
                    }
                }
                for(int v:tmp){
                    int mx=0;
                    for(int j=1;j<=n;j++){
                        if(!vis[j]){
                            mx=max(mx,dis(j,v));
                        }
                    }
                    if(mx<mn){
                        mn=mx;
                        nxt=v;
                        rem=u;
                    }
                }
            }
            vis[nxt]=1;
            can.push_back(nxt);
            if(i==k){
                cout<<mn<<"\n";
            }
        }
    }
    return 0;
}
