#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
using LL = long long;
using ULL = unsigned long long;

const int MAXN = 5e5 + 5;
const int MAXM = 505;
const int MAXD = 22;
const int MOD = 998244353;

struct Edge
{
    int v;
    LL w;
};
LL val[MAXN];
LL dis[MAXM][MAXM];
vec<Edge> sub[MAXN];
int main()
{

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    memset(dis, 0x3f, sizeof(dis));
    int c, m, n, d, q;
    std::cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> val[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int u, w;
            std::cin >> u >> w;
            sub[u].push_back({i, w});
        }
    }
    for (int u = 1; u <= n; u++)
    {
        for (int i = 0; i < sub[u].size(); i++)
        {
            int x = sub[u][i].v;
            LL w1 = sub[u][i].w;
            for (int j = i + 1; j < sub[u].size(); j++)
            {
                int y = sub[u][j].v;
                dis[x][y] = std::min(dis[x][y], w1 + sub[u][j].w);
                dis[y][x] = std::min(dis[y][x], w1 + sub[u][j].w);
            }
        }
    }
    for (int i = 1; i <= m; i++) dis[i][i] = 0;
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        LL ans = 2e18;
        for (Edge &a : sub[x])
        {
            LL w1 = a.w;
            for (Edge &b : sub[y])
            {
                ans = std::min(ans, dis[a.v][b.v] + w1 + b.w);
            }
        }
        std::cout << val[x] + val[y] + ans << '\n';
    }
    return 0;
}

