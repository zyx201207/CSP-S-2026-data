#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
vector<pair<int,int> >st[500005];
int e[505][505];
int dis[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        for(int j=1,a,t;j<=k;j++)
        {
            scanf("%lld%lld",&a,&t);
            st[a].push_back({i,t});
        }
    }
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++)e[i][i]=0;
    for(int i=1,l;i<=m;i++)
    {
        l=st[i].size();
        for(int j=0;j<l-1;j++)
        {
            for(int k=j+1;k<l;k++)
            {
                e[st[i][j].first][st[i][k].first]=
                e[st[i][k].first][st[i][j].first]=
                min(e[st[i][j].first][st[i][k].first],st[i][j].second+st[i][k].second);
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int s=1;s<=n;s++)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        pq.push({0,s});
        dis[s][s]=0;
        while(pq.size())
        {
            int u=pq.top().second;
            pq.pop();
            for(int v=1;v<=n;v++)
            {
                if(e[u][v]>1e10)continue;
                if(dis[s][u]+e[u][v]<dis[s][v])
                {
                    dis[s][v]=dis[s][u]+e[u][v];
                    pq.push({dis[s][v],v});
                }
            }
        }
    }
    while(q--)
    {
        int x,y,ans=9e18;
        scanf("%lld%lld",&x,&y);
        int l1=st[x].size();
        int l2=st[y].size();
        for(int j=0;j<l1;j++)
        {
            for(int k=0;k<l2;k++)
            {
                ans=min(ans,dis[st[x][j].first][st[y][k].first]+st[x][j].second+st[y][k].second+w[x]+w[y]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
