#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
using namespace std;
inline int read()
{
    int x=0,zf=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')zf=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*zf;
}
inline void print(int x)
{
    if(x==0)
    {
        putchar('0');
        return;
    }
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    char buf[20];
    int h=0;
    while(x)
    {
        buf[h]=x%10+'0';
        ++h;
        x/=10;
    }
    while(h--)putchar(buf[h]);
}
inline void princh(cint x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=1e6,LGN=20;
int n,k,d,rt;
vector<int>to[N+1];
int dep[N+1],mxdep[N+1],mxl[N+1];
int fa[LGN+1][N+1];
int top[N+1];
vector<int>lson[N+1],lfa[N+1],son[N+1];
int f[N+1],g[N+1],pf[N+1],pg[N+1];
int dfn[N+1],idx[N+1];
struct Spare_Table{
    inline int cmin(cint x,cint y)
    {
        return (dep[x]<dep[y]?x:y);
    }
    int st[LGN+1][N+1];
    void init()
    {
        for(int i=1;i<=n;++i)
        {
            st[0][i]=fa[0][dfn[i]];
        }
        for(int k=1;k<=LGN;++k)
        {
            for(int i=1;i<=n-(1<<k)+1;++i)
            {
                st[k][i]=cmin(st[k-1][i],st[k-1][i+(1<<k-1)]);
            }
        }
    }
    inline int ask(cint l,cint r)
    {
        cint p=__lg(r-l+1);
        return cmin(st[p][l],st[p][r-(1<<p)+1]);
    }
}ST;
inline int lca(cint u,cint v)
{
    if(u==v)return u;
    return ST.ask(min(idx[u],idx[v])+1,max(idx[u],idx[v]));
}
inline void add_edge(cint u,cint v)
{
    to[u].push_back(v);
    to[v].push_back(u);
}
inline int kfa(int u,int k)
{
    // cerr<<"kfa("<<u<<','<<k<<")\n";
    if(k<=0)return u;
    int p=__lg(k);
    u=fa[p][u];
    k-=(1<<p);
    cint v=top[u];
    if(dep[u]-dep[v]>=k)return lson[v][dep[u]-dep[v]-k];
    return lfa[v][k-dep[u]+dep[v]];
}
inline int kth(cint u,cint v,cint k)
{
    // cerr<<"kth("<<u<<','<<v<<','<<k<<")=";
    cint c=lca(u,v);
    // cerr<<"lca="<<c<<'\n';
    // cerr<<dep[u]-dep[c]<<' '<<k<<'\n';
    int res;
    if(dep[u]-dep[c]>=k)res=kfa(u,k);
    // cerr<<"e2\n";
    // cerr<<dep[u]<<' '<<dep[v]<<' '<<dep[c]<<'\n';
    else res=kfa(v,dep[u]+dep[v]-(dep[c]<<1)-k);
    // cerr<<res<<'\n';
    return res;
}
namespace INIT{
    void getd(cint u,cint fu)
    {
        fa[0][u]=fu;
        dep[u]=dep[fu]+1;
        for(int v:to[u])if(v!=fu)getd(v,u);
    }
    int tot;
    void dfs(cint u,cint fu)
    {
        dfn[idx[u]=++tot]=u;
        fa[0][u]=fu;
        for(int i=1;i<=LGN;++i)fa[i][u]=fa[i-1][fa[i-1][u]];
        dep[u]=dep[fu]+1;
        mxdep[u]=dep[u];
        lson[u].clear();
        lfa[u].clear();
        son[u].clear();
        for(int v:to[u])
        {
            if(v==fu)continue;
            dfs(v,u);
            son[u].push_back(v);
            mxdep[u]=max(mxdep[u],mxdep[v]);
        }
        if(u==rt)
        {
            sort(son[u].begin(),son[u].end(),[&](cint x,cint y){return mxdep[x]>mxdep[y];});
        }
        else for(int &v:son[u])
        {
            if(mxdep[v]>mxdep[son[u][0]])swap(v,son[u][0]);
        }
        mxl[u]=0;
        for(int v:son[u])
        {
            if(v==son[u][0])continue;
            mxl[u]=max(mxl[u],mxdep[v]-dep[u]);
        }
    }
    void main()
    {
        getd(1,0);
        int p=1;
        for(int i=1;i<=n;++i)if(dep[i]>dep[p])p=i;
        getd(p,0);
        int q=1;
        for(int i=1;i<=n;++i)if(dep[i]>dep[q])q=i;
        d=(dep[q]-1)>>1;
        int u=q;
        for(int i=1;i<=(dep[q]>>1);++i)u=fa[0][u];
        rt=u;
        tot=0;
        dfs(rt,0);
        for(int i=1;i<=n;++i)
        {
            if(i==rt||son[fa[0][i]][0]!=i)
            {
                int u=i,v=i;
                lson[i].push_back(i);
                lfa[i].push_back(i);
                top[i]=i;
                while(!son[u].empty())
                {
                    u=son[u][0];
                    v=fa[0][v];
                    top[u]=i;
                    lson[i].push_back(u);
                    lfa[i].push_back(v);
                }
            }
        }
        ST.init();
        // for(int i=1;i<=n;++i)
        // {
        //     cerr<<"dep"<<i<<":"<<dep[i]<<'\n';
        // }
    }
}
namespace STEP1{
    void dfsf(cint u)
    {
        for(int v:son[u])dfsf(v);
        f[u]=1;
        for(int v:son[u])
        {
            if(mxdep[v]-dep[u]>d)f[u]+=f[v];
        }
    }
    void dfsg(cint u)
    {
        if(son[u].empty())return;
        int s=g[u]+f[u];
        for(int v:son[u])
        {
            if(mxdep[v]-dep[u]>d)g[v]=s-f[v];
            else g[v]=s;
            dfsg(v);
        }
    }
    void main()
    {
        // cerr<<"STEP1\n";
        dfsf(rt);
        g[rt]=0;
        dfsg(rt);
        // for(int i=1;i<=n;++i)
        // {
        //     cerr<<i<<":("<<f[i]<<','<<g[i]<<")\n";
        // }
    }
}
namespace STEP2{
    void dfsf(cint u)
    {
        for(int v:son[u])
        {
            dfsf(v);
        }
        if(son[u].empty())
        {
            pf[u]=u;
            return;
        }
        pf[u]=pf[son[u][0]];
        while(pf[u]!=u&&dep[pf[u]]-dep[u]>d-mxl[u])pf[u]=fa[0][pf[u]];
    }
    void dfsg(cint u)
    {
        // cerr<<u<<":\n";
        if(son[u].empty())return;
        if(u==rt)
        {
            int cmx=0;
            for(int i=2;i<son[u].size();++i)
            {
                cmx=max(cmx,mxdep[son[u][i]]-1);
            }
            pg[son[u][0]]=kth(u,pf[son[u][1]],d-cmx);
            pg[son[u][1]]=kth(u,pf[son[u][0]],d-cmx);
            cint res=kth(u,pf[son[u][0]],d-mxl[u]);
            for(int i=2;i<son[u].size();++i)
            {
                pg[son[u][i]]=res;
            }
            for(int v:son[u])dfsg(v);
            return;
        }
        int mp,cp;
        cint md=mxdep[u]-dep[u];
        if(md>=d)mp=u;
        else mp=kth(u,pg[u],d-md);
        if(mxl[u]>=d)cp=u;
        else cp=kth(u,pg[u],d-mxl[u]);
        for(int v:son[u])
        {
            if(v==son[u][0])pg[v]=cp;
            else pg[v]=mp;
        }
        for(int v:son[u])dfsg(v);
    }
    void main()
    {
        // cerr<<"STEP2\n";
        dfsf(rt);
        dfsg(rt);
        // for(int i=1;i<=n;++i)
        // {
        //     cerr<<"p"<<i<<":("<<pf[i]<<','<<pg[i]<<")\n";
        // }
    }
}
bool check(cint x)
{
    // cerr<<"x="<<x<<'\n';
    int ans=n;
    d=x;
    STEP1::main();
    STEP2::main();
    for(int i=1;i<=n;++i)
    {
        if(i==rt)continue;
        // cerr<<"ans"<<i<<":"<<(lca(i,pg[i])==rt&&pg[i]!=rt?f[pg[i]]:g[kth(pg[i],i,1)])<<"\n";
        ans=min(ans,f[pf[i]]+(lca(i,pg[i])==rt&&pg[i]!=rt?f[pg[i]]:g[kth(pg[i],i,1)]));
    }
    return (ans<=k);
}
void solve()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=1;i<n;++i)add_edge(read(),read());
    if(n==2)
    {
        princh(0,'\n');
        return;
    }
    INIT::main();
    int l=0,r=d;
    while(l<r)
    {
        cint mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    princh(l,'\n');
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read();
    int T=read();
    while(T--)solve();
    return 0;
}