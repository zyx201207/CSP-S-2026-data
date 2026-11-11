#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int const N=500005;
int n,k,dp[105][105][105][2],sz[105];
vector<int> g[105];
bool b[105];
int dfs(int u,int f) {
    if(b[u]) return 0;
    int ans=0;
    for(int v:g[u]) if(v!=f) ans=max(ans,dfs(v,u));
    return ans+1;
}
int fa[105],cnt[105];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
void solve(int c) {
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(0<=c&&c<=2) {
        int ans=n*n;
        for(int i=1;i<(1<<n);i++) if(__builtin_popcount(i)==k) {
            for(int j=1;j<=n;j++) b[j]=(i>>j-1)&1;
            for(int j=1;j<=n;j++) if(b[j]) fa[j]=j;
            for(int u=1;u<=n;u++) if(b[u])
                for(int v:g[u]) if(b[v]) fa[find(u)]=find(v);
            for(int u=1;u<=n;u++) cnt[u]=0;
            for(int u=1;u<=n;u++) if(b[u]) cnt[find(u)]++;
            int cc=0;
            for(int u=1;u<=n;u++) if(cnt[u]) cc++;
            if(cc>2) continue;
            int dist=0;
            for(int j=1;j<=n;j++) dist=max(dist,dfs(j,0));
            ans=min(ans,dist);
//            cout<<i<<' '<<dist<<' '<<cc<<endl;
        }
        for(int i=1;i<=n;i++) g[i].clear();
        cout<<ans<<endl;
        return;
    }
}
int main() {
#ifndef DEBUG
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif // DEBUG
    int c,t;
    cin>>c>>t;
    while(t--) solve(c);
    return 0;
}
