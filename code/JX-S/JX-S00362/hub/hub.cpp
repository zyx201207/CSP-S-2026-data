#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>

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

void Solve()
{
    int n, k;
    std::cin >> n >> k;
    vec2<int> e(n + 1, vec<int>());
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vec<int> lit(n + 1, 0);
    vec<int> belong(n + 1, 0);
    vec<int> vis(n + 1, 0);
    auto DFS1 = [&](auto&& DFS1, int u, int fa) -> void
    {
        for (int v : e[u])
        {
            if (v == fa) continue;
            if (lit[u] == 1)
            {
                if (lit[fa] == lit[u]) belong[u] = belong[fa];
                else belong[u] = u;
            }
            DFS1(DFS1, v, u);
        }
    };
    int ans = MOD;
    for (int S = 0; S < (1 << n); S++)
    {
        int cnt = 0;
        lit.assign(n + 1, 0);
        for (int u = 1; u <= n; u++)
        {
            lit[u] = ((S >> (u - 1)) & 1);
            if (lit[u]) cnt++;
        }
        if (cnt != k) continue;
        belong.assign(n + 1, 0);
        std::set<int> cols;
        DFS1(DFS1, 1, 0);
        for (int u = 1; u <= n; u++)
        {
            if (belong[u] != 0) cols.insert(belong[u]);
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            vis.assign(n + 1, 0);
            std::queue<std::pair<int, int>> q;
            q.push({i, 0});
            vis[i] = 1;
            while (!q.empty())
            {
                int u = q.front().first, dis = q.front().second;
                q.pop();
                if (lit[u])
                {
                    res = std::max(res, dis);
                    break;
                }
                for (int v : e[u])
                {
                    if (vis[u]) continue;
                    vis[u] = 1;
                    q.push({v, dis + 1});
                }
            }
        }
        if (cols.size() <= 2)
        {
            ans = std::min(ans, res);
        }
    }
    std::cout << ans << '\n';
}

int main()
{

    // freopen("hub.in", "r", stdin);
    // freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int c, T;
    std::cin >> c >> T;
    while (T--) Solve();
    return 0;
}


