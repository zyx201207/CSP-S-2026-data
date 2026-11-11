#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int v,w;
    bool operator<(const node& other)const{return w>other.w;}
};
vector<int>g[5005];
int dijkstra(int s,int t)
{
    priority_queue<node>pq;
    pq.push({1,0});
    int sum[5005],flag[5005],d[5005];
    memset(d,0x3f3f3f3f,sizeof(d));
    sum[s]=1,d[s]=0;
    while(!pq.empty())
    {
        int u=pq.top().v;
        pq.pop();
        if(flag[u])continue;
        if(u==t)
        {
            sum[t]=(d[u]<d[t]?sum[u]:sum[t]+sum[u]);
            continue;
        }
        flag[u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]>d[u]+1)d[v]=d[u]+1,sum[v]=sum[u],pq.push({v,d[v]});
            else if(d[v]==d[u]+1)sum[v]+=sum[u];
        }
    }
    return (sum[t]==2?1:0);
}
int a[5005],t,c,n,d;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++)g[i].push_back(j);
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=dijkstra(i,j);
        cout<<ans<<'\n';
    }
    return 0;
}
