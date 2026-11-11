#include<bits/stdc++.h>
// #define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+5,inf=1e9;
int n,k,cid,T;vector<int> g[N];
int f[N],dis[N];
int cnt;bool vis[N];
void dfsss(int u,int fa){
    for(int v:g[u]) if(v^fa) {dis[v]=min(dis[v],dis[u]+1);dfsss(v,u);}
}
void dfssss(int u,int fa){
    for(int v:g[u]) if(v^fa&&dis[v]==0) {vis[v]=1;dfsss(v,u);}
}
void baoli(){
    const int l=1<<n;int ans=inf;
    for(int h=0;h<l;h++) if(__builtin_popcount(h)<=k) {
        for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
        for(int i=1;i<=n;i++) if((h>>(i-1))&1) dis[i]=0,dfsss(i,0);
        int res=0;for(int i=1;i<=n;i++) if(dis[i]==0&&!vis[i]) dfssss(i,0),res++;
        if(res<=2) {res=0;
            for(int i=1;i<=n;i++) res=max(res,dis[i]);ans=min(ans,res);
        }
    }
    printf("%d\n",ans);
}
void dfs(int u,int fa){
    if(g[u].size()==1) dis[u]=k;else dis[u]=inf;
    for(int v:g[u]) if(v^fa) {
        dfs(v,u);
        dis[u]=min(dis[u],dis[v]-1);f[u]+=f[v];
    }
    if(dis[u]<=0||f[u]) f[u]++;
}
bool check(int mid){
    for(int i=1;i<=n;i++) f[i]=0;
    dfs(1,0);//jia jia jia
    return f[1]<=k;
}
void t1(){
    int l=1,r=n,ans=n;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(4*mid-1+k>=(n+1)/2) ans=mid,r=mid-1;else l=mid+1;
    }
    printf("%d\n",ans);
}
void solve(){
    n=read(),k=read();
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++) {
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(k==n) {printf("0\n");return ;}
    if(n<=10) {baoli();return ;}
    if(13<=cid&&cid<=14) {t1();return ;}
    int l=1,r=n,ans=n;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;else l=mid+1;
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("hub.in" ,"r",stdin );
    freopen("hub.out","w",stdout);
    // freopen("1.in" ,"r",stdin );
    cid=read(),T=read();
    while(T--) solve();
    return 0;
}