#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=1e18;

ll g[505][505],dis[505][505];
ll w[500005];
vector<pair<ll,ll>> sta[500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            ll a,t;
            cin>>a>>t;
            sta[a].push_back({i,t});
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                g[i][j]=INF;
    
    for(int i=1;i<=m;i++)
    {
        if(sta[i].size()<=1) continue;
        for(auto j:sta[i])
            for(auto k:sta[i])
            {
                if(j==k) continue;
                ll u=j.first,v=k.first,w=j.second+k.second;
                g[u][v]=min(g[u][v],w);
                g[v][u]=g[u][v];
            }
    }

    //floyd
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(g[i][k]==INF || g[k][j]==INF) continue;
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                g[j][i]=min(g[j][i],g[k][i]+g[j][k]);
            }
    
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;

        ll ans=INF;
        for(auto j:sta[x])
            for(auto k:sta[y])
            {
                ll u=j.first,v=k.first,w=j.second+k.second;
                ans=min(ans,w+g[u][v]);
            }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}