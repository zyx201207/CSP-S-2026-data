#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL N = 502, M = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
LL f[N][N], w[M];
vector<pair<int, LL>> e[M];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(f, 0x3f, sizeof(f));
    int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, t; cin >> a >> t;
            e[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int sz = e[i].size();
        for (int j = 0; j < sz; j++)
        {
            for (int k = j + 1; k < sz; k++)
            {
                auto &p1 = e[i][j], &p2 = e[i][k];
                LL val = p1.second + p2.second;
                if (f[p1.first][p2.first] > val) f[p1.first][p2.first] = f[p2.first][p1.first] = val;
            }       
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= q; i++)
    {
        int x, y; cin >> x >> y;
        LL ret = INF;
        int sz1 = e[x].size(), sz2 = e[y].size();
        for (int j = 0; j < sz1; j++)
            for (int k = 0; k < sz2; k++)
                ret = min(ret, e[x][j].second + e[y][k].second + f[e[x][j].first][e[y][k].first]);
        cout << w[x] + w[y] + ret << "\n";
    }
    return 0;
}