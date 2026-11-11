#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int M = 5e5 + 5, N = 505;
int w[M], k[N], a[N][M], t[N][M];
vector < int > vl[M];
vector < pair < int, int > > g[M];

int dis[M];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            int x;
            cin >> a[i][j] >> x;
            t[i][a[i][j]] = x;
            vl[a[i][j]].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < k[i]; j++)
        {
            int u = a[i][j] + (i - 1) * 500, v = a[i][j + 1] + (i - 1) * 500;
            g[u].push_back({0, v});
            g[v].push_back({0, u});
        }
    }

    for(int j = 1; j <= m; j++)
    {
        for(int k1 = 0; k1 < vl[j].size(); k1++)
            for(int k2 = 0; k2 < vl[j].size(); k2++)
            {
                int e1 = vl[j][k1], e2 = vl[j][k2];
                if(e1 == e2) continue;
                int u = j + (e1 - 1) * 500, v = j + (e2 - 1) * 500;
                g[u].push_back({t[e1][j] + t[e2][j], v});
                g[v].push_back({t[e1][j] + t[e2][j], v});
            }
    }

    while(q--)
    {
        int sn, en;
        cin >> sn >> en;
        int ans = INF;
        for(int i = 1; i <= n; i++)
        {
            
            int s = sn + 500 * (i - 1);
            priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > q;
            memset(dis, 0x3f, sizeof dis);
            dis[s] = 0;
            q.push({0, s});
            while(!q.empty())
            {
                int u = q.top().second;
                q.pop();
                for(auto el : g[u])
                {
                    int w = el.first, v = el.second;
                    if(dis[u] != 0x3f3f3f3f && dis[u] + w < dis[v])
                    {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
            for(int j = 1; j <= n; j++)
            {
                int e = en + 500 * (j - 1);
                if(dis[e] != INF)
                    ans = min(ans, dis[e] + t[i][sn] + t[j][en]);
            }
        }
        cout << ans + w[sn] + w[en] << '\n';
    }
    return 0;
}