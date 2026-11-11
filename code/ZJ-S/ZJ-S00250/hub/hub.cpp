#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=1e18;
constexpr int maxn=1e6+10;
constexpr int maxk=30;
int n,k;
vector<int> gra[maxn];
int dep[maxn],fa[maxn][maxk];
int rt[maxn];

void init()
{
    for(int i=1;i<=n;++i) gra[i].clear();
}

void dfs(int u,int f)
{
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for(int v:gra[u])
    {
        if(v==f) continue;
        dfs(v,u);
    }
}

void st()
{
    int s=__lg(n);
    for(int i=1;i<=s;++i)
    {
        for(int j=1;j<=n;++j)
        {
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}

int lca(int u,int v)
{
    if(u==v) return u;

    if(dep[u]<dep[v]) swap(u,v);
    int s=dep[u]-dep[v];
    for(int i=__lg(s);i>=0;--i)
    {
        if(s>>i&1) u=fa[u][i];
    }

    if(u==v) return u;

    int t=__lg(dep[u]);
    for(int i=t;i>=0;--i)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

int dist(int u,int v)
{
    int l=lca(u,v);
    int res=dep[u]+dep[v]-2*dep[l];
    return res;
}

void init_()
{
    for(int i=1;i<=n;++i) rt[i]=i;
}

int fr(int u)
{
    if(u==rt[u]) return u;
    return rt[u]=fr(rt[u]);
}

void join(int u,int v)
{
    int ur=fr(u),vr=fr(v);
    if(ur!=vr) rt[ur]=vr;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin>>c>>t;

    while(t--)
    {
        cin>>n>>k;
        init();
        for(int i=1,u,v;i<=n-1;++i)
        {
            cin>>u>>v;
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }

        dfs(1,0);
        st();
        
        vector<int> it;
        auto check=[&]() -> bool
        {
            init_();
            int sz=it.size();
            for(int u:it)
            {
                for(int v:gra[u])
                {
                    auto x=lower_bound(it.begin(),it.end(),v)-it.begin();
                    if(x!=sz&&it[x]==v)
                    {
                        join(u,v);
                    }
                }
            }

            vector<bool> vis(n+1);
            for(int u:it)
            {
                vis[fr(u)]=1;
            }
            int cnt=0;
            for(int i=1;i<=n;++i) cnt+=vis[i];

            return cnt<=2;
        };
        
        int res=INF;
        for(int i=0;i<(1<<n);++i)
        {
            int cnt=__builtin_popcountll(i);
            if(cnt==k)
            {
                it.clear();
                for(int j=1;j<=n;++j)
                {
                    if(i>>j-1&1)
                    {
                        it.emplace_back(j);
                    }
                }

                if(check())
                {
                    vector<int> dis(n+1,INF);
                    int mxd=0;
                    for(int u=1;u<=n;++u)
                    {
                        for(int v:it)
                        {
                            dis[u]=min(dis[u],dist(u,v));
                        }
                        mxd=max(mxd,dis[u]);
                    }
                    res=min(res,mxd);
                }
            }
        }

        cout<<res<<'\n';
    }

    return 0;
}