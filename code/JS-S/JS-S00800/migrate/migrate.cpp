#include <bits/stdc++.h>
#define int long long
#define SIZE 2000005
using namespace std;

int c, t;
int mapping[SIZE], dis[SIZE], dp[SIZE];
int get_dis(int i, int j)
{
    return abs((mapping[i] - mapping[j]));
}
void solve()
{
    deque<int> q;
    memset(dp, 0, sizeof dp);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> mapping[i];
    }

    for (int i = 1; i <= n; i++)
    {
        unordered_set<int> banned;
        const int pos = mapping[i];
        while (q.size() && abs(mapping[q.front()] - pos) > d)
        {
            q.pop_front();
        }
        if (i >= 4)
        {
            // New dual-islands found
            int j = i - 3;
            bool good = get_dis(i, j) > d && get_dis(i, i - 2) <= d && get_dis(i, i - 1) <= d && get_dis(j, i - 1) <= d && get_dis(j, i - 2) <= d && get_dis(i, i - 3) > d;
            if (good)
            {
                dp[i] = 1;
                banned.insert(j);
            }
        }
        for (auto dq : q)
        {
            if (banned.find(dq) != banned.end())
            {
                dp[i] += dp[dq];
            }
        }
        banned.clear();
        q.push_back(i);
    }
    int ans = 0;
    for (int i = 4; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << ans << "\n";
}
signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}