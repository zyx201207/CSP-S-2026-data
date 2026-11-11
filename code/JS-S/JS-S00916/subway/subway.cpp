#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLII = pair<ll,pair<int,int> >;
const int N=505;

int c,n,m,d,q;
int k[N],a[N][N];
ll w[N],t[N][N];
vector<int> path[N];
int nxt[N][N];
int st,ed;
bool vis[N][N];
ll dist[N][N];

void dijkstra(int x)
{
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
            dist[i][j]=1e18;
    memset(vis,0,sizeof(vis));
    priority_queue<PLII> pq;
    dist[x][0]=0;
    pq.push({0,{0,x}});
    while(!pq.empty())
    {
        int u=pq.top().second.second;
        int lst=pq.top().second.first;
        pq.pop();
        //cerr<<u<<'\n';
        if(vis[u][lst])continue;
        vis[u][lst]=true;
        for(int p:path[u])
        {
            int v=nxt[p][u];
            //cerr<<p<<' '<<v;
            if(p==lst)
            {
                if(dist[u][lst]<dist[v][p])
                {
                    dist[v][lst]=dist[u][p];
                    pq.push({dist[v][p],{p,v}});
                }
            }
            else
            {
                if(dist[u][lst]+t[lst][u]+t[p][u]<dist[v][p])
                {
                    dist[v][p]=dist[u][lst]+t[lst][u]+t[p][u];
                    pq.push({dist[v][p],{p,v}});
                }
            }
            //cerr<<' '<<dist[v][p]<<'\n';
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%d",&a[i][j]);
            path[a[i][j]].push_back(i);
            scanf("%lld",&t[i][a[i][j]]);
            nxt[i][a[i][j-1]]=a[i][j];
        }
    }
    for(int r=1;r<=q;r++)
    {
        scanf("%d%d",&st,&ed);
        dijkstra(st);
        ll ans=1e18;
        for(int i=1;i<=n;i++)ans=min(ans,dist[ed][i]+t[i][ed]);
        printf("%lld\n",ans+w[st]+w[ed]);
    }
    return 0;
}

/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
