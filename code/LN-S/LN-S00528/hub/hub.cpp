#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int C,T,n,k,ans;
vector<int> adj[500005];
int fa[500005][22],dep[500005];
void dfs(int x,int f){
    fa[x][0]=f;
    dep[x]=dep[f]+1;
    for(int v:adj[x]){
        if(v==f) continue;
        dfs(v,x);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=21;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    }
    if(u==v) return u;
    for(int i=21;i>=0;i--){
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
bool slt[500005],vis[500005];
vector<int> selected;
void Dfs(int x){
    vis[x]=1;
    for(int v:adj[x]){
        if(vis[v]||!slt[v]) continue;
        Dfs(v);
    }
}
bool check(){
    int cnt=0;
    for(int i:selected) vis[i]=0;
    for(int i:selected){
        if(!vis[i]) cnt++,Dfs(i);
        if(cnt>2) return 0;
    }
    return 1;
}
void DFS(int x,int cntc){
    // cout<<x<<" "<<cntc<<" "<<k<<endl;
    if(n-x+1+cntc<k||cntc>k) return;
    // cout<<x<<" "<<cntc<<" "<<k<<endl;
    if(cntc==k){
        // cout<<"O:::::"<<endl;
        // for(int i:selected) cout<<i<<" ";
        // cout<<endl;
        if(!check()) return;
        int maxd=0;
        for(int i=1;i<=n;i++){
            int qwq=LONG_LONG_MAX;
            for(int j:selected){
                int lc=lca(i,j);
                // cout<<i<<"lc"<<j<<"lc"<<lc<<endl;
                qwq=min(qwq,dep[i]-dep[lc]+dep[j]-dep[lc]);
            }
            maxd=max(maxd,qwq);
        }
        ans=min(ans,maxd);
        // cout<<ans<<endl;
        return;
    }
    selected.push_back(x);
    slt[x]=1;
    DFS(x+1,cntc+1);
    selected.pop_back();
    slt[x]=0;
    DFS(x+1,cntc);
    return;
}
signed main(){
    qrw;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) adj[i].clear(),memset(fa[i],0,sizeof(fa[i])),dep[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,1);
        for(int i=1;i<22;i++){
            for(int j=1;j<=n;j++){
                fa[j][i]=fa[fa[j][i-1]][i-1];
            }
        }
        selected.clear();
        ans=LONG_LONG_MAX;
        DFS(1,0);
        cout<<ans<<endl;
    }
}
// 其实希望，本是无所谓有，也无所谓无的。
// 这正如世上的路——走的人多了，便就有了路。
// 但我欣然。我将大笑，我将歌唱。