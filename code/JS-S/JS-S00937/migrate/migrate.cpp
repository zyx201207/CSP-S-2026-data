#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    vector<int> R(n + 1);
    int r = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (r <= n && x[r] - x[i] <= d)
        {
            ++r;
        }
        R[i] = r - 1;
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    vector<vector<int>> dis(n + 1, vector<int>(n + 1));
    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        for (int j = i + 1; j <= R[i]; ++j)
        {
            f[i][j] = dis[i][j] = 1;
        }
        for (int j = R[i] + 1; j <= n; ++j)
        {
            dis[i][j] = dis[R[i]][j] + 1;
            for (int k = i + 1; k <= R[i]; ++k)
            {
                if (dis[R[i]][j] == dis[k][j])
                {
                    f[i][j] += f[k][j];
                }
            }
            ans += f[i][j] == 2;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T--)
        solve();
}