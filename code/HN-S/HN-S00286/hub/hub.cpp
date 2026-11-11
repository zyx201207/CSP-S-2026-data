// hub
#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
namespace FASTIO{
    template<typename T>
    void read(T &x){
        x=0;bool f=1;int ch=getchar();
        for(;!isdigit(ch);ch=getchar())f=ch=='-'?0:f;
        for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
        x=f?x:-x;
    }
    void read(){}
    template<typename T,typename ...Args>
    void read(T &x,Args &...args){read(x),read(args...);}
}
namespace Solve{
using FASTIO::read;
int c;
constexpr int N=1e6+5;
struct Solver{

int to[N<<1],nxt[N<<1],cnt,h[N];
void add(int u,int v){to[++cnt]=v,nxt[cnt]=h[u],h[u]=cnt;}
int n,k,ans;
int d[N],son[N];
void dfs1(int u,int dad){
    d[u]=son[u]=0;
    for(int e=h[u];e;e=nxt[e]){
        int v=to[e];if(v==dad)continue;
        dfs1(v,u);
        if(d[v]+1>d[u])d[u]=d[v]+1,son[u]=v;
    }
}
int p1,p2,mid,mdl,mdr;
void dfs2(int u,int dad,bool tag){
    d[u]=son[u]=0;if(u==mid)return;
    for(int e=h[u];e;e=nxt[e]){
        int v=to[e];if(v==dad)continue;
        if(tag&&v==mid)continue;
        dfs2(v,u,tag);
        if(d[v]+1>d[u])d[u]=d[v]+1,son[u]=v;
    }
}
int main(){
    read(n,k);
    for(int i=1;i<n;++i){
        int u,v;read(u,v);
        add(u,v),add(v,u);
    }
    if(k==n)return puts("0"),0;
    dfs1(1,1);for(p1=1;son[p1];p1=son[p1]);
    dfs1(p1,p1);for(p2=p1;son[p2];p2=son[p2]);
    mid=p1;
    for(int dis=0;2*(dis+1)<=d[p1];mid=son[mid],++dis);
    dfs1(mid,mid);
    sort(d+1,d+n+1,greater<int>());
    ans=d[k+1]+1;
    dfs1(p1,p1);mdl=p1;
    for(int dis=0;3*(dis+1)<=d[p1];mdl=son[mdl],++dis);
    dfs1(p2,p2);mdr=p2;
    for(int dis=0;3*(dis+1)<=d[p1];mdr=son[mdr],++dis);
    int dl=0,dr=0;
    for(int i=mid;i!=mdl;i=son[i])++dl;
    for(int i=mdr;i!=mid;i=son[i])++dr;
    if(dl>dr)dfs2(mdl,mdl,1),dfs2(mdr,mdr,0);
    else dfs2(mdl,mdl,0),dfs2(mdr,mdr,1);
    sort(d+1,d+n+1,greater<int>());
    ans=min(ans,d[k+1]+1);
    printf("%d\n",ans);
    return 0;
}

};
int main(){int t;read(c,t);while(t--){Solver _{};_.main();}return 0;}
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    return Solve::main();
}