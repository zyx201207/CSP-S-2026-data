#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5;
int c,n,m,d,q,g[maxn][25],di[maxn][25],cnt[maxn],w[maxn];
long long dis[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,b;
            cin>>a>>b;
            g[a][++cnt[a]]=i;
            di[a][cnt[a]]=b;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            for(int k=j+1;k<=cnt[i];k++)
            {
                if(di[i][j]+di[i][k]<dis[g[i][j]][g[i][k]])
                {
                    dis[g[i][j]][g[i][k]]=dis[g[i][k]][g[i][j]]=di[i][j]+di[i][k];
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        long long mini=1e18;
        for(int i=1;i<=cnt[u];i++)
            for(int j=1;j<=cnt[v];j++)
                mini=min(mini,w[u]+w[v]+di[u][i]+di[v][j]+dis[g[u][i]][g[v][j]]);
        cout<<mini<<"\n";
    }
}