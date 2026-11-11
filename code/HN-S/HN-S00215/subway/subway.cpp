#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int f[505][505], w[N], k[505];
vector<int> sta[N];//i 号站有哪些线路
map<int, int> mp[505];//mp[i][j] = i号线到j站台的距离
int T, n, m, d, q;
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    for(int i = 0; i < 505; i ++) for(int j = 0; j < 505; j ++) f[i][j] = 2e16;

    cin >> T >> n >> m >> d >> q;

    for(int i = 1; i <= m; i ++)
    {
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &k[i]);
        for(int j = 1; j <= k[i]; j ++)
        {
            pair<int, int> p;
            scanf("%lld %lld", &p.first, &p.second);
            mp[i][p.first] = p.second;
            sta[p.first].push_back(i);
        }
    }
    for(int i = 1; i <= n; i ++) f[i][i] = 0;
    for(int i = 1; i <= m; i ++)
    {
        for(int u : sta[i])
        {
            for(int v : sta[i])
            {
                if(u == v) continue;
                f[u][v] = min(f[u][v], mp[u][i] + mp[v][i]);
                f[v][u] = min(f[v][u], mp[u][i] + mp[v][i]);
            }
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(i == j)
            {
                f[i][j] = 0;
                continue;
            }
            for(int k = 1; k <= n; k ++)
            {
                if(k == i || k == j) continue;
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while(q --)
    {
        int u, v; scanf("%lld %lld", &u, &v);
        int ans = 2e16;
        for(int a : sta[u])
        {
            for(int b : sta[v])
            {
                ans = min(ans, f[a][b] + mp[a][u] + mp[b][v]);
            }
        }
        printf("%lld\n", ans + w[u] + w[v]);
    }
}
//能不能 还能再次相见 再回头 只看一眼
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/