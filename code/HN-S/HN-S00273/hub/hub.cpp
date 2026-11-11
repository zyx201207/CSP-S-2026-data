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
namespace Solve1{
    vector<int> leaf;
    int w[maxn];
    void dfs(int u,int fa){
        int flg=1;
        for(int v:g[u]) if(v!=fa) flg=0,dfs(v,u);
        if(flg) leaf.pb(u);
    }
    bool in(int x,int y){
        return (dfn[y]<=dfn[x]&&dfn[x]<dfn[y]+sz[y]);
    }
    bool chk(int x){
        // cerr<<"chk:"<<x<<endl;
        for(int i=1;i<=n;i++){
            vector<int> vec;
            for(int u:leaf) if(in(u,i)&&dis(u,i)>x) vec.pb(kth(u,x));
            if(vec.empty()){
                w[i]=1;
                continue;
            }
            int sz=vec.size();
            sort(vec.begin(),vec.end(),[](int x1,int x2){return dfn[x1]<dfn[x2];});
            w[i]=dis(vec[0],i)+1;
            for(int j=1;j<sz;j++) w[i]+=dis(vec[j],i)-dis(lca(vec[j],vec[j-1]),i);
        }
        // for(int i=1;i<=n;i++) cerr<<w[i]<<" ";cerr<<endl;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(in(i,j)||in(j,i)) continue;
                bool flg=1;
                for(int u=1;u<=n;u++){
                    if(in(u,i)||in(u,j)) continue;
                    if(min(dis(u,i),dis(u,j))>x){
                        flg=0;
                        break;
                    }
                }
                if(!flg) continue;
                // if(x==11) cerr<<i<<" "<<j<<" "<<w[i]+w[j]<<endl;
                if(w[i]+w[j]<=k) return 1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||!in(i,j)||dep[j]-1>x) continue;
                // cerr<<i<<" "<<j<<" "<<endl;
                bool flg=1;
                for(int u:leaf){
                    if(in(u,j)) continue;
                    if(dis(u,j)>x){
                        flg=0;
                        break;
                    }
                }
                if(!flg) continue;
                int res=w[i];
                vector<int> vec;
                for(int u:leaf) if(!in(u,i)&&in(u,j)&&dis(u,j)>x) vec.pb(kth(u,x));
                if(dis(f[kth(i,x)],j)>x) vec.pb(kth(f[kth(i,x)],x));
                int sz=vec.size();
                if(sz>0){
                    sort(vec.begin(),vec.end(),[](int x1,int x2){return dfn[x1]<dfn[x2];});
                    res+=dis(vec[0],j)+1;
                    for(int k=1;k<sz;k++) res+=dis(vec[k],j)-dis(lca(vec[k],vec[k-1]),j);
                }
                else res++;
                // cerr<<i<<" "<<j<<" "<<res<<endl;
                // for(int u:vec) cerr<<u<<" ";cerr<<endl;
                if(res<=k) return 1;
            }
        }
        return 0;
    }
    void solve(){
        leaf.clear(),dfs(1,1);
        int l=0,r=n,mid=0,res=n;
        while(l<=r) mid=(l+r)>>1,(chk(mid)?res=mid,r=mid-1:l=mid+1);
        print(res,'\n');
    }
}
void solve(){
    n=read<int>(),k=read<int>(),cnt=0;
    for(int i=1,u,v;i<n;i++) u=read<int>(),v=read<int>(),g[u].pb(v),g[v].pb(u);
    dfs(1,0),Dfs(1,1,1);
    if(o<=10) Solve1::solve();
    for(int i=1;i<=n;i++) g[i].clear();
}
int main(){
    FileIO("hub");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    o=read<int>(),t=read<int>();
    while(t--) solve();
    return 0;
}
/*
我常常追忆过去。

生命瞬间定格在脑海，我将背后的时间裁剪 折叠 蜷曲，揉捻成天上朵朵白云。云朵之间亦有分别：积云厚重，而卷云飘渺。

调太他妈久了，打不完了。
*/