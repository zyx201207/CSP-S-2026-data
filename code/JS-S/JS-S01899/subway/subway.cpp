#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
int c, n, m, d, q;
vector<int> where[500005];
vector<int> line[505];
ll g[505][505], len[500005];
unordered_map<int, ll> a[505];
void init()
{
    int u, v;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) g[i][j] = INT_MAX;
    for(int i = 1; i <= n; i ++) g[i][i] = 0;
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 0; j < where[i].size(); j ++)
        {
            for(int k = j + 1; k < where[i].size(); k ++)
            {
                u = where[i][j], v = where[i][k];
                g[u][v] = min(g[u][v], a[u][i] + a[v][i]);
                g[v][u] = min(g[u][v], a[u][i] + a[v][i]);
            }
        }
    }
    for(int k = 1; k <= n; k ++)
    {
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    return;
}
int main()
{
    IOS;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++) cin >> len[i];
    for(int i = 1; i <= n; i ++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++)
        {
            int id, w;
            cin >> id >> w;
            line[i].push_back(id);
            where[id].push_back(i);
            a[i][id] = w;
        }
    }
    init();
    int s, t, u, v;
    ll ans = LLONG_MAX;
    while(q --)
    {
        ans = LLONG_MAX;
        cin >> s >> t;
        for(int i = 0; i < where[s].size(); i ++)
        {
            for(int j = 0; j < where[t].size(); j ++)
            {
                u = where[s][i], v = where[t][j];
                ans = min(ans, g[u][v] + a[u][s] + a[v][t]);
            }
        }
        cout << ans + len[s] + len[t] << "\n";
    }
    return 0;
}
