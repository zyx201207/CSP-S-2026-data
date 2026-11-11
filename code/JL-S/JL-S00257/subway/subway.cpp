#include <bits/stdc++.h>
using namespace std;
long long a[500005],dis[505][505];
struct node
{
    int v;
    long long w;
};
vector <node> mp[500005];
vector <node> sta[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&a[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        while(x--)
        {
            int u;
            long long w;
            scanf("%d%lld",&u,&w);
            sta[i].push_back({u,w});
            mp[u].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(node tmp:sta[i])
        {
            int u=tmp.v;
            for(node e:mp[u])
                dis[i][e.v]=min(dis[i][e.v],tmp.w+e.w);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        long long ans=1e18;
        for(node tmp:mp[s])
            for(node e:mp[t])
                ans=min(ans,tmp.w+e.w+dis[tmp.v][e.v]);
        printf("%lld\n",a[s]+a[t]+ans);
    }
    return 0;
}
