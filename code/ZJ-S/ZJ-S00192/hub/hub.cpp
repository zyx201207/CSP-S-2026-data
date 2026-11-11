#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=4e3+10;
constexpr int maxm=5e3+10;
constexpr int INF=1e18;
int n,c,T,k,ans,res,fa[maxn],dis[maxn][maxn];
int FA[maxn],siz[maxn],dep[maxn],top[maxn],son[maxn];
bool gra[maxn][maxn];
vector<int>g[maxn];
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
}
int findr(int x)
{
    return fa[x]==x?x:fa[x]=findr(fa[x]);
}
void join(int x,int y)
{
    int xr=findr(x),yr=findr(y);
    if(xr!=yr)
    {
        fa[xr]=yr;
    }
}
void dfs1(int u,int p)
{
    FA[u]=p;
    siz[u]=1;
    dep[u]=dep[p]+1;
    for(int v:g[u])
    {
        if(v==p)
        {
            continue;
        }
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v])
        {
            son[u]=v;
        }
    }
}
void dfs2(int u,int h)
{
    top[u]=h;
    if(son[u])
    {
        dfs2(son[u],h);
    }
    for(int v:g[u])
    {
        if(v==FA[u]||v==son[u])
        {
            continue;
        }
        dfs2(v,v);
    }
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])
        {
            swap(u,v);
        }
        u=FA[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}
int Dis(int u,int v)
{
    int l=lca(u,v);
    return dep[u]+dep[v]-2*dep[l];
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        ans=INF;
        if(k==1)
        {
            for(int i=1;i<=n;++i)
            {
                son[i]=0;
            }
            for(int i=1,u,v;i<n;++i)
            {
                scanf("%lld%lld",&u,&v);
                g[u].emplace_back(v);
                g[v].emplace_back(u);
            }
            dfs1(1,0);
            dfs2(1,1);
            for(int i=1;i<=n;++i)
            {
                int tmp=0;
                for(int j=1;j<=n;++j)
                {
                    if(i==j)
                    {
                        continue;
                    }
                    tmp=max(tmp,Dis(i,j));
                }
                ans=min(ans,tmp);
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                gra[i][j]=0;
                dis[i][j]=i==j?0ll:INF;
            }
        }
        for(int i=1,u,v;i<n;++i)
        {
            scanf("%lld%lld",&u,&v);
            gra[u][v]=gra[v][u]=1;
            dis[u][v]=dis[v][u]=1;
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }            
        }
        for(int i=0;i<(1ll<<n);++i)
        {
            if(__builtin_popcount(i)!=k)
            {
                continue;
            }
            vector<int>s,o;
            for(int j=0;j<n;++j)
            {
                if(i>>j&1)
                {
                    s.emplace_back(j+1);
                }
                else
                {
                    o.emplace_back(j+1);
                }
            }
            init(n);
            int cnt=0;
            for(int u=0;u<s.size();++u)
            {
                for(int v=0;v<u;++v)
                {
                    if(gra[s[u]][s[v]])
                    {
                        join(s[u],s[v]);
                    }
                }
            }
            for(int j:s)
            {
                if(fa[j]==j)
                {
                    ++cnt;
                }
            }
            if(cnt>2)
            {
                continue;
            }
            res=0;
            for(int u:o)
            {
                int tmp=INF;
                for(int v:s)
                {
                    tmp=min(tmp,dis[u][v]);
                }
                res=max(res,tmp);
            }
            ans=min(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
