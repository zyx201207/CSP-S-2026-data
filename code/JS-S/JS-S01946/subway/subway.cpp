#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], a[505][30], t[505][30], k[505], dist[10000000];
vector<pair<int, int>> g[500005];
int num;
int D(int x, int y)
{
    for (int i = 1; i <= num; i++) dist[i] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < g[x].size(); i++)
    {
        dist[g[x][i].first] = g[x][i].second;
        pq.push({g[x][i].first, g[x][i].second});
    }
    while(!pq.empty())
    {
        int a1 = pq.top().first, a2 = pq.top().second;
        pq.pop();
        if (dist[a1] != a2 && dist[a1] != INT_MAX) continue;
        for (int i = 0; i < g[a1].size(); i++)
        {
            if (g[a1][i].second + a2 < dist[g[a1][i].first])
            {
                dist[g[a1][i].first] = g[a1][i].second + a2;
                pq.push({g[a1][i].first, dist[g[a1][i].first]});
            }
        }
    }
    return dist[y];
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    num = m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (j != 1)
            {
                num++;
                g[num].push_back({a[i][j - 1], t[i][j - 1]});
                g[a[i][j - 1]].push_back({num, t[i][j - 1]});
                num++;
                g[num].push_back({a[i][j], t[i][j]});
                g[a[i][j]].push_back({num, t[i][j]});
                g[num].push_back({num - 1, 0});
                g[num - 1].push_back({num, 0});
            }
            if (j == k[i])
            {
                num++;
                g[num].push_back({a[i][1], t[i][1]});
                g[a[i][1]].push_back({num, t[i][1]});
                num++;
                g[num].push_back({a[i][j], t[i][j]});
                g[a[i][j]].push_back({num, t[i][j]});
                g[num].push_back({num - 1, 0});
                g[num - 1].push_back({num, 0});
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int ans = w[x] + w[y];
        ans += D(x, y);
        cout << ans << endl;
    }
    return 0;
}
