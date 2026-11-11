/*
CSP-S 2026 T2
Author:DFLJ

--I will win.

Passed at 15:27

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500001];
int G[501][501],dis[501][501];
vector<pair<int,int> > nG[500001];
void build()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) G[i][j]=1e18;
        G[i][i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        for(auto j : nG[i])
        {
            for(auto k : nG[i])
            {
                //if(j.first==k.first) continue;
                //cout<<j.first<<' '<<j.second<<' '<<k.first<<' '<<k.second<<'\n';
                G[j.first][k.first]=min(G[j.first][k.first],j.second+k.second);
                G[k.first][j.first]=G[j.first][k.first];
            }
        }
    }
}
void floyd()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) dis[i][j]=G[i][j];
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++) cin>>w[i];
    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            int a,t;
            cin>>a>>t;
            nG[a].push_back({i,t});
            //cout<<i<<' '<<t<<'\n';
        }
    }
    // for(auto i : nG[2])
    // {
    //     cout<<i.first<<' '<<i.second<<'\n';
    // }
    build();
    floyd();
    //cout<<G[1][2]<<'\n';
    while(q--)
    {
        int xr,yr;
        cin>>xr>>yr;
        long long ans=1e18;
        for(auto u : nG[xr])
        {
            for(auto v : nG[yr])
            {
                ans=min(ans,dis[u.first][v.first]*1ll+u.second+v.second);
            }
        }
        cout<<ans+w[xr]+w[yr]<<'\n';
    }
    return 0;
}
