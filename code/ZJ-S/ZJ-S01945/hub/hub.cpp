#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 4005;
typedef long long ll;

int n, K, len[N];
vector<int> g[N];

int lim;
void dfs(int x, int fa, int &cnt)
{
    len[x] = 0;
    for (auto y : g[x])
    {
        if (y == fa)
            continue;
        dfs(y, x, cnt);
        len[x] = max(len[x], len[y] + 1);
    }
    cnt += len[x] >= lim;
}

int dis[N];
bool solve(int x)
{
    queue<pair<int, int>> q;
    dis[x] = 0;
    q.emplace(x, 0);
    int tot = 0, cnt = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int fa = q.front().second;
        q.pop();
        if (dis[x] == lim)
        {
            if ((++cnt) > 2)
                return false;
            int res = 0;
            dfs(x, fa, res);
            if ((tot += res) > K)
                return false;
            continue;
        }
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            dis[y] = dis[x] + 1;
            q.emplace(y, x);
        }
    }
    return true;
}

vector<pair<int, int>> e;
bool solve2(int x, int y)
{
    queue<pair<int, int>> q;
    dis[x] = 0;
    q.emplace(x, y);
    int tot = 0, cnt = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int fa = q.front().second;
        q.pop();
        if (dis[x] == lim)
        {
            if ((++cnt) == 2)
                return false;
            int res = 0;
            dfs(x, fa, res);
            if ((tot += res) > K)
                return false;
            continue;
        }
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            dis[y] = dis[x] + 1;
            q.emplace(y, x);
        }
    }
    q.emplace(y, x);
    dis[y] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int fa = q.front().second;
        q.pop();
        if (dis[x] == lim)
        {
            if ((++cnt) > 2)
                return false;
            int res = 0;
            dfs(x, fa, res);
            if ((tot += res) > K)
                return false;
            continue;
        }
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            dis[y] = dis[x] + 1;
            q.emplace(y, x);
        }
    }
    return cnt == 2;
}

bool check(int mid)
{
    lim = mid;
    for (int i = 1; i <= n; i++)
        if (solve(i))
            return true;
    for (int i = 0; i < n - 1; i++)
        if (solve2(e[i].first, e[i].second))
            return true;
    return false;
}

namespace sol
{
    bool val[N];
    void dfs(int x, int fa)
    {
        if (!val[x])
            return;
        val[x] = 0;
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            dfs(y, x);
        }
    }
    int dfs1(int x, int fa)
    {
        if (val[x])
            return 0;
        int res = 0x3f3f3f3f;
        for (auto y : g[x])
        {
            if (y == fa)
                continue;
            res = min(res, dfs1(y, x) + 1);
        }
        return res;
    }
    void main()
    {
        int res = 0x3f3f3f3f;
        for (int i = 0; i < (1 << n); i++)
        {
            if (__builtin_popcount(i) != K)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    val[j + 1] = 1;
                }
            }
            int ans = 0;
            for (int j = 1; j <= n; j++)
                ans = max(ans, dfs1(j, 0));
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (val[j])
                {
                    ++cnt;
                    dfs(j, 0);
                }
            }
            if (cnt <= 2)
            {
                res = min(res, ans);
            }
        }
        cout << res << endl;
    }
}

void Main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    e.clear();
    e.resize(n - 1);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        e[i - 1] = make_pair(x, y);
    }
    if (n <= 10)
        return sol::main();
    int l = 0, r = n, mid = 0, res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << res << endl;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TaskCnt = 1;
    cin >> TaskCnt >> TaskCnt;
    while (TaskCnt--)
        Main();
    return 0;
}