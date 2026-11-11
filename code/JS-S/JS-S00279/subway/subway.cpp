#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const int N = 505, M = 5e5 + 5;
ll c, n, m, d, q;
ll a[M], dis[N][N];
vector <pll> g[N + M], g1[5 * N];
unordered_map <ll, ll> tg[M];

inline void bfs(int s)
{
    priority_queue <pll, vector <pll>, greater <pll>> q;
    dis[s][s] = 0; q.push({0, s});
    while (!q.empty())
    {
        int h = q.top().second; q.pop();
        for (auto e : g1[h])
        {
            ll v = e.second, w = e.first;
            if (dis[s][v] > dis[s][h] + w)
            {
                dis[s][v] = dis[s][h] + w;
                q.push({dis[s][v], v});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ll x, pos, l;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> pos >> l;
            g[m + i].push_back({l, pos});
            g[pos].push_back({l, m + i});
            tg[pos][m + i] = l;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i + m])
        {
            int st = e.second;
            for (auto sub : g[st])
            {
                if (sub.second != i + m)
                {
                    g1[i].push_back({e.first + sub.first, sub.second - m});
                    g1[sub.second - m].push_back({e.first + sub.first, i});
                }
            }
        }
    }

    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) bfs(i);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = LLONG_MAX;
        for (auto ex : tg[x])
        {
            for (auto ey : tg[y])
            {
                ans = min(ans, (ex.second) + (ey.second) + dis[ex.first - m][ey.first - m]);
            }
        }
        cout << ans + a[x] + a[y] << '\n';
    }
    return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
