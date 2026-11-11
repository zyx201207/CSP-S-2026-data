#include<bits/stdc++.h>
using namespace std;typedef long long ll;
#define getchar getchar_unlocked
const int maxn=1e6+5,inf=0x3f3f3f3f;
int testid,T,n,lim;
inline int read(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    int res=0;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
inline ll lread(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    ll res=0ll;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}struct Edge{int to,nxt;}e[maxn<<1];int head[maxn],ecnt;
inline void addEdge(int u,int v){e[++ecnt]=Edge{v,head[u]},head[u]=ecnt;}
namespace Subtask0{
    inline bool chk(){return n<=10;}
    const int N=15;bool mrk[N];int tot,f[N],cur;
    void dfs(int u,int fa){
        if(!fa||(!mrk[fa]&&mrk[u]))tot++;
        f[u]=(mrk[u]?0:inf);
        for(int i=head[u],v;i;i=e[i].nxt)if((v=e[i].to)!=fa)
            dfs(v,u),f[u]=min(f[u],f[v]+1);
    }void dfs1(int u,int fa){
        if(fa)f[u]=min(f[u],f[fa]+1);
        cur=max(cur,f[u]);for(int i=head[u],v;i;i=e[i].nxt)
            if((v=e[i].to)!=fa)dfs1(v,u);
    }
    inline int main(){
        unsigned U=1u<<n;int ans=inf;for(unsigned s=0u;s<U;s++)if(__builtin_popcount(s)==lim){
            for(int i=1;i<=n;i++)mrk[i]=(s>>i-1)&1;
            cur=-inf,tot=0,dfs(1,0),dfs1(1,0);
            if(tot<=2)ans=min(ans,cur);
        }printf("%d\n",ans);
        return 0;
    }
}
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int main(){open(hub);
    for(testid=read(),T=read();T--;){
        n=read(),lim=read(),ecnt=0;for(int i=1;i<=n;i++)head[i]=0;
        for(int i=1,u,v;i<n;i++)u=read(),v=read(),addEdge(u,v),addEdge(v,u);
        if(Subtask0::chk())Subtask0::main();
    }
    return 0;
}
/*
underthetime
680855
meow meow meow
>w<

*/