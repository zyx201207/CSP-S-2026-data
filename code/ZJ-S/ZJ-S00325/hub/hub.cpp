#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
constexpr int inf=(LLONG_MAX>>1)-1ll;
int n,ans=inf;
vector<int> gra[maxn];
int vis[maxn],cho[maxn],d[maxn],dis[maxn];
void dfs0(int u,int p)
{
    vis[u]=1;
    for(int v:gra[u])
    {
        if(v==p||!cho[v]) continue;
        dfs0(v,u);
    }
}
int bfs(int s)
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=inf,vis[i]=0;
    }
    dis[s]=0;
    queue<int> q;
    q.emplace(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:gra[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.emplace(v);
            }
        }
    }
    int res=inf;
    for(int i=1;i<=n;++i)
    {
        if(cho[i])
        {
            res=min(res,dis[i]);
        }
    }
    return res;
}
void dfs(int x,int k)
{
    if(x==n+1)
    {
        if(k)
        {
            return ;
        }
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            vis[i]=0;
        }
        for(int i=1;i<=n;++i)
        {
            if(cho[i]&&(!vis[i]))
            {
                dfs0(i,0);
                ++cnt;
            }
        }
        if(cnt>2)
        {
            return ;
        }
        int res=0;
        for(int i=1;i<=n;++i)
        {
            if(!cho[i])
            {
                res=max(res,bfs(i));
            }
        }
        ans=min(ans,res);
        return ;
    }
    if(k)
    {
        cho[x]=1;
        dfs(x+1,k-1);
    }
    cho[x]=0;
    dfs(x+1,k);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int k;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        if(n<=20)
        {
            dfs(1,k);
            printf("%lld\n",ans);
            ans=inf;
        }
        else
        {
            printf("0\n");
        }
        for(int i=1;i<=n;++i)
        {
            gra[i].clear();
        }
    }
    return 0;
}
