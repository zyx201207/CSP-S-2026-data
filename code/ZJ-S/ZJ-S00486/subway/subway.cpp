#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
const int MAXN = 505;
const int MAXK = 5e5+5, MAXM = 5e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
inline ll min(ll a, ll b) { return a < b ? a : b; }

ll c, n, m, d, q;
ll w[MAXM];
ll f[MAXN][MAXN];
// ll f[5][5] = {
//         {},
//         {0, 0, inf, 100, 1},
//         {0, inf, 0, 1, inf},
//         {0, 100, 1, 0, 1},
//         {0, 1, inf, 1, 0}
//     };
pii e[MAXM][25];

inline void flyd()
{
    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        if(f[i][k] != inf && f[k][j] != inf) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
}

inline void solve()
{
    int u, v; ll ans = 0x3f3f3f3f3f3f3f3f;
    scanf("%d%d", &u, &v);
    for(int i = 1; i <= e[u][0].first; i++)
    {
        ll cur;
        for(int j = 1; j <= e[v][0].first; j++)
        {
            // if(e[u][i].first != e[v][j].first) continue;
            cur = f[e[u][i].first][e[v][j].first] + e[u][i].second + e[v][j].second;
            // cout<<f[e[u][i].first][e[v][j].first]<<' '<<e[u][i].second<<' '<<e[v][j].second<<endl;
            ans = min(ans, cur);
        }
    }
    // printf("%lld ", ans);
    printf("%lld\n", ans + w[u] + w[v]);
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= 500; i++) f[i][i] = 0;

    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
    {
        scanf("%lld", &w[i]);
    }
    for(int i = 1, k; i <= n; i++)
    {
        int a, t;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++)
        {
            scanf("%d%d", &a, &t);
            e[a][++e[a][0].first] = pii(i, t);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int u = 1; u <= e[i][0].first; u++)
        for(int v = u+1; v <= e[i][0].first; v++)
        {
            f[e[i][u].first][e[i][v].first] = f[e[i][v].first][e[i][u].first] = 
                min(f[e[i][v].first][e[i][u].first], (ll)e[i][u].second + e[i][v].second);
        }
    }


    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++) printf("%lld ", f[i][j]);
    //     printf("\n");
    // }
    // n = 4;
    flyd();
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++) printf("%lld ", f[i][j]);
    //     printf("\n");
    // }

    for(; q--; ) solve();

    return 0;
}
