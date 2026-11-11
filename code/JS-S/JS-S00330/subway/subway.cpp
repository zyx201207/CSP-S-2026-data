#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MA = 1010;

int w[MA];

ll dis[MA][MA];
vector<pair<int, int>> es[MA];
bool va[MA];
priority_queue<pair<int, int>> que;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
   
    int c, n, m, d, q;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

    if (c >= 7 && c <= 11)
    {
        for (int i = 1; i <= m; i++)
            scanf("%d", &w[i]);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            int s, t, sw, tw;
            scanf("%d%d%d%d", &s, &sw, &t, &tw);
            ll ww = sw + tw;
            es[s].push_back({ww, t});
            es[t].push_back({ww, s});
        }
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dis[i][j] = 1e18;

        // dijk
        for (int s = 1; s <= m; s++)
        {
            dis[s][s] = 0;
            for (int i = 1; i <= m; i++)
                va[i] = false;
            que.push({0, s});
            while (!que.empty())
            {
                auto tt = que.top();
                que.pop();
                int cur = tt.second, dcur = -tt.first;
                if (va[cur]) continue;
                va[cur] = true;
                for (auto e : es[cur])
                {
                    int nt = e.second, we = e.first;
                    if (va[nt]) continue;
                    if (dis[s][nt] > dis[s][cur] + we)
                    {
                        dis[s][nt] = dis[s][cur] + we;
                        que.push({-dis[s][nt], nt});
                    }
                }
            }
        }

        while (q--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", w[x] + dis[x][y] + w[y]);
        }
    }

    return 0;
}