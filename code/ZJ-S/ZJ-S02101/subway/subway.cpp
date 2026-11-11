#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct node
{
    ll v,w;
};
vector<node>edges[1005];
ll w[200000];
ll a[200000],t[200000];
ll dis[1005],vis[1005];
void dijkstra(ll s)
{
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<ll,ll>>pq;
    dis[s]=0;
    pq.push({-dis[s],s});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto e:edges[u])
        {
            ll v=e.v,w=e.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({-dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++)
        {
            scanf("%d%d",&a[j],&t[j]);
        }
        for(ll u=1;u<=k;u++)
        {
            for(ll v=u+1;v<=k;v++)
            {
                edges[a[u]].push_back({a[v],t[u]+t[v]});
                edges[a[v]].push_back({a[u],t[u]+t[v]});
            }
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        dijkstra(x);
        printf("%d\n",dis[y]+w[x]+w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

