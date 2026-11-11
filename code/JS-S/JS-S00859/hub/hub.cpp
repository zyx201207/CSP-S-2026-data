#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
#define off ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fi first
#define se second
using namespace std;
const int N=1000005;
const int M=1005;
const int Q=100005;
/*int c,t,n,k,dep,mk[N],dfn[N],top[N],idx,f[N],sz[N],son[N],m,dis[N],st,ed,rt;
vector<int>a[N],vs,pth;
void ldfs1(int u,int fa)
{
    dis[u]=dis[fa]+1;
    if(dis[u]>dis[m])
    {
        m=u;
    }
    for(int v:a[u])
    {
        if(v!=fa)
        {
            ldfs1(v,u);
        }
    }
}
bool ldfs2(int u,int fa)
{
    if(u==ed)
    {
        pth.push_back(u);
        return 1;
    }
    bool f=0;
    for(int v:a[u])
    {
        if(v!=fa)
        {
            f=(f||ldfs2(v,u));
        }
    }
    if(f)
    {
        pth.push_back(u);
    }
    return f;
}
void pdfs1(int u,int fa)
{
    dep[u]=dep[fa]+1;
    sz[u]=1;
    f[u]=fa;
    for(int v:a[u])
    {
        if(v!=fa)
        {
            pdfs1(v,u);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u])
            {
                son[u]=v;
            }
        }
    }
}
void pdfs2(int u,int ftop)
{
    dfn[u]=++idx;
    top[u]=ftop;
    if(son[u])
    {
        pdfs2(son[u],ftop);
    }
    for(int v:a[u])
    {
        if(v!=f[u]&&v!=son[u])
        {
            pdfs2(v,v);
        }
    }
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])
        {
            v=f[top[v]];
        }
        else
        {
            u=f[top[u]];
        }
    }
    return (dep[u]<dep[v]?u:v);
}
int dfs1(int u,int fa,int x)
{
    int mx=0;
    for(int v:a[u])
    {
        if(v!=fa)
        {
            mx=max(mx,dfs1(v,u));
        }
    }
    if(mx==0)
    {
        return dep[u];
    }
    if(x==mx-dep[u])
    {
        mk[u]=1;
        vs.push_back(u);
    }
    return dep[u];
}

bool check(int x)
{
    vs.clear();
    for(int i=1;i<=n;i++)
    {
        mk[i]=0;
    }
    if(dfs1(rt,0)<=x)
    {
        return 1;
    }
    int flag=0;
    for(int u:vs)
    {
        if(dep[u]-dep[rt]<=x)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        dfs2(rt,0);
    }
}*/
int n,c,t,k,dis[M][M],mk[N],f[N],ans,st,ed,m,dp[N];
vector<int>a[N],pth;
void dfs(int u,int fa,int st)
{
    dis[st][u]=dis[st][fa]+1;
    for(int v:a[u])
    {
        if(v!=fa)
        {
            dfs(v,u,st);
        }
    }
}
int findroot(int x)
{
    if(x==f[x])
    {
        return x;
    }
    return f[x]=findroot(f[x]);
}
void join(int u,int v)
{
    u=findroot(u);
    v=findroot(v);
    if(u!=v)
    {
        f[u]=v;
    }
}
bool check(int st)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        if((1<<i-1)&st)
        {
            mk[i]=1;
            cnt++;
        }
        else
        {
            mk[i]=0;
        }
    }
    if(cnt!=k)
    {
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(mk[i])
        {
            for(int v:a[i])
            {
                if(mk[v])
                {
                    join(i,v);
                }
            }
        }
    }
    set<int>stt;
    for(int i=1;i<=n;i++)
    {
        if(mk[i])
        {
            stt.insert(findroot(i));
        }
    }
    return stt.size()<=2;
}
void ldfs1(int u,int fa)
{
    dp[u]=dp[fa]+1;
    if(dp[u]>dp[m])
    {
        m=u;
    }
    for(int v:a[u])
    {
        if(v!=fa)
        {
            ldfs1(v,u);
        }
    }
}
bool ldfs2(int u,int fa)
{
    if(u==ed)
    {
        pth.push_back(u);
        return 1;
    }
    bool f=0;
    for(int v:a[u])
    {
        if(v!=fa)
        {
            f=(f||ldfs2(v,u));
        }
    }
    if(f)
    {
        pth.push_back(u);
    }
    return f;
}
signed main()
{
    off;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c<=3)
    {
        while(t--)
        {
            cin>>n>>k;
            /*for(int i=1;i<=n;i++)
            {
                a[i].clear();
                dep[i]=0;
                dis[i]=0;
                m=0;
            }
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
            ldfs1(1,0);
            for(int i=1;i<=n;i++)
            {
                dis[i]=0;
            }
            st=m;
            ldfs1(m,0);
            ed=m;
            ldfs2(st,0);
            rt=pth[pth.size()/2];
            pdfs1(rt,0);
            pdfs2(rt,rt);
            int L=-1,R=n;
            while(L+1<R)
            {
                int mid=L+R>>1;
                if(check(mid))
                {
                    R=mid;
                }
                else
                {
                    L=mid;
                }
            }*/
            for(int i=1;i<=n;i++)
            {
                a[i].clear();
            }
            ans=n;
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
            for(int i=1;i<=n;i++)
            {
                dfs(i,0,i);
            }
            for(int st=0;st<(1<<n);st++)
            {
                if(!check(st))
                {
                    continue;
                }
                int mx=0;
                for(int i=1;i<=n;i++)
                {
                    int mn=n;
                    for(int j=1;j<=n;j++)
                    {
                        if((1<<j-1)&st)
                        {
                            mn=min(mn,dis[i][j]);
                        }
                    }
                    mx=max(mx,mn);
                }
                ans=min(ans,mx);
            }
            cout<<ans-1<<'\n';
        }
    }
    else if(c==7)
    {
        while(t--)
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++)
            {
                a[i].clear();
            }
            ans=n;
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
            for(int i=1;i<=n;i++)
            {
                dfs(1,0,1);
            }
            ldfs1(1,0);
            st=m;
            ldfs1(m,0);
            ed=m;
            pth.clear();
            ldfs2(st,0);
            for(int i=0,j=pth.size()-1;i<j;i++,j--)
            {
                int mx=0;
                for(int k=1;k<=n;k++)
                {
                    mx=max(mx,min(dis[pth[i]][k],dis[pth[i]][k]));
                }
                ans=min(ans,mx);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
//file memory long long
