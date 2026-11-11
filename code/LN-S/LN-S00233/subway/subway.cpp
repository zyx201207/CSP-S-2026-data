#include <bits/stdc++.h>
using namespace std;
int w[500005];
vector<pair<int,long long> > g[500005];//每个站台连接哪些线路 距离多少
long long dist[305][305];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int co,n,m,d,q,x,y;
    cin>>co>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=1e18;
        }
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",w+i);
    }
    for(int i=1;i<=n;i++)
    {
        int cnt;
        cin>>cnt;
        for(int j=1;j<=cnt;j++)
        {
            scanf("%d%d",&x,&y);
            pair<int,long long> t;
            t.first=i;
            t.second=y;
            g[x].push_back(t);
            for(int k=0;k<g[x].size()-1;k++)
            {
                pair<int,long long> s;
                s=g[x][k];
                dist[s.first][t.first]=dist[t.first][s.first]=min(dist[s.first][t.first],t.second+s.second);
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
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        long long ans=1e18;
        for(int j=0;j<g[x].size();j++)
        {
            for(int k=0;k<g[y].size();k++)
            {
                pair<int,long long> from=g[x][j];
                pair<int,long long> to=g[y][k];
                ans=min(ans,dist[from.first][to.first]+from.second+to.second);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}
