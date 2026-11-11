#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
const int N=1e3+1;
int n,k,ans=0;
bool vis[N];
int dfn[N],low[N],ord[N],tcnt=0,dis[N][N];
vector<int>g[N];
void tarjan(int u)
{
    dfn[++tcnt]=u;
    for(auto v:g[u])
    {
        if(dfn[v])continue;
        if(vis[v])tarjan(v);
    }
    return;
}
bool pd()
{
    int cl=0,siz=0;tcnt=0;
    for(int i=1;i<=n;++i)
    {
        dfn[i]=low[i]=0;
        if(!vis[i])continue;
        ord[++siz]=i;
    }
    for(int i=1;i<=k;++i)
        if(!dfn[ord[i]])tarjan(ord[i]),cl++;
    //for(int i=1;i<=siz;++i)cout<<ord[i]<<' ';cout<<":"<<cl;
    return cl<=2;
}
int calc()
{
    int maxd=0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i])continue;
        int tmpv=INT_MAX;
        for(int j=1;j<=n;++j)
            if(vis[j])tmpv=min(tmpv,dis[i][j]);
        maxd=max(maxd,tmpv);
    }
    //cout<<' '<<maxd<<endl;
    return maxd;
}
void dfs(int dep,int sm)
{
    if(dep>n)
    {
        if(sm==k)
        {
            if(pd())ans=min(ans,calc());
        }
        return;
    }
    vis[dep]=0;
    dfs(dep+1,sm);
    vis[dep]=1;
    if(sm+1<=k)dfs(dep+1,sm+1);
    vis[dep]=0;
}
void solve()
{
    cin>>n>>k;ans=INT_MAX;
    for(int i=1;i<n;++i)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i==j)dis[i][j]=0;
            else dis[i][j]=1e8;
        }
    for(int i=1;i<=n;++i)
        for(auto j:g[i])dis[i][j]=1;
    for(int kk=1;kk<=n;++kk)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
    }
    //if(n==10)for(int i=1;i<=n;++i)cout<<dis[5][i]<<' ';puts("");
    dfs(1,0);
    for(int i=1;i<=n;++i)g[i].clear();
    cout<<ans<<endl;
    return;
}
signed main()
{
#define FILE "hub"
freopen(FILE".in","r",stdin);
freopen(FILE".out","w",stdout);
cin.tie(0);cout.tie(0);
    int id,_;cin>>id>>_;
    while(_--)solve();
    return 0;
}