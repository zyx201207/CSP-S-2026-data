#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u, t;
};

const int N = 200005;
int k[N], w[N];
int c, n, m, d, q, x, y, ans;
node g[1000005][2];
bool vis[N][N];

void dfs(int u, int step, int s)
{
    if(step == y)
    {
        ans = min(ans, s + w[y]);
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(g[i][1].u == step && !vis[i][1] || g[i][2].u == step && !vis[i][2])
        {
            if(g[i][2].u && !vis[i][2])
            {
                vis[i][2] = 1;
                dfs(i, g[i][2].u, s + g[i][2].t);
                vis[i][2] = 0;
            }
            if(!vis[i][1])
            {
                vis[i][1] = 1;
                dfs(i, g[i][1].u, s + g[i][1].t);
                vis[i][1] = 0;
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> n >> m >> d >> q;

    memset(g, 0, sizeof g);
    for(int i = 1; i <= q; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            int a, t;
            cin >> a >> t;
            g[i][j].u = a;
            g[i][j].t = t;
        }
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        memset(vis, 0, sizeof vis);

        for(int j = 1; j <= n; j++)
        {
            if(x == g[j][1].u)
            {
                ans = 1e9;
                vis[j][x] = 1;
                dfs(j, x, w[x] + g[i][1].t);
            }
            if(x == g[j][2].u)
            {
                vis[j][x] = 1;
                dfs(j, x, w[x] + g[i][2].t);
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
