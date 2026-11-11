#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q;
int w[500010];
int k;
vector<pair<int,int> > g[500010];
int f[510][510];
int inf = 1e17;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin >> a >> t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j) f[i][j] = inf;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(pair<int,int> x:g[i])
        {
            for(pair<int,int> y:g[i])
            {
                f[x.first][y.first] = min(f[x.first][y.first],x.second+y.second);
                f[y.first][x.first] = min(f[y.first][x.first],x.second+y.second);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin >> x >> y;
        int ans= inf;
        for(pair<int,int> a:g[x])
        {
            for(pair<int,int> b:g[y])
            {
                ans = min(ans, a.second + b.second + f[a.first][b.first]);
            }
        }
        ans = ans + w[x]+w[y];
        if(x==y) ans=0;
        cout << ans << endl;
    }
    return 0;
}