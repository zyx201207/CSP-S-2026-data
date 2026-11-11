#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int c,n,m,d,q,cnt,tot;
int head[5005],vis[5005];
long long w[500005],dist[5005][5005];
struct Edge
{
    int u,v,nex;
    long long w;
}e[6065];
void add(int u,int v,int w)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].nex=head[u];
    head[u]=cnt;
    return;
}
void dijkstra(int s)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    q.push({0,s});
    for(int i=1;i<=tot;i++) dist[s][i]=INF;
    dist[s][s]=0;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {

        int u=q.top().second;
        while(vis[u]&&!q.empty())
        {
//            cout<<u<<" ";
            q.pop();
            u=q.top().second;
        }
//        cout<<"\n";
//        cout<<u<<"\n";
//        if(u==10)
//        {
//            while(!q.empty())
//            {
//                cout<<q.top().second<<" ";
//                q.pop();
//            }
//        }
//        for(int i=1;i<=tot;i++) cout<<vis[i]<<" ";cout<<"\n";
        if(q.empty()) break;
        vis[u]=1;
//        cout<<u<<"\n";
        for(int i=head[u];~i;i=e[i].nex)
        {
            int v=e[i].v;
            long long dis=dist[s][u]+e[i].w;
//            cout<<v<<" "<<dis<<" "<<dist[s][u]<<" "<<dist[s][v]<<"\n";
            if(dis<dist[s][v])
            {
                dist[s][v]=dis;
                pair<long long,int> furina;
                furina.first=dis;
                furina.second=v;
                q.push(furina);
//                cout<<v<<" "<<dis<<'\n';
            }
        }
//        cout<<"\n\n\n";
        q.pop();
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if(c<=11)
    {
        tot=m;
        for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
//            cout<<"\nhutao\n";
            int u,t,x;
            for(int j=1;j<=k;j++)
            {
                scanf("%d%d",&u,&t);
//                cout<<j<<"\nfurina\n";
                add(u,++tot,t);
                add(tot,u,t);
                if(j!=1)
                {
                    add(tot,tot-1,0);
                    add(tot-1,tot,0);
                }
                x=u;
            }
        }
//        for(int i=1;i<=cnt;i++) cout<<i<<" "<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].nex<<"\n";
//        for(int i=1;i<=tot;i++) cout<<head[i]<<" ";cout<<"\n";
        for(int i=1;i<=m;i++)
        {
            dijkstra(i);
//            cout<<"\n\n\n";
        }
        for(int i=1;i<=q;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
 //           for(int i=1;i<=tot;i++) cout<<dist[s][i]<<" ";cout<<"\n";
            cout<<dist[s][t]+w[s]+w[t]<<"\n";
        }
    }
    return 0;
}
