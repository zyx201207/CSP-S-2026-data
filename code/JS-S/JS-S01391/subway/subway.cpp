#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],t[505][500005],k[505],u,v,vis[500005];
vector<long long> g[505];
long long dfs(long long x,long long s,long long lx)
{
    vis[x]=s;
    if(x==v)
    {
        return 0;
    }
    int xs=INT_MAX,o;
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]!=lx)
        {
            for(int j=1;j<=m;j++)
            {
                if(j!=x&&t[g[x][i]][j])
                {
                    if(vis[j]>s+t[g[x][i]][x]+t[g[x][i]][j])
                    {
                        o=dfs(j,s+t[g[x][i]][x]+t[g[x][i]][j],g[x][i]);
                    }
                    xs=min(xs,o);
                }
            }
        }
    }
    return xs;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            long long x;
            scanf("%lld",&x);
            g[x].push_back(i);
            scanf("%lld",&t[i][x]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%lld %lld",&u,&v);
        memset(vis,0x7f,sizeof(vis));
        int p=dfs(u,0,0);
        printf("%lld\n",w[u]+w[v]+vis[v]);
    }
    return 0;
}
