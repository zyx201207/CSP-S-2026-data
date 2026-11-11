#include<bits/stdc++.h>
using namespace std;
int w[550000];
vector<pair<int,int> >v[550000];
int K[550000];
long long dis[550][550];
int main()
{
    int c,n,m,d,q;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&K[i]);
        for(int j=1;j<=K[i];j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(make_pair(i,y));
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)dis[i][j]=100000000000000000;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            for(int k=0;k<v[i].size();k++)
            {
                if(j==k)continue;
                int jj=v[i][j].first,kk=v[i][k].first;
                dis[jj][kk]=min(dis[jj][kk],1ll*v[i][j].second+v[i][k].second);
                dis[kk][jj]=dis[jj][kk];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=1000000000000000000;
        for(int i=0;i<v[x].size();i++)
        {
            for(int j=0;j<v[y].size();j++)
            {
                ans=min(ans,dis[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
}
