#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
const int N=1e6+5;
vector<int> G[N];
int sz[N],dp[N],fa[N],so[N],tp[N];
void dfs1(int x,int f){
    fa[x]=f,dp[x]=dp[f]+1,sz[x]=1;
    for (int y : G[x])
        if(y!=f){
            dfs1(y,x);
            sz[x]+=sz[y];
            if(sz[y]>sz[so[x]]) so[x]=y;
        }
    return;
}
void dfs2(int x,int ft){
    tp[x]=ft;
    if(so[x]) dfs2(so[x],ft);
    for (int y : G[x])
        if(y!=fa[x]&&y!=so[x]) dfs2(y,y);
    return;
}
int lca(int x,int y){
    while(tp[x]!=tp[y]){
        if(dp[tp[x]]<dp[tp[y]]) swap(x,y);
        x=fa[tp[x]];
    }
    if(dp[tp[x]]>dp[tp[y]]) swap(x,y);
    return x;
}
int dist(int x,int y){
    return dp[x]+dp[y]-dp[lca(x,y)];
}
int f[N];
bool flag[N];
int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}
void Merge(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    f[x]=y;
    return;
}
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        G[i].clear();
    for (int i=1;i<n;++i){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(fa,0,sizeof(fa));
    memset(sz,0,sizeof(sz));
    memset(so,0,sizeof(so));
    memset(dp,0,sizeof(dp));
    dfs1(1,0);
    dfs2(1,1);
    int ans=INT_MAX;
    for (int i=0;i<(1<<n);++i){
        if(__builtin_popcount(i)!=k) continue;
        for (int j=1;j<=n;++j)
            f[j]=j;
        for (int x=1;x<=n;++x)
            for (int y : G[x])
                if(((i>>x-1)&1)&&((i>>y-1)&1)) Merge(x,y);
        int cnt=0;
        for (int j=1;j<=n;++j)
            flag[j]=0;
        for (int j=1;j<=n;++j)
            if((i>>j-1)&1){
                int tmp=Find(j);
                if(!flag[tmp]) flag[tmp]=1,++cnt;
            }
        if(cnt>2) continue;
        int ma=0;
        for (int j=1;j<=n;++j){
            if((i>>j-1)&1) continue;
            int mi=INT_MAX;
            for (int l=1;l<=n;++l)
                if(((i>>l-1)&1)) mi=min(mi,dist(j,l));
            ma=max(ma,mi);
        }
        ans=min(ans,ma);
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}