#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510, M = 5e5 + 10, S = 5e5 + 510, P = 1510;
struct node {
    int v; ll w;
    bool operator<(const node x) const {
        return w > x.w;
    }
};
vector<node>edge[S];
ll w[M], T, dis[P][P], dist[S];
int c, n, m, d, q, sumk, num[S], dep[S], st[S][21];
void dfs(int u, int p)
{
    dep[u] = dep[p] + 1, st[u][0] = p;
    for (int k = 1; k <= 20; k++) {
        st[u][k] = st[st[u][k - 1]][k - 1];
    }
    for (auto x : edge[u]) if (x.v != p) {
        dist[x.v] = dist[u] + x.w; dfs(x.v, u);
    }
    return;
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = 20; k >= 0; k--) {
        if (dep[st[u][k]] >= dep[v]) u = st[u][k];
    }
    if (u == v) return u;
    for (int k = 20; k >= 0; k--) {
        if (st[u][k] != st[v][k]) u = st[u][k], v = st[v][k];
    }
    return st[u][0];
}
void dijk(int x)
{
    priority_queue<node>pq; pq.push({x, 0LL});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int u = cur.v, cw = cur.w;
        if (dis[x][u] < cw) continue;
        for (auto t : edge[u])
        {
            if (dis[x][t.v] <= cw + t.w) continue;
            dis[x][t.v] = cw + t.w;
            pq.push({t.v, cw + t.w});
        }
    }
    return;
}
void bfs(int x)
{
    queue<node>q;
    q.push({x, 0LL});
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        int u = cur.v, cw = cur.w;
        if (num[u] < cw) continue;
        for (auto t : edge[u])
        {
            if (num[t.v] <= cw + 1) continue;
            num[t.v] = cw + 1; q.push({t.v, cw + 1});
        }
    }
    return;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k; int a; ll t; sumk += k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a >> t; T = t;
            edge[a].push_back({m + i, t});
            edge[m + i].push_back({a, t});
        }
    }
    if (sumk <= 1000) {
        fill((ll*)dis, (ll*)dis + P * P, 1000000000000000000LL);
        for (int i = 1; i <= m + n; i++) dis[i][i] = 0LL;
        for (int i = 1; i <= m; i++) dijk(i);
    }
    if (c > 19) {
        dfs(1, 0);
    }
    while (q--)
    {
        int x, y; cin >> x >> y;
        if (sumk <= 1000) {
            cout << dis[x][y] + w[x] + w[y] << "\n";
        }
        else if (c >= 12 && c <= 19) {
            fill((int*)num, (int*)num + S, 1e9); num[x] = 0;
            bfs(x); cout << (ll)num[y] * T + w[x] + w[y] << "\n";
        }
        else {
            int z = lca(x, y);
            ll res = dist[x] - dist[z] + dist[y] + w[x] + w[y];
            cout << res << "\n";
        }
    }
    return 0;
}
