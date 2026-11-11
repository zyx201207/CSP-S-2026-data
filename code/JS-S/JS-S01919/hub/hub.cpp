#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, m, ans = INT_MAX, g[5005][5005], dis[5005][5005];
vector < int > ch;

void myprint()
{
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (g[ch[i]][ch[j]] == 1) sum++;
    // for (auto i : ch)
    //     cout << i << ' ';
    // cout << '\n' << sum << '\n';
    if (sum < m - 2) return;
    int aans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = INT_MAX;
        for (auto j : ch)
            cnt = min(cnt, dis[i][j]);
        aans = max(aans, cnt);
    }
    ans = min(ans, aans);
}

void dfs(int u, int sum)
{
    if (sum == m) myprint();
    else if (u > n) return;
    else
    {
        ch.push_back(u);
        dfs(u + 1, sum + 1);
        ch.pop_back();
        dfs(u + 1, sum);
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = INT_MAX;
        memset(g, 0, sizeof g);
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            dis[u][v] = dis[v][u] = g[u][v] = g[v][u] = 1;
        }
        for (int i = 1; i <= n; i++)
            dis[i][i] = g[i][i] = 1;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << dis[i][j] << ' ';
        //     cout << '\n';
        // }
        dfs(1, 0);
        cout << ans << '\n';
    }
    return 0;
}