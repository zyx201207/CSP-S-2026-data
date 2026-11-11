#include <bits/stdc++.h>
using namespace std;
const int N=501000;
int c,n,m,d,q;
long long w[N],dis[N];
bool vis[N];
vector<pair<int,long long>> edges[N];
void solve(int s)
{
    for(int i=1;i<=n+m;i++)
    {
        vis[i]=false;
        dis[i]=1e18;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(!vis[u])
        {
            vis[u]=true;
            for(auto i : edges[u])
            {
                int v=i.first;
                long long k=i.second;
                if(dis[v]>dis[u]+k)
                {
                    dis[v]=dis[u]+k;
                    q.push({dis[v],v});
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int k,x;
        long long y;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d%lld",&x,&y);
            edges[i+m].push_back({x,y});
            edges[x].push_back({i+m,y});
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        solve(x);
        printf("%lld\n",w[x]+dis[y]+w[y]);
    }
    return 0;
}
