#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,ans,f[N][20],d[N],lens[1005][1005],ff[N];
bool vis[N],vis2[N];
vector<int> e[N];
int fd(int x){
    if(x==ff[x])return x;
    return ff[x]=fd(ff[x]);
}
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    f[u][0]=fa;
    for(int i=0;i<=log2(d[u]);i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v!=fa){
            dfs(v,u);
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    while(d[y]>d[x]){
        int k=d[y]-d[x];
        int to=log2(k);
        y=f[y][to];
    }
    if(x==y)return x;

    for(int i=log2(d[x]);i>0;i--){
        if(f[y][i]!=f[x][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
void dfs3(int u){
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(!vis2[v]&&vis[v]){
            vis2[v]=1;
            dfs3(v);
        }
    }
}
void dfs2(int u,int ct){
    if(u==n+1){
        if(ct!=k)return;
        int cntk=0;
        for(int i=1;i<=n;i++)vis2[i]=0;
        for(int i=1;i<=n;i++){
            if(!vis2[i]&&vis[i]){
                vis2[i]=1;
                dfs3(i);
                cntk++;
            }
        }
        if(cntk>2)return;
        int val=0;
        for(int i=1;i<=n;i++){
            int mn=1e9;
            for(int j=1;j<=n;j++){
                if(i==j||!vis[j])continue;
                mn=min(mn,lens[j][i]);
            }
            val=max(val,mn);
        }
        ans=min(val,ans);
        return;
    }
    vis[u]=1;
    dfs2(u+1,ct+1);
    vis[u]=0;
    dfs2(u+1,ct);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=25;j++)f[i][j]=0;
            d[i]=0;
            e[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int lc=lca(i,j);
                lens[i][j]=lens[j][i]=d[i]+d[j]-2*d[lc];
            }
        }
        dfs2(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
