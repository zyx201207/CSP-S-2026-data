#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

constexpr int MN = 500, MM = 5e5, MD = 20;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
int W[MM + 10];
int K[MN + 10];
int cnt[MM + 10];
pii gp[MM + 10][MD + 10];
vector<pii> ed[MN + 10];
ll f[MN + 10][MN + 10];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", W + i);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", K + i);
        for (int j = 1; j <= K[i]; ++j)
        {
            int a, t;
            scanf("%d%d", &a, &t);
            gp[a][++cnt[a]] = {i, t};
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= cnt[i]; ++j)
        {
            for (int k = j + 1; k <= cnt[i]; ++k)
            {
                int u = gp[i][j].first;
                int v = gp[i][k].first;
                int w = gp[i][j].second + gp[i][k].second;
                ed[u].emplace_back(v, w);
                ed[v].emplace_back(u, w);
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        f[i][i] = 0;
        for (auto p : ed[i])
        {
            f[i][p.first] = p.second;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (f[j][i] != INF && f[i][k] != INF)
                {
                    f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
                }
            }
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = INF;
        for (int i = 1; i <= cnt[x]; ++i)
        {
            for (int j = 1; j <= cnt[y]; ++j)
            {
                int u = gp[x][i].first;
                int v = gp[y][j].first;
                int t1 = gp[x][i].second;
                int t2 = gp[y][j].second;
                ans = min(ans, f[u][v] + t1 + t2);
            }
        }
        ans += W[x] + W[y];
        printf("%lld\n", ans);
    }

    return 0;
}
