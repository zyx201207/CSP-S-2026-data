#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e6+10;
constexpr int maxm=5e5+10;
constexpr int INF=(LLONG_MAX>>1)-1ll;
int dis[maxn];
bool vis[maxn];
vector<int>cun[maxn];

int val[maxm];
typedef struct edge 
{
int to,nxt,w;
}edge;
edge es[maxn];
int heads[maxn];
int enums;
void add_edge(int x,int y,int w)
{
    es[++enums]={y,heads[x],w};
    heads[x]=enums;
}
typedef struct node 
{
    int x,dis;
    bool operator<(const node &i)const 
    {
        return dis>i.dis;
    }
}node;
int n;
priority_queue<node>dq;
int m;
void dijkstra(int s)
{
while(!dq.empty())dq.pop();
for(int i=1;i<=m;++i)
{
vis[i]=0;
dis[i]=INF;
for(int j:cun[i]){dis[j+m*i]=INF;vis[j+m*i]=0;}
}
dis[s]=0;
dq.push((node({s,0ll})));
while(!dq.empty())
{
    int u=dq.top().x;
    dq.pop();
    if(vis[u])continue;
    vis[u]=1;
    for(int i=heads[u];i;i=es[i].nxt)
    {
        int v=es[i].to,w=es[i].w;
        if(dis[v]>dis[u]+w)
        {
            dis[v]=dis[u]+w;
            dq.push(node({v,dis[v]}));
        }
    }
}
}
signed main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int c,d,q,u,v,w,last=-1,k,ans=INF;
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;++i)cin>>val[i];
for(int i=1;i<=n;++i)
{
    cin>>k;
    last=-1;
    for(int j=1;j<=k;++j)
    {
        cin>>u>>w;
cun[i].emplace_back(u);
if(j>1) add_edge(last+m*i,u+m*i,0);
last=u;
add_edge(last+m*i,last,w);
add_edge(last,last+m*i,w);
    }
}   
for(int i=1;i<=q;++i)
{
cin>>u>>v;
dijkstra(u);
cout<<val[u]+val[v]+dis[v]<<'\n';
}
return 0;
}