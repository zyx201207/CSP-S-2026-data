#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int N = 505, M = 5e5 + 5, inf = 1e18;
vector<pii> sta[M];
int dis[N][N], tim1[M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q;
    cin >> n >> n >> m >> q >> q;
    for (int i = 1; i <= m; i++)
        cin >> tim1[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, t;
            cin >> x >> t;
            sta[x].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = inf;
    for (int i = 1; i <= m; i++)
    {
        for (auto a : sta[i])
        {
            for (auto b : sta[i])
            {
                if (a.first == b.first)
                    continue;
                dis[a.first][b.first] = min(dis[a.first][b.first], a.second + b.second);
                dis[b.first][a.first] = min(dis[b.first][a.first], a.second + b.second);
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int x, y, ans = inf;
        cin >> x >> y;
        for (auto a : sta[x])
            for (auto b : sta[y])
                ans = min(ans, dis[a.first][b.first] + a.second + b.second);
        cout << ans + tim1[x] + tim1[y] << "\n";
    }
    return 0;
}