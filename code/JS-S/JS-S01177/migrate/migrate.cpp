#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, t, cnt, ans, dis[2000005];

pair<long long, long long> dfs(long long j, long long k, long long step)
{
    int i = upper_bound(dis + j + 1, dis + k + 1, dis[j] + d) - dis - 2;
    if (i == j)
        return {0ll, INT_MAX};
    if (i == k)
        return {1ll, step};
    if (i == j - 1)
        return dfs(i, k, step + 1);
    pair<long long, long long> l = dfs(i, k, step + 1);
    if (l.first == 1ll || l.first == 2ll)
    {
        pair<long long, long long> p = dfs(i - 1, k, step + 1);
        if (p.first == 0ll)
            return l;
        if (p.second == l.second)
            return {l.first + p.first, l.second};
        return l;
    }
    return l;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        d = 1;
        cin >> n >> m;
        for (long long i = 1; i <= n; i++)
        {
            cin >> dis[i];
            if (i > 1 && dis[i] - dis[i - 1] > m)
            {
                if (i - d < 4)
                {
                    d = i;
                    continue;
                }
                for (long long j = d; j < i; j++)
                    for (long long k = j + 3; k < i; k++)
                        if (dfs(j, k, 0).first == 2)
                            ans++;
                d = i;
            }
        }
    }
    cout << ans;
    return 0;
}
