#include <bits/stdc++.h>
#define int long long
using namespace std;

vector < pair < int, int > > g[510005]; 
int dis[510005], c, n, m, d, q, w[500005];
bool vis[510005];

void Dijstra(int st)
{
    for (int i = 1; i <= n + m; i++)
    {
        dis[i] = 0x3f3f3f3f;
        vis[i] = 0;
    }
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > q;
    dis[st] = 0;
    q.push({0, st});
    while (!q.empty())
    {
        pair < int, int > now = q.top();
        // cout << now.second << '\n';
        q.pop();
        if (vis[now.second]) continue;
        vis[now.second] = 1;
        for (auto i : g[now.second])
            if (vis[i.second] == 0 && now.first + i.first < dis[i.second])
            {
                dis[i.second] = now.first + i.first;
                q.push({dis[i.second], i.second});
            }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            g[m + i].push_back({y, x});
            g[x].push_back({y, m + i});
        }
    }
    // for (int i = 1; i <= n + m; i++)
    // {
    //     cout << i << ":";
    //     for (auto j : g[i])
    //         cout << j.first << ' ' << j.second << "    ";
    //     cout << '\n'; 
    // }
    while (q--)
    {
        int st, lt;
        cin >> st >> lt;
        Dijstra(st);
        cout << dis[lt] + w[st] + w[lt] << '\n';
    }
    return 0;
}