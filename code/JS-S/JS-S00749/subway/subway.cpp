#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int graph[505][505],a[500005];
vector<int>w[500005];
vector<int>edge[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    memset(graph,0x3f,sizeof graph);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        for(int j=0;j<k;j++)
        {
            int x,y;
            scanf("%lld %lld",&x,&y);
            edge[x].push_back(i);
            w[x].push_back(y);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<w[i].size();j++)
        {
            for(int k=0;k<w[i].size();k++)
                if(j!=k)
                {
                    graph[edge[i][j]][edge[i][k]]=w[i][j]+w[i][k];
                }
                else
                {
                    graph[edge[i][j]][edge[i][k]]=0;
                }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            {
                graph[i][j]=graph[j][i]=min(graph[i][j],graph[i][k]+graph[j][k]);
            }
    }
    for(int i=0;i<q;i++)
    {
        int u,v,ans=0x3f3f3f3f;
        scanf("%lld %lld",&u,&v);
        for(int j=0;j<w[u].size();j++)
            for(int k=0;k<w[v].size();k++)
            {
                ans=min(ans,graph[edge[u][j]][edge[v][k]]+w[u][j]+w[v][k]);
            }
        ans=ans+a[u]+a[v];
        printf("%lld\n",ans);
    }
    return 0;
}
