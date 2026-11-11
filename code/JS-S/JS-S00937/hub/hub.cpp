#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define int long long

using namespace std;

void dfs(vector<vector<int>> &tr,
         int u, int p, int cut,
         vector<int> &dis, vector<int> &pre)
{
    dis[u] = dis[p] + 1;
    pre[u] = p;
    for (auto &&v : tr[u])
    {
        if (v == p || v == cut)
            continue;
        dfs(tr, v, u, cut, dis, pre);
    }
}

int diam(int n, vector<vector<int>> &tr,
         int root, int cut)
{
    vector<int> dis(n + 1, 0), pre(n + 1, -1);
    dfs(tr, root, root, cut, dis, pre);
    int mx = 0, u = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (dis[i] > mx)
        {
            mx = dis[i];
            u = i;
        }
    }
    dis.assign(n + 1, 0);
    pre.assign(n + 1, -1);
    dfs(tr, u, u, cut, dis, pre);
    mx = 0;
    u = -1;
    vector<int> d;
    for (int i = 1; i <= n; ++i)
    {
        if (dis[i] > mx)
        {
            mx = dis[i];
            u = i;
        }
    }
    for (;; u = pre[u])
    {
        d.push_back(u);
        if (pre[u] == u)
            break;
    }
    return d[d.size() / 2];
}

int dfs2(vector<vector<int>> &tr,
         int u, int p, int cut, int d, int mid,
         vector<int> &mxdep)
{
    mxdep[u] = d;
    int ans = 0;
    for (auto &&v : tr[u])
    {
        if (v == p || v == cut)
            continue;
        ans += dfs2(tr, v, u, cut, d + 1, mid, mxdep);
        mxdep[u] = max(mxdep[u], mxdep[v]);
    }
    if (mxdep[u] - d >= mid)
        ++ans;
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> tr(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    if (k == n)
    {
        cout << "0\n";
        return;
    }
    map<pair<int, int>, int> d;
    for (int u = 1; u <= n; ++u)
    {
        for (auto &&v : tr[u])
        {
            d[{u, v}] = diam(n, tr, u, v); // root is u
            // cout << u << " " << v << " " << d[{u, v}] << "!\n";
        }
    }
    int root = diam(n, tr, 1, 0);
    int L = 0, R = n + 1;
    while (L < R)
    {
        int mid = (L + R) / 2;
        bool flag = 0;
        vector<int> mxdep(n + 1, -1);
        if (dfs2(tr, root, root, 0, 0, mid, mxdep) <= k)
            flag = 1;
        for (int u = 1; u <= n; ++u)
        {
            for (auto &&v : tr[u])
            {
                if (u > v)
                    continue;
                mxdep.assign(n + 1, -1);
                if (dfs2(tr, d[{u, v}], d[{u, v}], v, 0, mid, mxdep) +
                        dfs2(tr, d[{v, u}], d[{v, u}], u, 0, mid, mxdep) <=
                    k)
                    flag = 1;
            }
        }
        if (flag)
            R = mid;
        else
            L = mid + 1;
    }
    cout << L << "\n";
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T--)
        solve();
}