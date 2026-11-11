#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,k;
vector<int> ver[N];
bool vis[N],vv[N];
int fa[N][22],dep[N];
void dfs(int x){
    for(int y:ver[x]){
        if(y==fa[x][0]) continue;
        fa[y][0]=x;
        dep[y]=dep[x]+1;
        dfs(y);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    int dd=dep[x]-dep[y];
    for(int c=0;c<=20;c++){
        if(dd&1) x=fa[x][c];
        dd>>=1;
    }
    if(x==y) return x;
    for(int c=20;c>=0;c--){
        if(fa[x][c]!=fa[y][c]){
            x=fa[x][c];
            y=fa[y][c];
        }
    }
    return fa[x][0];
}
int dis(int x,int y){
    return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int md[N];
void solve(int x,int fa){
    md[x]=0;
    for(int y:ver[x]){
        if(y==fa||vis[y]) continue;
        solve(y,x);
        md[x]=max(md[x],md[y]);
    }
    md[x]++;
}
struct comp{
    bool operator()(int x,int y){
        return md[x]<md[y];
    }
};
priority_queue<int,vector<int>,comp> pq;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            vis[i]=vv[i]=dep[i]=md[i]=0;
            for(int c=0;c<=20;c++) fa[i][c]=0;
        }
        for(int i=1;i<=n;i++) ver[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            ver[u].push_back(v);
            ver[v].push_back(u);
        }
        dep[1]=1;
        dfs(1);
        for(int c=1;c<=20;c++){
            for(int i=1;i<=n;i++){
                fa[i][c]=fa[fa[i][c-1]][c-1];
            }
        }
        int ans=n;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int u=1;u<=n;u++) vv[u]=vis[u]=0;
                int tot=0;
                for(int u=1;u<=n;u++){
                    if(lca(i,j)==i){
                        if(dep[u]>dep[i]&&lca(u,i)==i
                           &&lca(u,j)!=i&&lca(u,j)!=j){
                            vis[u]=1;
                            tot=max(tot,min(dis(u,i),dis(u,j)));
                        }
                        continue;
                    }
                    if(lca(i,j)==j){
                        if(dep[u]>dep[j]&&lca(u,j)==j
                           &&lca(u,i)!=j&&lca(u,i)!=i){
                            vis[u]=1;
                            tot=max(tot,min(dis(u,i),dis(u,j)));
                        }
                        continue;
                    }
                    if(!((lca(u,i)==i&&lca(u,j)==lca(i,j))||
                       (lca(u,j)==j&&lca(u,i)==lca(i,j)))){
                        vis[u]=1;
                        tot=max(tot,min(dis(u,i),dis(u,j)));
                    }
                }
                solve(i,0); solve(j,0);
                pq.push(i); pq.push(j);
                vv[i]=vv[j]=1;
                int res=k;
                while(res!=0&&!pq.empty()){
                    int t=pq.top();
                    pq.pop();
                    vis[t]=1;
                    for(int u:ver[t]){
                        if(!vis[u]&&!vv[u]) pq.push(u);
                        vv[u]=1;
                    }
                    res--;
                }
                if(!pq.empty()) tot=max(tot,md[pq.top()]);
                ans=min(ans,tot);
                while(!pq.empty()) pq.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
