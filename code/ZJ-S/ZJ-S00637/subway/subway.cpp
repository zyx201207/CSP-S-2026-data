#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 5e5 + 5, D = 25;
int c, n, m, d, tot, a[M], h[M * 2 + N], dis[M * 2 + N];
struct edge { int to, w, nxt; } e[M * D << 1];
queue<int>q;

void add(int u, int v, int w)
{
    e[++tot] = {v, w, h[u]}, h[u] = tot;
    e[++tot] = {u, w, h[v]}, h[v] = tot;
}

int dij(int s, int t)
{
    for (int i = 1; i <= m * 2 + n; i++) dis[i] = 1e14;
    while (q.size()) q.pop();
    dis[s] = 0, q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dis[u] + e[i].w < dis[v])
            {
                dis[v] = dis[u] + e[i].w, q.push(v);
            }
        }
    }
    return dis[t];
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> c >> n >> m >> d >> _;
    for (int i = 1; i <= m; i++) cin >> a[i], add(i, m + i, a[i]);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int u, v;
            cin >> u >> v;
            add(m + u, m * 2 + i, v);
        }
    }
    /*
    for (int i = 1; i <= m * 2 + n; i++)
    {
        cout << i << ":\n";
        for (int j = h[i]; j; j = e[j].nxt) cout << i << " " << e[j].to << " " << e[j].w << "\n";
    }
    */
    while (_--)
    {
        int u, v;
        cin >> u >> v;
        cout << dij(u, v) << "\n";
    }
}
