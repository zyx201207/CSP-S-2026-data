#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500505, maxm = maxn << 1;
int head[maxn], ver[maxm], edge[maxm], Next[maxn];
int c, n, m, d, q, tot = 0;
int W[maxn];
int dis[maxn], vis[maxn];
int fa[maxn][31], dep[maxn], siz[maxn][31];

void add(int x, int y, int w, int z = 1)
{
    ver[++tot] = y, edge[tot] = w, Next[tot] = head[x], head[x] = tot;
    if(z) add(y, x, w, 0);
}

void dijkstra(int s, int k)
{
    priority_queue<pair<int, int> > q;

    for(int i = 1; i <= n +m; i++) dis[i] = 1e18;
    q.push({0, s});
    dis[s] = 0;

    while(!q.empty())
    {
        int u = q.top().second; q.pop();
        if(vis[u] == k) continue;
        vis[u] = k;

        //cout << "u = " << u << "\n";

        for(int i = head[u]; i; i = Next[i])
        {
            int v = ver[i], w = edge[i];

            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

void dfs(int u, int faa)
{
    fa[u][0] = faa;
    dep[u] = dep[faa] + 1;

    for(int j = 1; j <= 30; j++)
    {
        fa[u][j] = fa[fa[u][j - 1]][j - 1];
        siz[u][j] = siz[u][j - 1] + siz[fa[u][j - 1]][j - 1];
    }

    for(int i = head[u]; i; i = Next[i])
    {
        int v = ver[i], w = edge[i];
        if(v == faa) continue;

        siz[v][0] = w;
        dfs(v, u);
    }
}

int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    int tmp = dep[x] - dep[y], ans = 0;
    for(int i = 0; tmp; i++, tmp >>= 1)
        if(tmp & 1)
            ans += siz[x][i],
            x = fa[x][i];
    if(x == y) return ans;

    for(int j = 30; j; j--)
    {
        if(fa[x][j] != fa[y][j])
        {
            ans += siz[x][j] + siz[y][j];
            x = fa[x][j], y = fa[y][j];
        }
    }
    ans += siz[x][0] + siz[y][0];
    return ans;
}

void solve_dijkstra();
void solve_lca()
{
    for(int i = 1; i <= m; i++) cin >> W[i];
    for(int i = 1; i <= n; i++)
    {
        int K;
        cin >> K;
        //K = 2;
        int a, b, t1, t2;
        cin >> a >> t1 >> b >> t2;
        add(a, b, t1 + t2);
    }

    dfs(1, 0);

    for(int k = 1; k <= q; k++)
    {
        int x, y;
        cin >> x >> y;

        cout << lca(x, y) + W[x] + W[y] << "\n";
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    if(c <= 8) solve_dijkstra();
    else if(c <= 11) solve_lca();


    return 0;
}


void solve_dijkstra()
{
    for(int i = 1; i <= m; i++) cin >> W[i];
    for(int i = 1; i <= n; i++)
    {
        int K;
        cin >> K;
        int a, t;
        while(K--)
        {
            cin >> a >> t;
            add(m + i, a, t);
        }
    }

    for(int k = 1; k <= q; k++)
    {
        int x, y;
        cin >> x >> y;

        dijkstra(x, k);
        cout << dis[y] + W[x] + W[y] << "\n";
    }
}
