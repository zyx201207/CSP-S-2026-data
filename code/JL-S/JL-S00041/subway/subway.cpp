#include<bits/stdc++.h>
#define int long long
const int M = 5e5+10, inf = 1e12;
using namespace std;
int c, n, m, d, q, k, ans = inf;
int w[M];
int a[505][M], T;
int dis[505][505];
vector<int> tl[M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            cin >> a[i][j] >> T;
            tl[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j] = inf;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto line1:tl[i])
        {
            for(auto line2:tl[i])
            {
                if(line1 == line2)
                    dis[line1][line2] = 0;
                else dis[line1][line2] = 2 * T;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i == j) dis[i][j] = 0;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x, y;
        cin >> x >> y;
        ans = inf;
        for(auto j:tl[x])
        {
            for(auto k:tl[y])
            {
                // cout << j << ' ' << k << '\n';
                ans = min(ans, dis[j][k]);
            }
        }
        ans += 2 * T + w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}