#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 505;
const int M = 5e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int C, n, m, D, q, w[M];
ll dis[N][N];
vector<pair<int, int>> a[N];
vector<pair<int, int>> g[M];
void Main()
{
    cin >> C >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1, k; i <= n; i++)
    {
        cin >> k;
        a[i].resize(k);
        for (auto &x : a[i])
        {
            cin >> x.first >> x.second;
            g[x.first].emplace_back(i, x.second);
        }
        sort(a[i].begin(), a[i].end());
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        for (int j = i + 1; j <= n; j++)
        {
            auto l = a[i].begin();
            auto r = a[j].begin();
            ll res = inf;
            while (l != a[i].end() && r != a[j].end())
            {
                if (l->first == r->first)
                    res = min(res, (ll)l->second + r->second);
                if (l->first < r->first)
                    ++l;
                else
                    ++r;
            }
            dis[i][j] = dis[j][i] = res;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int x, y; q--;)
    {
        cin >> x >> y;
        ll res = inf;
        for (auto l : g[x])
        {
            for (auto r : g[y])
            {
                res = min(res, dis[l.first][r.first] + l.second + r.second);
            }
        }
        cout << res + w[x] + w[y] << endl;
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TaskCnt = 1;
    // cin >> TaskCnt;
    while (TaskCnt--)
        Main();
    return 0;
}