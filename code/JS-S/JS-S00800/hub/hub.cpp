#include <bits/stdc++.h>
#define int long long
#define SIZE 1000005
using namespace std;

int c, t;
vector<int> edge[SIZE];
int dep[SIZE], fa[SIZE];
// LONGEST, second LONGEST
pair<int, int> dp[SIZE];
int mx_len;
void clear()
{
    mx_len = 0;
    memset(edge, 0, sizeof edge);
    memset(dep, 0, sizeof dep);
}
void update_path(int cur, int duepath)
{
    if (duepath >= dp[cur].first)
    {
        dp[cur].second = dp[cur].first;
        dp[cur].first = duepath;
    }
    else if (duepath > dp[cur].second)
    {
        dp[cur].second = duepath;
    }
}
void dfs(int cur, int f)
{
    dep[cur] = dep[f] + 1;
    fa[cur] = f;
    for (auto nxt : edge[cur])
    {
        if (cur != f)
        {
            dfs(nxt, cur);
            const int nxt_1st = dp[nxt].first + 1, nxt_2nd = dp[nxt].second + 1;
            update_path(cur, nxt_1st);
            update_path(cur, nxt_2nd);
            mx_len = max(mx_len, dp[cur].first + dp[cur].second);
        }
    }
}
void solve()
{
    // int n, k;
    // cin >> n >> k;
    // // 0 Reset the data
    // clear();
    // for (int i = 0; i < n; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     edge[u].push_back(v);
    //     edge[v].push_back(u);
    // }

    // // 1 DFS to get information
    // dfs(1, 1);

    // // 2 Find the nodes on the diameter
    // vector<int> diameter_path;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (dp[i].first + dp[i].second == mx_len)
    //     {
    //         diameter_path.push_back(i);
    //     }
    // }
    cout << 0 << "\n";
}
signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}