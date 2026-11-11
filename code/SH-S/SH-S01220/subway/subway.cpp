#include <iostream>
#include <vector>
using i64 = long long;
const int maxn = 505;
const int maxm = 5e5 + 5;
const i64 INF = 1e18 + 5;

int w[maxm];
std::vector<std::pair<int, int>> station[maxm];
i64 g[maxn][maxn];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; ++i) std::cin >> w[i];

    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) g[i][j] = g[j][i] = INF;

    for(int i = 1; i <= n; ++i)
    {
        int k;
        std::cin >> k;

        for(int j = 1; j <= k; ++j)
        {
            int st, time;
            std::cin >> st >> time;
            
            for(auto v : station[st])
                if(time + v.second < g[i][v.first]) g[i][v.first] = g[v.first][i] = time + v.second;
            station[st].push_back({i, time});
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
            {
                if(k == i || k == j) continue;
                if(g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[j][i] =  g[i][k] + g[k][j]; 
            }

    for(int i = 1; i <= q; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        i64 ans = INF;
        for(auto i : station[x])
            for(auto j : station[y])
                ans = std::min(ans, g[i.first][j.first] + i.second + j.second);

        std::cout << ans + w[x] + w[y] << "\n";
    }
}
