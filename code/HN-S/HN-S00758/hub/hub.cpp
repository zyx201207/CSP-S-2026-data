#include<iostream>
#include<vector>

using namespace std;

const int inf=1e9;

static inline void chkmin(int &x,int y){if(x>y)x=y;}

int n,K;
vector<int>vec[1000005];

bool vis[1000005];
int dep[1000005];
int siz[1000005];
int dp[1005][1005];
int nxt[1005];
static inline void dfs2(int u,int fa){
    dp[u][0]=dp[u][1]=0;
    for(int i=2;i<=K;++i)
        dp[u][i]=inf;
    for(auto v:vec[u]){
        if(vis[v]||v==fa)
            continue;
        dfs2(v,u);
        for(int i=0;i<=K;++i){
            nxt[i]=max(dp[u][i],dp[v][0]+1);
            for(int j=1;j<i;++j)
                chkmin(nxt[i],max(dp[u][j],dp[v][i-j]));
        }
        for(int i=0;i<=K;++i)
            dp[u][i]=nxt[i];
    }
}
int h[1000005];
static inline void dfs(int u,int fa){
    h[u]=0;
    for(auto v:vec[u]){
        if(vis[v]||v==fa)
            continue;
        dfs(v,u);
        h[u]=max(h[u],h[v]+1);
    }
}

int ans;
static inline void solve(int x,int y){
    if(x==y){
        dfs2(x,0);
        for(int i=1;i<=K;++i)
            chkmin(ans,dp[x][i]);
        return;
    }
    int ret=0;
    for(int i=1;i<=n;++i){
        if(vis[i]&&i!=x&&i!=y){
            dfs(i,0);
            ret=max(ret,min(dep[i],dep[y]-dep[i])+h[i]);
        }
    }
    dfs2(x,0);
    dfs2(y,0);
    for(int i=1;i<K;++i)
        chkmin(ans,max(max(dp[x][i],dp[y][K-i]),ret));
}

static inline void dfs(int u,int fa,int rt){
    vis[u]=true;
    solve(rt,u);
    for(int i=0;i<(int)vec[u].size();++i){
        int v=vec[u][i];
        if(v==fa)
            continue;
        dep[v]=dep[u]+1;
        dfs(v,u,rt);
    }
    vis[u]=false;
}

static inline void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;++i)
        vec[i].clear();
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    // if(K==2){
    //     ans=inf;
    //     for(int u=1;u<=n;++u){
    //         dfs3(u,0);
    //     }
    //     cout<<ans<<'\n';
    // }else{
        ans=inf;
        for(int u=1;u<=n;++u){
            dep[u]=0;
            dfs(u,0);
            dfs(u,0,u);
        }
        cout<<ans<<'\n';
    // }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _id,T;
    cin>>_id>>T;
    while(T--)
        solve();
    return 0;
}