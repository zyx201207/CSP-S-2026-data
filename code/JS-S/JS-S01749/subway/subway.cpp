#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<PI>v[500005];
ll dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,x,t;j<=k;j++)
        {
            cin>>x>>t;
            v[x].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=5e15;
    for(int i=1;i<=m;i++)
    {
        if(v[i].size()<=1)continue;
        for(int j=0;j<v[i].size();j++)
            for(int k=j+1;k<v[i].size();k++)
            {
                int x=v[i][j].first,y=v[i][k].first;
                ll wx=v[i][j].second,wy=v[i][k].second;
                dis[y][x]=dis[x][y]=min(dis[x][y],wx+wy);
            }
    }    
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            for(int j=i+1;j<=n;j++)
                if(i!=k&&j!=k)dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j]<<" ";
    //     cout<<endl;
    // }
    int x,y;
    ll ans=5e15;
    while(q--)
    {
        cin>>x>>y;
        ans=5e15;
        for(int i=0;i<v[x].size();i++)
            for(int j=0;j<v[y].size();j++)
                ans=min(ans,dis[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second+w[x]+w[y]);
        cout<<ans<<'\n';
    }
    return 0;
}
