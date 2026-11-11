#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,w[500001],Map[501][501];
vector<array<int,2>>vec[500001];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                Map[i][j]=1e18;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,y;
            cin>>x>>y;
            vec[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++)
        for(auto&[u,w1]:vec[i])
            for(auto&[v,w2]:vec[i])
                Map[u][v]=min(Map[u][v],w1+w2);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                Map[i][j]=min(Map[i][k]+Map[k][j],Map[i][j]);
    while(q--)
    {
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto&[u,w1]:vec[x])
            for(auto&[v,w2]:vec[y])
                ans=min(ans,Map[u][v]+w1+w2);
        cout<<ans+w[x]+w[y]<<"\n";
    }
}