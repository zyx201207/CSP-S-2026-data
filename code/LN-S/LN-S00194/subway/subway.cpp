#include <bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
    bool operator<(const node& other)const{return w>other.w;}
};
int k,c,n,m,d1,q,w[505],flag[1000005],d[1000005];
vector<node>g[1000005];
int dijkstra(int s,int t)
{
    priority_queue<node>pq;
    pq.push({s,0});
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(flag,0,sizeof(flag));
    d[s]=0;
    while(!pq.empty())
    {
        int u=pq.top().v;
        pq.pop();
        if(flag[u])continue;
        flag[u]=1;
        if(u==t)return d[u];
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].v,w=g[u][i].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push({v,d[v]});
            }
        }
    }
    return -1;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d1>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,a,t;j<=k;j++)
        {
            cin>>a>>t;
            g[i+m].push_back({a,t});
            g[a].push_back({i+m,t});
        }
    }
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        cout<<dijkstra(s,t)+w[s]+w[t]<<'\n';
    }
    return 0;
}
