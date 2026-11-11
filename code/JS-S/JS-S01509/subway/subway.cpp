#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define xx first
#define yy second
int C,n,m,d,q;
int dis[505][505],a[500005];
vector<pii> g[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    cin>>C>>n>>m>>d>>q;
    memset(dis,63,sizeof(dis));
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int cnt;
        cin>>cnt;
        dis[i][i]=0;
        while(cnt--)
        {
            int u,t;
            cin>>u>>t;
            g[u].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        for(int j=0;j<g[i].size();j++)
        {
            u=g[i][j].xx;
            for(int k=0;k<g[i].size();k++)
            {
                v=g[i][k].xx,c=g[i][j].yy+g[i][k].yy;
                dis[u][v]=min(dis[u][v],c),dis[v][u]=dis[u][v];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--)
    {
        int u,v,ans=1e18,uu,vv,c;
        cin>>u>>v;
        for(int i=0;i<g[u].size();i++)
        {
            uu=g[u][i].xx;
            for(int j=0;j<g[v].size();j++)
            {
                vv=g[v][j].xx,c=g[u][i].yy+g[v][j].yy;
                ans=min(ans,dis[uu][vv]+c);
            }
        }
        cout<<ans+a[u]+a[v]<<'\n';
    }
    return 0;
}
