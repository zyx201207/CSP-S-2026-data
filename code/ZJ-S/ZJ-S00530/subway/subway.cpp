#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

#define int long long

using std::cin;
using std::cout;
using std::min;
using std::queue;
using std::swap;
using std::vector;

const int N = 5e5, M = 5e5;

struct edge
{
    edge() {}
    edge(int to, int w) : to(to), w(w) {}
    int to, w;
};

int c, n, m, d, q;
int w[N + 10];
vector<int> sd[N + 10];
vector<edge> e[N + M + 10];
int dep[N + M + 10], fa[N + M + 10][30];
int dis[N + M + 10];
bool vis[N + M + 10];

struct node
{
    node() {}
    node(int x, int w) : x(x), w(w) {}
    bool operator<(node b) const { return w < w; }
    int x, w;
};

int spfa(int x, int y)
{
    memset(dis, 63, sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    vis[x] = 1;
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        vis[fr] = 0;
        for (auto i : e[fr])
        {
            if (dis[i.to] > dis[fr] + i.w)
            {
                dis[i.to] = dis[fr] + i.w;
                if (!vis[i.to])
                    q.push(i.to);
            }
        }
    }
    return dis[y];
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1, k; i <= m; i++)
    {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++)
            cin >> a >> t, sd[a].push_back(i), e[i].push_back(edge(m + a, t)), e[m + a].push_back(edge(i, t));
    }
    for (int i = 1, x, y; i <= q; i++)
    {
        cin >> x >> y;
        cout << spfa(x + m, y + m) + w[x] + w[y] << '\n';
    }
    return 0;
}

// void dfs(int x, int fa)
// {
//     dep[x] = dep[fa] + 1, ::fa[x][0] = fa;
//     // for (int j = 1; j <= 25; j++)
//     //     ::fa[x][j] = ::fa[::fa[x][j - 1]][j - 1];
//     for (auto i : e[x])
//     {
//         int to = i.to, w = i.w;
//         if (dep[to])
//             continue;
//         dfs(to, x);
//     }
// }
// int lca(int a, int b)
// {
//     if (dep[a] < dep[b])
//         swap(a, b);
//     for (int j = 25; j >= 0; j--)
//         if (dep[fa[a][j]] >= dep[b])
//             a = fa[a][j];
//     if (a == b)
//         return a;
//     for (int j = 25; j >= 0; j--)
//         if (fa[a][j] != fa[b][j])
//             a = fa[a][j], b = fa[b][j];
//     return fa[a][0];
// }