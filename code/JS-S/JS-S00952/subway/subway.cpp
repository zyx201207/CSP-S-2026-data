#include<bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;
int uid, n, m, d, Q, a[N][M], k[N], t[N][M], w[M];
long long dis[N][N];
vector<pair<int, long long> > q[M];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> uid >> n >> m >> d >> Q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            q[a[i][j]].push_back({i, t[i][j]});
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dis[i][j] = 1e18 + 10;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int k1 = 0;k1 < q[i].size();k1++)
        {
            for(int k2 = 0;k2 < q[i].size();k2++)
            {
                if(k1 == k2)
                {
                    continue;
                }
                dis[q[i][k1].first][q[i][k2].first] = min(dis[q[i][k1].first][q[i][k2].first], q[i][k1].second + q[i][k2].second);
                dis[q[i][k2].first][q[i][k1].first] = min(dis[q[i][k2].first][q[i][k1].first], q[i][k1].second + q[i][k2].second);
            }
        }
    }
    for(int kk = 1;kk <= n;kk++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][kk] + dis[kk][j]);
            }
            dis[i][i] = 0;
        }
    }
    for(int i = 1;i <= Q;i++)
    {
        int x, y;
        cin >> x >> y;
        long long ans = w[x] + w[y];
        long long cnt = 1e18 + 10;
        for(int k1 = 0;k1 < q[x].size();k1++)
        {
            for(int k2 = 0;k2 < q[y].size();k2++)
            {
                cnt = min(cnt, dis[q[x][k1].first][q[y][k2].first] + q[x][k1].second + q[y][k2].second);
            }
        }
        cout << ans + cnt << "\n";
    }
    return 0;
}

// 15:02 - 16:46