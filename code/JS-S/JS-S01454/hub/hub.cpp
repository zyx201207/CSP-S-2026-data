#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000050];
int dis[4050][4050],dp[4050],vis[4050],f[10050][15],n,k,cho[4050],d[4050],vis2[4050];
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();++i){
        int to=g[x][i];
        if(vis[to]) continue;
        dp[to]=dp[x]+1;
        f[to][0]=x;
        dfs(to);
    }
}
void dfs2(int x){
    vis2[x]=1;
    for(int i=0;i<g[x].size();++i){
        int to=g[x][i];
        if(vis2[to]) continue;
        dfs(to);
    }
}
void init(){
    for(int i=1;i<=n;++i) fill(dis[i]+1,dis[i]+n+1,0);
    fill(dp+1,dp+n+1,0);
    fill(vis+1,vis+n+1,0);
    for(int i=1;i<=n;++i) fill(f[i]+1,f[i]+13,0);
    fill(cho+1,cho+n+1,0);
    fill(d+1,d+n+1,0);
    fill(vis2+1,vis2+n+1,0);
    for(int j=1;j<=12;++j){
        for(int i=1;i<=n;++i){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
int lca(int a,int b){
    if(dp[a]>dp[b]) swap(a,b);
    int del=dp[b]-dp[a];
    for(int i=12;i>=0;i--){
        if((1<<i)&del) a=f[a][i];
    }
    for(int i=12;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
void solve(){
    int ans=1e9;
    cin>>n>>k;
    for(int i=1;i<=n;++i) g[i].clear();
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    dfs(1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dis[i][j]=dis[j][i]=dp[i]+dp[j]-dp[lca(i,j)]*2;
        }
    }
    for(long long i=1;i<=pow(2,n);++i){
        int cnt=0,cur=0;
        for(int j=n;j>=0;--j){
            if(i&j){
                cho[j]=1;
                ++cnt;
            }
        }
        if(cnt!=k) continue;
        cnt=0;
        for(int i=1;i<=n;++i){
            if(cho[i]&&(!vis2[i])){
                ++cnt;
                if(cnt<=2) dfs2(i);
            }
        }
        if(cnt>2) continue;
        for(int i=1;i<=n;++i){
            d[i]=1e9;
            for(int j=1;j<=k;++j){
                d[i]=min(d[i],dis[i][j]);
            }
            cur=max(cur,d[i]);
        }
        ans=min(ans,cur);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
