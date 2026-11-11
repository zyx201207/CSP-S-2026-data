#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Inf=1e18;
int number,n,m,ma,Q;
int w[500005];
vector<pair<int,int>> g[500005];
int dis[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>number>>n>>m>>ma>>Q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=Inf;
    for(int i=1;i<=n;i++)dis[i][i]=0;
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
    for(int i=1;i<=m;i++)
        for(int j=0;j<g[i].size()-1;j++)
        {
            auto [u,du]=g[i][j];
            for(int jj=j+1;jj<g[i].size();jj++)
            {
                auto [v,dv]=g[i][jj];
                dis[u][v]=dis[v][u]=min(dis[u][v],du+dv);
            }
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            if(dis[i][k]==Inf)continue;
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    while(Q--)
    {
        int x,y,ans=Inf;
        cin>>x>>y;
        for(auto [u,du]:g[x])
            for(auto [v,dv]:g[y])
                ans=min(ans,du+dv+dis[u][v]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
