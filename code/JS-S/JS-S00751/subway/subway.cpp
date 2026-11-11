#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;
int c, n, m, d, Q, w[500005], k[505], t[500005], cnt, head[500005], dis[500005];
vector<int> a[505], num[500005]; bool vis[500005];
priority_queue<pii, vector<pii>, greater<pii> > q;
struct node
{
    int nxt, to, w;
}g[5000005];
void add(int u, int v, int w)
{
    g[++cnt] = {head[u], v, w};
    head[u] = cnt;
    g[++cnt] = {head[v], u, w};
    head[v] = cnt;
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &Q);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &k[i]);
        for (int j = 1; j <= k[i]; j++)
        {
            int x, y;
            scanf("%lld%lld", &x, &y);
            a[i].push_back(x), t[++tot] = y;
            num[x].push_back(tot);
            if (j != 1)
                add(tot, tot - 1, 0);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int len = num[i].size();
        for (int j = 0; j < len - 1; j++)
        {
            for (int k = j + 1; k < len; k++)
                add(num[i][j], num[i][k], t[num[i][j]] + t[num[i][k]]);
        }
    }
    while (Q--)
    {
        int x, y, ans = 1e18;
        scanf("%lld%lld", &x, &y);
        for (int b = 0; b < num[x].size(); b++)
        {
            int s = num[x][b];
            while (!q.empty())
                q.pop();
            for (int i = 1; i <= tot; i++)
                dis[i] = 1e18, vis[i] = 0;
            dis[s] = 0, q.push(mkp(0, s));
            while (!q.empty())
            {
                int u = q.top().sec; q.pop();
                if (vis[u])
                    continue;
                vis[u] = 1;
                for (int i = head[u]; i; i = g[i].nxt)
                {
                    int v = g[i].to, w = g[i].w;
                    if (dis[u] + w < dis[v])
                        dis[v] = dis[u] + w, q.push(mkp(dis[v], v));
                }
            }
            for (int i = 0; i < num[y].size(); i++)
                ans = min(ans, dis[num[y][i]] + t[num[x][b]] + t[num[y][i]]);
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
