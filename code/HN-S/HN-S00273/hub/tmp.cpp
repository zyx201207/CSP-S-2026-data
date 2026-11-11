#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define mset multiset
#define ull unsigned long long
#define i128 __int128
#define fixs fixed<<setprecision
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
namespace FastIO{
    char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p1=buf,p2=(p1+fread(buf,1,1<<21,stdin)))==p1?EOF:*p1++)
    template<typename T>inline T read(){T x=0,w=0;char ch=getchar();while(ch<'0'||ch>'9') w|=(ch=='-'),ch=getchar();while('0'<=ch&&ch<='9') x=x*10+(ch^'0'),ch=getchar();return w?-x:x;}
    template<typename T>inline void write(T x){if(!x) return ;write(x/10),putchar((x%10)^'0');}
    template<typename T>inline void print(T x){if(x<0) putchar('-'),write(-x);else if(x>0) write(x);else putchar('0');}
    template<typename T>inline void print(T x,char en){print(x),putchar(en);}
}using namespace FastIO;
const int maxn=1e6+10;
int o,n,k,sz[maxn],son[maxn],dfn[maxn],rk[maxn],dep[maxn],f[maxn],top[maxn],cnt;
vector<int> g[maxn];
void dfs(int u,int fa){
    f[u]=fa,dep[u]=dep[fa]+1,sz[u]=1,son[u]=0;
    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u),sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void Dfs(int u,int fa,int tp){
    top[u]=tp,dfn[u]=++cnt,rk[cnt]=u;
    if(son[u]) Dfs(son[u],u,tp);
    for(int v:g[u]) if(v!=fa&&v!=son[u]) Dfs(v,u,v);
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) u^=v^=u^=v;
        u=f[top[u]];
    }
    return (dep[u]<dep[v]?u:v);
}
int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int kth(int u,int k){
    while(k>dep[u]-dep[top[u]]) k-=dep[u]-dep[top[u]]+1,u=f[top[u]];
    return rk[dfn[u]-k];
}
void solve(){
    n=read<int>(),k=read<int>(),cnt=0;
    for(int i=1,u,v;i<n;i++) u=read<int>(),v=read<int>(),g[u].pb(v),g[v].pb(u);
    int res=n;
    dfs(1,0),Dfs(1,1,1);
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=k) continue;
        int cnt=k,maxx=0;
        for(int j=1;j<=n;j++){
            if(!((i>>(j-1))&1)) continue;
            for(int k:g[j]) if(k>j) cnt-=((i>>(k-1))&1);
        }
        if(cnt>2) continue;
        for(int j=1;j<=n;j++){
            int minn=n;
            for(int k=1;k<=n;k++) if((i>>(k-1))&1) minn=min(minn,dis(j,k));
            maxx=max(maxx,minn);
        }
        res=min(res,maxx);
        if(maxx==1){
            for(int j=1;j<=n;j++) if((i>>(j-1))&1) cerr<<j<<" ";
            cerr<<endl;
        }
    }
    print(res,'\n');
    for(int i=1;i<=n;i++) g[i].clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    o=read<int>(),t=read<int>();
    while(t--) solve();
    return 0;
}