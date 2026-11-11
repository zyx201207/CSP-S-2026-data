#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 2007
#define INF 1000000007

int c, t;
int n, k;
vector<int> edge[N];
int vis[N];
int vis2[N];
int dis[N];
int ans;

void dfs2(int now)
{
    vis2[now] = 1;
    for (int nex: edge[now])
    {
        if (!vis2[nex] && vis[nex])
        {
            dfs2(nex);
        }
    }
}

void dfs(int now, int last)
{
    if (now == n)
    {
        if (last) return;
        else
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++) vis2[i] = 0;
            for (int i = 1; i <= n; i++)
            {
                if (vis[i] && !vis2[i])
                {
                    cnt++;
                    dfs2(i);
                }
            }
            if (cnt > 2) return;
            int ppp = 0;
            for (int i = 1; i <= n; i++) dis[i] = vis[i] ? 0 : INF;
            deque<int> q;
            for (int i = 1; i <= n; i++) if (vis[i]) q.push_back(i);
            while (!q.empty())
            {
                int now = q.front(); q.pop_front();
                for (int nex: edge[now])
                {
                    if (dis[nex] > dis[now] + 1)
                    {
                        dis[nex] = dis[now] + 1;
                        q.push_back(nex);
                    }
                }
            }
            for (int i = 1; i <= n; i++) ppp = max(ppp, dis[i]);
            ans = min(ans, ppp);
        }
    }
    dfs(now + 1, last);
    vis[now] = 1;
    dfs(now + 1, last - 1);
    vis[now] = 0;
}

signed solve()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ans = INF;
    dfs(1, k);
    cout << ans << '\n';
    return 0;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
