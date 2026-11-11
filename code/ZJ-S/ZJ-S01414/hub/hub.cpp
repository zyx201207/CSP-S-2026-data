#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, k;
int dep[N], maxdep[N];
vector<int> son[N], pre[N], suf[N];
int f[N];

void clear()
{
    for(int i = 1; i <= n; i ++) h[i] = -1, son[i].clear(), pre[i].clear(), suf[i].clear(), f[i] = 0, maxdep[i] = dep[i] = 0;
    idx = 0;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs2(int u, int father, int mid)
{
    dep[u] = dep[father] + 1;
    maxdep[u] = dep[u];
    f[u] = 1;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        dfs2(j, u, mid);
        if(maxdep[j] - dep[u] > mid) f[u] += f[j];
        maxdep[u] = max(maxdep[u], maxdep[j]);
        son[u].push_back(j);
        pre[u].push_back(maxdep[j]);
        suf[u].push_back(maxdep[j]);
    }
    int sz = son[u].size();
    for(int j = 1; j < sz; j ++) pre[u][j] = max(pre[u][j], pre[u][j - 1]);
    for(int j = sz - 2; j >= 0; j --) suf[u][j] = max(suf[u][j], suf[u][j + 1]);
}

void dfs3(int u, int father, int mid, int &res, int val, int maxv1, int maxv2)
{
    // printf(">> %d %d %d %d %d %d %d\n", u, father, mid, res, val, maxv1, maxv2);
    if(dep[u] + maxv1 > mid || maxv2 - 1 > mid) return;
    res = min(res, val + f[u]);
    int sz = son[u].size();
    for(int i = 0; i < sz; i ++)
    {
        int j = son[u][i];
        int vp = (i ? pre[u][i - 1] : -1e9), vs = (i != sz - 1 ? suf[u][i + 1] : -1e9);
        int vt = max(max(vp, vs), dep[u]);
        dfs3(j, u, mid, res, val, max(maxv1, vt - 2 * dep[u]), max(maxv2, vt));
    }
}

bool check(int mid)
{
    int minv = n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++) son[j].clear(), pre[j].clear(), suf[j].clear();
        dfs2(i, 0, mid);
        minv = min(minv, f[i]);
        // printf("> %d %d %d\n", i, mid, f[i]);
        for(int j = h[i]; ~j; j = ne[j])
        {
            int v = e[j], val = f[i];
            if(maxdep[v] - 1 > mid) val -= f[v];
            // printf("> %d: %d %d\n", i, v, val);
            dfs3(v, i, mid, minv, val, -1e9, -1e9);
        }
    }
    // printf("%d %d %d\n", minv, k, mid);
    return minv <= k;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    memset(h, -1, sizeof h);
    int cidx, test;
    cin >> cidx >> test;
    while(test --)
    {
        clear();
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n - 1; i ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y), add(y, x);
        }
        int l = 0, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
// (g++ -std=c++14 -O2 -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wconversion hub.cpp -o hub && ./hub && diff hub.out hub1.ans)