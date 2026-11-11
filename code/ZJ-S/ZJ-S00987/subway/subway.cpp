#include <bits/stdc++.h>
const long long inf=1e17;
using namespace std;
long long c,n,m,d,q,w[500010],f[510][510];
struct edge{long long x,w;};
vector<edge>g[500010];
void as(int num)
    {
        for(long long i=0,x,y,w;i<g[num].size();i++)
            for(long long j=i+1;j<g[num].size();j++)
                {
                    x=g[num][i].x,y=g[num][j].x,w=g[num][i].w+g[num][j].w;
                    f[x][y]=f[y][x]=min(f[x][y],w);
                }
        return;
    }
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(long long i=1,len;i<=n;i++)
        {
            scanf("%lld",&len);
            for(long long j=1,x,w;j<=len;j++)
                {
                    scanf("%lld%lld",&x,&w);
                    g[x].push_back({i,w});
                }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)f[i][j]=inf;
    for(int i=1;i<=m;i++)as(i);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
        {
            long long x,y,ans=inf;
            scanf("%lld%lld",&x,&y);
            for(long long i=0,u,v,W;i<g[x].size();i++)
                for(long long j=0;j<g[y].size();j++)
                    {
                        u=g[x][i].x,v=g[y][j].x,W=g[x][i].w+g[y][j].w;
                        W=W+f[u][v];
                        ans=min(ans,W);
                    }
            ans+=w[x]+w[y];
            printf("%lld\n",ans);
        }
    return 0;
}
