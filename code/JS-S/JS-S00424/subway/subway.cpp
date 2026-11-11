#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,x,y,d,q,w[500005],k;
vector <pair<int,int> > G[500005];
int dist[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int v,w;
        cin >> k;
        for (int j=1;j<=k;j++)
        {
            cin >> v >> w;
            G[v].push_back({i,w});
        }
    }
    memset(dist,0x3f,sizeof dist);
    for (int i=1;i<=m;i++)
    {
        for (auto j:G[i])
        {
            for (auto k:G[i])
            {
                if (j.first!=k.first)
                {
                    dist[j.first][k.first]=min(dist[j.first][k.first],j.second+k.second);
                }
                else dist[j.first][j.first]=0;
            }
        }
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i!=j)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while (q--)
    {
        cin >> x >> y;
        int res=LONG_LONG_MAX;
        for (auto i:G[x])
        {
            for (auto j:G[y])
            {
                res=min(res,w[x]+w[y]+i.second+j.second+dist[i.first][j.first]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
