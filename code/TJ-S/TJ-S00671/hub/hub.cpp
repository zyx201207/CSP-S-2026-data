#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
vector<int> g[N];
int fa[N],pa[N][22],dep[N];
int n,k;
inline void init(){
    for (int j=1;j<=20;j++){
        for (int i=1;i<=n;i++) pa[i][j]=pa[pa[i][j-1]][j-1];
    }
}
inline int find(int x){
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
inline void dfs(int u,int f){
    pa[u][0]=f,dep[u]=dep[f]+1;
    for (int v:g[u]){
        if (v==f) continue;
        dfs(v,u);
    }
}
inline int lca(int u,int v){
    if (dep[u]>dep[v]) swap(u,v);
    for (int j=20;j>=0;j--){
        if (dep[pa[v][j]]>=dep[u]) v=pa[v][j];
    }
    if (u==v) return u;
    for (int j=20;j>=0;j--){
        if (pa[u][j]!=pa[v][j]) u=pa[u][j],v=pa[v][j];
    }
    return pa[u][0];
}
inline void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1;i<=n;i++) dep[i]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=20;j++) pa[i][j]=0;
    }
    dfs(1,0);
    init();
    int ans=1e18;
    for (int S=0;S<(1<<n);S++){
        for (int i=1;i<=n;i++) fa[i]=i;
        int cnt=0;
        for (int i=1;i<=n;i++){
            if ((S>>(i-1))&1) cnt++;
        }
        if (cnt!=k) continue;
        vector<bool> vis(n+1,0);
        vector<int> d(n+1,0);
        for (int i=1;i<=n;i++){
            if ((S>>(i-1))&1){
                vis[i]=1;
            }
        }
        for (int i=1;i<=n;i++){
            if ((S>>(i-1))&1){
                if ((S>>(pa[i][0]-1))&1){
                    fa[find(i)]=fa[find(pa[i][0])];
                }
            }
        }
        int bcnt=0;
        for (int i=1;i<=n;i++){
            if ((S>>(i-1))&1){
                if (fa[i]==i) bcnt++;
            }
        }
        if (bcnt>2){
            continue;
        }
        for (int i=1;i<=n;i++){
            if ((S>>(i-1))&1) d[i]=0;
            else{
                int mn=1e18;
                for (int j=1;j<=n;j++){
                    if ((S>>(j-1))&1){
                        mn=min(mn,dep[i]+dep[j]-2*dep[lca(i,j)]);
                    }
                }
                d[i]=mn;
            }
        }
        int mx=0;
        for (int i=1;i<=n;i++){
            mx=max(mx,d[i]);
        }
        ans=min(ans,mx);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;cin>>c>>T;
    while (T--) solve();
    return 0;
}
