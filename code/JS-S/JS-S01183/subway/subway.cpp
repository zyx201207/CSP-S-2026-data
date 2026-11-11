#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF=1e18;
const int N=1510;
int n,m,c,D,Q;
int w[N];
int k;
int a,t,s;
bool vis[N];
ll d[N][N];
struct edge
{
    int v,l;
};
vector<edge> g[N];
struct node
{
    int pos;
    ll dis;
};
bool operator<(const node& x,const node& y)
{
    return x.dis>y.dis;
}
priority_queue<node> pq;

void dijkstra(int st,int ed)
{
    for(int i=1;i<=m+n;i++)
    {
        vis[i]=false;
        d[st][i]=INF;
    }
    d[st][st]=0;
    pq.push({st,0});
    while(!pq.empty())
    {
        int u=pq.top().pos;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(auto e:g[u])
        {
            if(d[st][e.v]>d[st][u]+e.l)
            {
                d[st][e.v]=d[st][u]+e.l;
                pq.push({e.v,d[st][e.v]});
            }
        }
    }
}

void Task1_11()
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d%d",&a,&t);
            g[m+i].push_back({a,t});
            g[a].push_back({m+i,t});
        }
    }
    while(Q--)
    {
        scanf("%d%d",&s,&t);
        if(!d[s][t]&&!d[t][s])
            dijkstra(s,t);
        printf("%lld\n",max(d[t][s],d[s][t])+w[s]+w[t]);
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    Task1_11();
    return 0;
}
