#include <bits/stdc++.h>
using namespace std;
namespace chennie_bless_me{
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
inline void chmax(T &a,T b){
    if(a<b) a=b;
}
template<typename T>
inline void chmin(T &a,T b){
    if(b<a) a=b;
}
namespace fastio{
    const int BUFSZ=1<<20;
    char buf[BUFSZ],*p1=buf,*p2=buf,ch; int sgn;
    #define gc() ((p1==p2&&(p1=buf,p2=p1+fread(buf,1,BUFSZ,stdin))),(p1==p2?EOF:*p1++))
    template<typename T>
    inline void read(T &x){
        x=0; sgn=0; ch=gc();
        while(!isdigit(ch)){
            if(ch=='-') sgn=1;
            ch=gc();
        }
        while(isdigit(ch)){
            x=x*10+(ch-'0');
            ch=gc();
        }
        if(sgn) x=-x;
    }
    #undef gc
}
using fastio::read;
const int N=1e6+5;
int testcase,T;
int n,k;
vector<int> G[N],a[N];
int dis1[N],dis2[N],l1,l2;
void dfs(int u,int fa,int d,int dis[],int &l){
    dis[u]=d;
    if(d>dis[l]) l=u;
    for(int v:G[u]){
        if(v==fa) continue;
        dfs(v,u,d+1,dis,l);
    }
}
struct dsu{
    int fa[N],cnt;
    void init(int n){
        fill(fa,fa+n+2,-1);
        cnt=0;
    }
    int root(int u){
        return fa[u]<0?u:fa[u]=root(fa[u]);
    }
    void merge(int u,int v){
        u=root(u);v=root(v);
        if(u==v)return ;
        if(fa[u]>fa[v])swap(u,v);
        fa[u]+=fa[v];fa[v]=u;cnt++;
    }
}uf;
void solve(){
    for(int i=0;i<=n;i++){
        G[i].clear();
        a[i].clear();
    }
    read(n); read(k);
    uf.init(n);
    for(int i=1;i<n;i++){
        int u,v; read(u);
        read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    l1=1; 
    dfs(1,0,0,dis1,l1);
    l2=l1;
    dfs(l1,0,0,dis2,l2);
    vector<int> dis(n+1,-1),deg(n+1);
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(G[i].size()==1){
            Q.push(i);
            dis[i]=0;
        }
        deg[i]=G[i].size();
    }
    while(Q.size()){
        int u=Q.front(); Q.pop();
        for(int v:G[u]){
            if(dis[v]!=-1) continue;
            if(--deg[v]==1){
                Q.push(v);
                dis[v]=dis[u]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        a[dis[i]].push_back(i);
    }
    int ans=n;
    for(int i=n-1;i>=0;i--){
        uf.init(n);
        for(int j=i,sum=0;j<n;j++){
            sum+=a[j].size();
            if(sum>k) break;
            for(int u:a[j]){
                for(int v:G[u]){
                    if(dis[v]>=i&&dis[v]<=j)
                        uf.merge(u,v);
                }
            }
            if(sum-uf.cnt<=2) chmin(ans,max(i,n-j-1));
        }
    }
    cout<<ans<<'\n';
}
void main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    read(testcase);
    read(T);
    while(T--) solve();
}
}
int main(){
    assert(freopen("hub.in","r",stdin));
    assert(freopen("hub.out","w",stdout));
    chennie_bless_me::main();
    return 0;
}