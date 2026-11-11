#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int id, T;
int n, k, used[N], flag[N], fa[N], can[N][N], ans;
vector<int> g[N];
int find(int u)
{
    return (fa[u] == u) ? u : fa[u] = find(fa[u]);
}
void dfs(int x, int sum)
{
    if(x == n + 1)
    {
        if(sum != k) return ;
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i = 1; i <= n; i ++)
        {
            if(!flag[i]) continue;
            for(int j = 1; j <= n; j ++)
            {
                if(!flag[j] || i == j) continue;
                if(can[i][j] == 1)
                {
                    int fi = find(i), fj = find(j);
                    if(fi != fj)
                    {
                        fa[fi] = fj;
                    }
                }
            }
        }
        vector<int> used_rt(n + 1, 0);
        for(int i = 1; i <= n; i ++)
        {
            if(flag[i])
            {
                // cout << find(i) << endl;
                used_rt[find(i)] |= 1;
            }
        }
        int tot_rt = 0;
        for(int i = 1; i <= n; i ++) if(used_rt[i]) ++tot_rt;
        if(tot_rt > 2) return ;
        int mx = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(flag[i]) continue;
            int mn_res = 1e9;
            for(int j = 1; j <= n; j ++)
            {
                if(flag[j])
                {
                    // cout << j << endl;
                    mn_res = min(mn_res, can[i][j]);
                }
            }
            mx = max(mx, mn_res);
        }
        // cout << mx << endl;
        ans = min(ans, mx);
        return ;
    }
    flag[x] = 1;
    dfs(x + 1, sum + 1);
    flag[x] = 0;
    dfs(x + 1, sum);
}
void solve()
{
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++) can[i][j] = 1e9;
        can[i][i] = 0;
    }
    ans = 1e9;
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i < n; i ++)
    {
        int u, v; scanf("%lld %lld", &u, &v);
        can[u][v] = can[v][u] = 1;
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(i == j) continue;
            for(int k = 1; k <= n; k ++)
            {
                if(k == i || k == j) continue;
                can[i][j] = min(can[i][j], can[i][k] + can[k][j]);
            }
        }
    }
    // for(int i = 1; i <= n; i ++)
    // {
    //     for(int j = 1; j <= n; j ++)
    //     {
    //         cout << can[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dfs(1, 0);
    printf("%lld\n", ans);
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> id >> T;
    while(T --) solve();
    // solve();
}
/*
5 2
1 2
2 3
3 4
4 5

*/