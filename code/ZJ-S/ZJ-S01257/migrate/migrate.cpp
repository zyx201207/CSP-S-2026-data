#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int MN = 5000;

int c, t;
int n, d;
int x[MN + 10];
vector<int> ed[MN + 10];
int dis[MN + 1][MN + 1];
int cnt[MN + 1][MN + 1];
queue<int> q;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", x + i);
        }
        for (int i = 1; i <= n; ++i)
        {
            ed[i].clear();
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (abs(x[i] - x[j]) <= d)
                {
                    ed[i].push_back(j);
                    ed[j].push_back(i);
                }
            }
        }
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            q.push(i);
            dis[i][i] = 0;
            cnt[i][i] = 1;
            while (!q.empty())
            {
                int u = q.front(); q.pop();
                for (auto v : ed[u])
                {
                    if (dis[i][u] + 1 < dis[i][v])
                    {
                        dis[i][v] = dis[i][u] + 1;
                        q.push(v);
                    }
                    else if (dis[i][u] + 1 == dis[i][v])
                    {
                        cnt[i][v] += cnt[i][u];
                    }
                }
            }
            for (int j = i + 1; j <= n; ++j)
            {
                if (cnt[i][j] == 2)
                {
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
