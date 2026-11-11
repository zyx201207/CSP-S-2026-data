#include<bits/stdc++.h>
using namespace std;
long long d[500010],dis[510][510];
vector<pair<int,long long>>v[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h,a,b,c,T;
    cin>>h>>a>>b>>c>>T;
    for(int i = 1;i<=b;i++)
    {
        cin>>d[i];
    }
    for(int i = 1;i<=a;i++)
    {
        for(int j = 1;j<=a;j++)
        {
            if(i!=j)
                dis[i][j]=1e18+9;
        }
    }
    for(int i = 1;i<=a;i++)
    {
        int z;
        cin>>z;
        for(int j = 1;j<=z;j++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back({i,y});
        }
    }
    for(int i = 1;i<=b;i++)
    {
        for(int j = 0;j<v[i].size()-1;j++)
        {
            for(int k = j+1;k<v[i].size();k++)
            {
                dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
                dis[v[i][k].first][v[i][j].first]=min(dis[v[i][k].first][v[i][j].first],v[i][j].second+v[i][k].second);
            }
        }
    }
    for(int i = 1;i<=a;i++)
    {
        for(int j = 1;j<=a;j++)
        {
            for(int k = 1;k<=a;k++)
            {
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    while(T--)
    {
        int x,y;
        long long ans = 1e18+9;
        cin>>x>>y;
        for(int i = 0;i<v[x].size();i++)
        {
            for(int j = 0;j<v[y].size();j++)
            {
                ans=min(ans,v[x][i].second+v[y][j].second+dis[v[x][i].first][v[y][j].first]);
            }
        }
        cout <<ans+d[x]+d[y]<<"\n";
    }
    return 0;
}
