#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <unordered_map>
#define int long long
#define endl "\n"
using namespace std;
const int inf = 0x7fffffffffffffffLL >> 1;
int LINE = 500002;

inline int line(int n)
{
    return LINE + n;
}

struct node
{
    int v, w;
    bool operator<(node a) const
    {
        return v > a.v;
    }
};

int w[500005];
vector<int> station[500005];
unordered_map<int, int> t[500005];
int dis[502][502];
int gr[502][502];
vector<node> g[502];
bitset<500505> vis;

void Dijkstra(int s)
{
    priority_queue<node> q;
    for (int i = 1; i < 502; i++) dis[s][i] = inf;
    dis[s][s] = 0;
    q.push({s, 0});
    vis.reset();
    while (!q.empty())
    {
        int t = q.top().v;
        q.pop();
        if (vis[t])
            continue;
        vis[t] = true;
        for (node i : g[t])
        {
            if (dis[s][i.v] > dis[s][t] + i.w)
            {
                dis[s][i.v] = dis[s][t] + i.w;
                if (!vis[i.v]) q.push(i);
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int ki;
        cin >> ki;
        for (int j = 0; j < ki; j++)
        {
            int ai, ti;
            cin >> ai >> ti;
            station[ai].push_back(i);
            t[ai][i] = ti;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int x : station[i])
        {
            for (int y : station[i])
            {
                if (x == y) continue;
                dis[x][y] = min(dis[x][y], (int)t[i][x] + t[i][y]);
                dis[y][x] = dis[x][y];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] != inf)
            {
                g[i].push_back({j, dis[i][j]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        Dijkstra(i);
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int ans = inf;
        for (int i : station[x])
        {
            for (int j : station[y])
            {
                ans = min(ans, dis[i][j] + t[x][i] + t[y][j]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
