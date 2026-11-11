#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e6 + 9;

int n, m, tid;

vector < int > E[N];

int f[N], R, F[N], vis[N], S, T, mx, fa[N], p[N];

void dfs(int u, int dep)
{
    for (int v : E[u])
        if (v != fa[u])
            fa[v] = u, dfs(v, dep + 1);
    if (dep > mx)
        mx = dep, T = u;
}

void dfs1(int u, int fa)
{
    F[u] = f[u] = 0;
    for (int v : E[u])
        if (!vis[v] && v != fa)
            dfs1(v, u), f[u] = max(f[u], f[v] + 1), F[u] += F[v];
    if (f[u] >= R)
        ++ F[u];
}

int lef[N], rig[N], q[N], a[N], cnt;

int chk(int x)
{
    int l, r;
    R = x;
    l = 1, r = 0;
    for (int i = 1, j = 1;i <= cnt;++ i)
    {
        dfs1(p[i], 0);
        a[i] = i + f[p[i]];
        while (l <= r && a[q[r]] < a[i])
            -- r;
        q[++ r] = i;
        auto qmax = [&]()
        {
            while (l <= r && q[l] <= j)
                ++ l;
            if (l > r)
                return 0;
            return a[q[l]] - j;
        };
        if (i > 1)
        {
            F[p[i]] += F[p[i - 1]];
            int x = f[p[i - 1]] + 1;
            if (x >= R && f[p[i]] < R)
                ++ F[p[i]];
            f[p[i]] = max(f[p[i]], x);
        }
        while (qmax() > R)
            ++ j;
        lef[i] = max(1, F[p[j]]);
    }
    l = 1, r = 0;
    for (int i = cnt, j = cnt;i >= 1;-- i)
    {
        dfs1(p[i], 0);
        a[i] = f[p[i]] - i;
        while (l <= r && a[q[r]] < a[i])
            -- r;
        q[++ r] = i;
        auto qmax = [&]()
        {
            while (l <= r && q[l] >= j)
                ++ l;
            if (l > r)
                return 0;
            return a[q[l]] + j;
        };
        if (i < cnt)
        {
            F[p[i]] += F[p[i + 1]];
            int x = f[p[i + 1]] + 1;
            if (x >= R && f[p[i]] < R)
                ++ F[p[i]];
            f[p[i]] = max(f[p[i]], x);
        }
        while (qmax() > R)
            -- j;
        rig[i] = max(1, F[p[j]]);
    }
    // printf("%d\n", R);
    // for (int i = 0;i < cnt;++ i)
    //     printf("%d %d\n", lef[i], rig[i + 1]);
    // printf("\n-------------------------\n");
    for (int i = 0;i < cnt;++ i)
        if (lef[i] + rig[i + 1] <= m)
            return 1;
    return 0;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;++ i)
        E[i].clear();
    for (int i = 1, u, v;i < n;++ i)
        scanf("%d%d", &u, &v), E[u].push_back(v), E[v].push_back(u);
    for (int i = 1;i <= n;++ i)
        vis[i] = 0;
    mx = 0, fa[1] = 0, dfs(1, 0), S = T;
    mx = 0, fa[S] = 0, dfs(S, 0);
    cnt = 0;
    while (T)
        p[++ cnt] = T, vis[T] = 1, T = fa[T];
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T;
    scanf("%d%d", &tid, &T);
    while (T --)
        solve();

    return 0;
}