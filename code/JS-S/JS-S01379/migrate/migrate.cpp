#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int N = 2e6 + 5, inf = 3e18;
int a[N], dis[N], n, d, cnt[N], ans;
queue<pii> q;
void bfs(int st)
{
    q.push({st, 0});
    for (int i = st + 1; i <= n; i++)
        dis[i] = inf, cnt[i] = 0;
    dis[st] = 0, cnt[st] = 1;
    while (!q.empty())
    {
        pii tmp = q.front();
        q.pop();
        for (int i = tmp.first + 1; i <= n && a[i] - a[tmp.first] <= d; i++)
        {
            if (dis[i] < tmp.second + 1)
                continue;
            else if (dis[i] == tmp.second + 1)
                cnt[i] += cnt[tmp.first];
            else
            {
                dis[i] = tmp.second + 1;
                cnt[i] = cnt[tmp.first];
                q.push({i, dis[i]});
            }
        }
    }
    for (int i = st + 1; i <= n; i++)
        ans += (cnt[i] == 2);
}
void solve()
{
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        bfs(i);
    cout << ans << "\n";
}
void solveA()
{
    int step = 1;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[1] >= d)
            break;
        step++;
    }
    if (step == 1)
        cout << "0\n";
    else if ((a[step + 1] - a[1]) % d == 0)
        cout << max(0ll, n - step * 2 + 1) << "\n";
    else
        cout << max(0ll, n - (step - 1) * 2 + 1) << "\n";
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int c, t;
    cin >> c >> t;
    if (c == 11 || c == 12)
    {
        while (t--)
            solveA();
        return 0;
    }
    while (t--)
        solve();
    return 0;
}