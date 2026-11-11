#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e6+10;
constexpr int INF=(LLONG_MAX>>1)-1ll;
int c,t;
int n,k;
vector<int> gra[maxn];
bool vis[maxn];
int dis[maxn];
void bfs(int s)
{
    for(int i=1;i<=n;++i)
    {
        vis[i]=dis[i]=0;
    }
    queue<int> q;
    q.emplace(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:gra[u])
        {
            if(vis[v])
            {
                continue;
            }
            vis[v]=1;
            dis[v]=dis[u]+1;
            q.emplace(v);
        }
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        for(int i=1,u,v;i<n;++i)
        {
            scanf("%lld%lld",&u,&v);
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        bfs(1);
        int xx=0;
        int now=0;
        for(int i=1;i<=n;++i)
        {
            if(dis[i]>xx)
            {
                xx=dis[i];
                now=i;
            }
        }
        bfs(now);
        int len=0;
        for(int i=1;i<=n;++i)
        {
            len=max(len,dis[i]);
        }
        int ans=0;
        ++len;
        while((ans*2+1)*k<len)
        {
            ++ans;
        }
        for(int i=1;i<=n;++i)
        {
            vis[i]=dis[i]=0;
            gra[i].clear();
        }
        printf("%lld\n",ans);
    }
    return 0;
}

