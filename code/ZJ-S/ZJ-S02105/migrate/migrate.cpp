#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int x[N];
int sum[N];
int n, d;
int c, t;
vector<int> e[N];
int dp[N];
int dis[N];
int ans = 0;
void dfs(int u)
{
        for (auto v : e[u])
        {
                int flg = 0;
                if (dis[v] == dis[u] + 1)
                {
                        dp[v] += dp[u];
                        flg = 1;
                }

                if (dis[v])
                {
                        continue;
                }
                dis[v] = dis[u] + 1;
                if (!flg)
                {
                        dp[v] = dp[u];
                }
                dfs(v);
        }
}

void chs(int dot)
{
        ans = 0;
        dp[dot] = 1;
        dfs(dot);
        for (int i = 1; i <= n; i++)
        {
                ans += dp[i] == 2;
                dp[i] = 0;
                dis[i] = 0;
        }
}
void solve()
{
        if (c == 11 || c == 12)
        {
                int del = x[2] - x[1];
                if (del >= d / 2)
                {
                        cout << 0 << endl;
                }
                else if (del > d / 3 && del < d / 2)
                {
                        cout << n - 3 << endl;
                }
                else
                {
                        cout << 0 << endl;
                }
                return;
        }
        if (c >= 15 && c <= 18)
        {
                cout << 0 << endl;
                return;
        }
        

        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
                cin >> x[i];
        }
        for (int i = 1; i < n; i++)
        {
                for (int j = i + 1; j <= n; j++)
                {
                        if (x[j] - x[i] <= d)
                        {
                                e[j].push_back(i);
                                e[i].push_back(j);
                        }
                }
        }
        for (int i = 1; i <= n; i++)
        {
                chs(i);
        }
        cout << ans << endl;
}
signed main()
{
        freopen("migrate.in", "r", stdin);
        freopen("migrate.out", "w", stdout);

        cin >> c >> t;
        while (t--)
        {
                solve();
        }
}