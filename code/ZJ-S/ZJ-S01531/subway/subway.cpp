#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 0x7f7f7f7f7f7f7f7fLL;
int c, n, m, d, q;
vector<long long> w;

vector<unordered_map<int, long long>> b;
vector<vector<long long>> dis;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    dis.resize(n + 1, vector<long long>(n + 1, INF));
    b.resize(m + 1);
    w.resize(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int u, val;
            cin >> u >> val;
            b[u][i] = val;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (auto line_1 : b[i])
        {
            for (auto line_2 : b[i])
            {
                if (line_1 == line_2)
                    continue;
                int line1 = line_1.first;
                int line2 = line_2.first;
                long long d1 = line_1.second;
                long long d2 = line_2.second;
                dis[line1][line2] = min(dis[line1][line2], d1 + d2);
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    for (int T = 1; T <= q; T++)
    {
        int u, v;
        cin >> u >> v;
        long long ans = INF;
        for (auto line_1 : b[u])
            for (auto line_2 : b[v])
            {
                int line1 = line_1.first;
                int line2 = line_2.first;
                long long wu = line_1.second;
                long long wv = line_2.second;
                ans = min(ans, dis[line1][line2] + wu + wv);
            }
        cout << (ans + w[u] + w[v]) << '\n';
    }
    return 0;
}