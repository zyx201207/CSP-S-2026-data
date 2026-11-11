#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int dep[N],n,k;
int f[25][N];
vector<int> g[N];
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    int k=dep[u]-dep[v];
    for(int i=20;i>=0;i--) {
        if((k>>i)&1) u=f[i][u];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--) {
        if(f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
    }
    return f[0][u];
}
void dfs(int u,int fa){
    f[0][u]=fa;dep[u]=dep[fa]+1;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void init(){
    for(int j=1;(1<<j)<=n;j++) {
        for(int i=1;i<=n;i++) {
            f[j][i]=f[j-1][f[j-1][i]];
        }
    }
}
int Dis(int u,int v){
    int lc=lca(u,v);
    return dep[u]+dep[v]-2*dep[lc];
}
struct edge{
    int u,v;
}e[N];
bool b[N],in[N];
int pre[N];
int find(int p){
    if(p==pre[p]) return p;
    return pre[p]=find(pre[p]);
}
int check(int S){
    for(int i=1;i<=n;i++) pre[i]=i,in[i]=b[i]=0;
    for(int i=0;i<n;i++) {
        if((S>>i)&1) b[i+1]=1;
    }
    for(int i=1;i<n;i++) {
        int u=e[i].u,v=e[i].v;
        if(b[u]&&b[v]) pre[find(u)]=find(v);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(b[i]) if(!in[find(i)]) in[find(i)]=1,cnt++;
    }
    if(cnt>2) return n;
    int su=0;
    for(int i=1;i<=n;i++) {
        int res=n;
        if(b[i]) continue;
        for(int j=1;j<=n;j++) {
            if(!b[j]) continue;
            res=min(res,Dis(i,j));
        }
        su=max(su,res);
    }
    // if(su==0) cerr<<S<<'\n';
    return su;
}
int check1(){
    int su=0;
    for(int i=1;i<=n;i++) {
        int res=n;
        if(b[i]) continue;
        for(int j=1;j<=n;j++) {
            if(!b[j]) continue;
            res=min(res,Dis(i,j));
        }
        su=max(su,res);
    }
    return su;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) dep[i]=0,g[i].clear();
    for(int i=1,u,v;i<n;i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[i]=edge{u,v};
    }
    dfs(1,0);
    init();
    int ans=n;
    if(k<=2) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) b[j]=0;
            b[i]=1;
            if(k==2) 
            for(int j=i+1;j<=n;j++) {
                b[j]=1;
                ans=min(ans,check1());
                b[j]=0;
            }
            else ans=min(ans,check1());
        }
    }
    else 
    for(int S=0;S<(1<<n);S++) {
        if(__builtin_popcount(S)!=k) continue;
        ans=min(ans,check(S));
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) {
        solve();
    }
    return 0;
}