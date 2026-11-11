#include <bits/stdc++.h>
#define int long long
using namespace std;

static char puf[1<<20];
static signed len=0,pos=0;
inline signed gc(){
    if(len==pos)
    {
        len=(int)fread(puf,1,sizeof puf,stdin);
        pos=0;
        if(len==0) return EOF;
    }
    return puf[pos++];
}
template <typename T>
inline void read(T &x){
    x=0;
    signed f=1,c=gc();
    while(!isdigit(c))
    {
        if(c=='-') f=-1;
        c=gc();
    }
    while(isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=gc();
    }
    x*=f;
}

constexpr int maxn = 5e5+10;
constexpr int maxm = 2e6+10;

struct edge
{
    int to,nxt,w;
};

struct node
{
    int p,d;
    node(int a,int b):p(a),d(b) {}
    bool operator<(const node& x)const
    {
        return d>x.d;
    }
};

struct qqq
{
    int u,v,id;
    qqq()=default;
    qqq(int a,int b,int c):u(a),v(b),id(c) {}
    bool operator<(const qqq &x)const
    {
        return u<x.u;
    }
};

int c,n,m,d,q;
int wi[maxm];

edge edges[maxm];
int heads[maxm],enums;
int cnt;
inline void add(const int &x,const int &y,const int &w)
{
    edges[++enums]={y,heads[x],w};
    heads[x]=enums;
    edges[++enums]={x,heads[y],w};
    heads[y]=enums;
    ++cnt;
}
int dis[maxm];
priority_queue<node> pq;
inline void dj(int s)
{
    memset(dis,63,sizeof(int)*(m+n+10));
    dis[s]=0;
    pq.emplace(s,0);
    while(!pq.empty())
    {
        int u=pq.top().p;
        int d=pq.top().d;
        pq.pop();
        if(d>dis[u]) continue;
        for(int i=heads[u]; i ;i=edges[i].nxt)
        {
            int v=edges[i].to;
            int w=edges[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.emplace(v,dis[v]);
            }
        }
    }
}
qqq qwq[maxn];
int ans[maxn];
inline void bl()
{
    for(int i=1;i<=m;++i)
    {
        read(wi[i]);
        // add(i,i+m,w);
    }
    for(int i=1;i<=n;++i)
    {
        int k;
        read(k);
        for(int j=1,id,w ;j<=k;++j)
        {
            read(id),read(w);
            add(id,m+i,w);
        }
    }
    // cerr<<cnt;

    for(int i=1,u,v ;i<=q;++i)
    {
        read(u),read(v);
        qwq[i]={u,v,i};
    }
    sort(qwq+1,qwq+1+q);
    int lst=0;
    for(int i=1;i<=q;++i)
    {
        if(qwq[i].u!=lst)
        {
            lst=qwq[i].u;
            dj(lst);
        }
        ans[qwq[i].id]=dis[qwq[i].v]+wi[qwq[i].u]+wi[qwq[i].v];
    }
    for(int i=1;i<=q;++i)
    {
        printf("%lld\n",ans[i]);
    }
}

vector<bool> vis(maxm,0);

bool istr(int u,int p)
{
    vis[u]=1;
    for(int i=heads[u]; i ;i=edges[i].nxt)
    {
        int v=edges[i].to;
        if(v==p) continue;
        if(vis[v]) return 0;
        if(!istr(v,u))
        {
            return 0;
        }
    }
    return 1;
}

int siz[maxm],dep[maxm],fa[maxm],son[maxm];
int lon[maxm],top[maxm];

void dfs1(int u,int p)
{
    siz[u]=1;
    dep[u]=dep[p]+1;
    fa[u]=p;
    for(int i=heads[u]; i ;i=edges[i].nxt)
    {
        int v=edges[i].to;
        int w=edges[i].w;
        if(v==p) continue;
        lon[v]+=lon[u]+w;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v])
        {
            son[u]=v;
        }
    }
}

void dfs2(int u,int t)
{
    top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(int i=heads[u]; i ;i=edges[i].nxt)
    {
        int v=edges[i].to;
        if(v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}

inline int getlca(int u,int v)
{
    while(top[u]^top[v])
    {
        if(dep[top[u]]<dep[top[v]])
        {
            swap(u,v);
        }
        u=fa[top[u]];
    }
    return dep[u]>dep[v] ? v : u;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif // ONLINE_JUDGE

    read(c),read(n),read(m),read(d),read(q);
    if(q<=200)
    {
        bl();
        return 0;
    }

    for(int i=1;i<=m;++i)
    {
        read(wi[i]);
        // add(i,i+m,w);
    }
    for(int i=1;i<=n;++i)
    {
        int k;
        read(k);
        for(int j=1,id,w ;j<=k;++j)
        {
            read(id),read(w);
            add(id,m+i,w);
        }
    }

    if(istr(1,0))
    {
        dfs1(1,0);
        dfs2(1,1);

        for(int i=1,u,v,lca ;i<=q;++i)
        {
            read(u),read(v);
            lca=getlca(u,v);
            printf("%lld\n",lon[u]+lon[v]-lon[lca]*2+wi[u]+wi[v]);
        }
    }



    return 0;
}











