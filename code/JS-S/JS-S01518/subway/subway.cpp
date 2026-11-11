#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll dis[505][505];
ll w[500005];
vector<pair<int,ll>>sta[500005];
void Floyd()
{
    memset(dis,0x3f,sizeof dis);
    for (int i = 1;i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1;k <= m; k++)
        for (int i = 0;i < sta[k].size(); i++)
            for (int j = 0;j < sta[k].size(); j++)
            {
                if (i == j)
                    continue;
                int x1,x2;
                ll d1,d2;
                x1 = sta[k][i].first;
                d1 = sta[k][i].second;
                x2 = sta[k][j].first;
                d2 = sta[k][j].second;
                dis[x1][x2] = min(dis[x1][x2],d1 + d2);
                dis[x2][x1] = min(dis[x2][x1],d1 + d2);
            }
    for (int k = 1;k <= n; k++)
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i = 1;i <= m; i++)
        scanf("%lld",w + i);
    for (int i = 1;i <= n; i++)
    {
        int k,x;
        ll t;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%lld",&x,&t);
            sta[x].push_back({i,t});
        }
    }
    Floyd();
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0;i < sta[x].size(); i++)
            for (int j = 0;j < sta[y].size(); j++)
            {
                int x1,x2;
                ll d1,d2;
                x1 = sta[x][i].first;
                d1 = sta[x][i].second;
                x2 = sta[y][j].first;
                d2 = sta[y][j].second;
                ans = min(ans,dis[x1][x2] + d1 + d2);
            }
        printf("%lld\n",ans + w[x] + w[y]);
    }
    return 0;
}