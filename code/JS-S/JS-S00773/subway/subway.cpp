#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[500005];
int dist[505][505];
vector<pair<int,int> > g[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++)dist[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto [p1,w1]:g[i])
        {
            for(auto [p2,w2]:g[i])
            {
                dist[p1][p2]=min(dist[p1][p2],w1+w2);
                dist[p2][p1]=min(dist[p2][p1],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=INF;
        for(auto [p1,w1]:g[u])
        {
            for(auto [p2,w2]:g[v])
            {
                ans=min(ans,w[u]+w1+dist[p1][p2]+w2+w[v]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
