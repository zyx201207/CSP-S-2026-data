#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,w[500010],a[510][500010],t[510][500010],k[510],vis[500010];
struct node
{
   int to;
   long long w;
};
vector<node> e[500010];
struct work
{
    int id;
    long long d;
};
long long dis[500010];
bool operator < (work x,work y)
{
    return x.d>y.d;
}
void Dijkstra(int s)
{
    for(int i=1;i<=m;i++) dis[i]=500000000000010,vis[i]=0;
    priority_queue<work> q;
    q.push(work{s,0});
    dis[s]=0;
    while(!q.empty())
    {
        int x=q.top().id;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0;i<e[x].size();i++)
        {
            if(dis[x]+e[x][i].w<dis[e[x][i].to])
            {
                dis[e[x][i].to]=dis[x]+e[x][i].w;
                q.push(work{e[x][i].to,dis[e[x][i].to]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];

        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            for(int p=1;p<=k[i];p++) if(j!=p) e[a[i][j]].push_back(node{a[i][p],t[i][j]+t[i][p]});
        }
    }
    for(int i=1;i<=qq;i++)
    {
        int u,v;
        cin>>u>>v;
        Dijkstra(u);
        cout<<dis[v]+w[u]+w[v]<<endl;
    }
    return 0;
}
