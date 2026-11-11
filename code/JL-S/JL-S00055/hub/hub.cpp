#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4010;

int n, K;
int h[N], e[N * 2], ne[N * 2], idx;
int f[N], g[N], res[N], depth[N];
int Mid;
int maxd[N], maxd2[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs1(int u, int fa)
{
    f[u] = (Mid <= maxd[u]);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        dfs1(j, u);
        f[u] += f[j];
    }
}

void dfs2(int u, int fa, int s)
{
    int maxv = -1e9, maxv2 = -1e9, pos = -1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        if (maxd[j] + depth[j] > Mid)
        {
            int val = maxd[j] + 1;
            if (val >= maxv) maxv2 = maxv, maxv = val, pos = j;
            else if (val > maxv2) maxv2 = val;
        }
    }
    int val = (depth[u] <= Mid ? -1e9 : 0);
    if (val >= maxv) maxv2 = maxv, maxv = val, pos = -1;
    else if (val > maxv2) maxv2 = val;
    if (maxd2[u] <= Mid) res[s] = min(res[s], max(1, f[u]));
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        if (j != pos) maxd2[j] = max(maxd2[u] + 1, maxv + 1);
        else maxd2[j] = max(maxd2[u] + 1, maxv2 + 1);
        dfs2(j, u, s);
    }
}

void dfs3(int u, int fa)
{
    maxd[u] = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        depth[j] = depth[u] + 1;
        dfs3(j, u);
        maxd[u] = max(maxd[u], maxd[j] + 1);
    }
}

bool check(int mid)
{
    Mid = mid;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ ) maxd[j] = f[j] = depth[j] = 0, maxd2[j] = -1e9;
        dfs3(i, -1);
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            dfs1(k, i);
            res[k] = 1e9;
            dfs2(k, i, k);
        }
        int sum = 1;
        int minv = 1e9;
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            sum += f[k];
            minv = min(minv, res[k] - f[k]);
            //cout << "res: " << res[k] << '\n';
        }
        //cout << mid << ' ' << i << ' ' << sum << ' ' << minv << '\n';
        //cout << sum << ' ' << minv + sum << '\n';
        if (sum <= K) return true;
        if (minv + sum <= K) return true;
    }
    return false;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test_id, T;
    cin >> test_id >> T;
    while (T -- )
    {
        cin >> n >> K;
        //cout << n << ' ' << K << '\n';
        for (int i = 1; i <= n; i ++ ) h[i] = -1; idx = 0;
        for (int i = 0; i < n - 1; i ++ )
        {
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
        }
        //cout << check(8) << '\n';
        //return 0;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << '\n';
    }

    return 0;
}