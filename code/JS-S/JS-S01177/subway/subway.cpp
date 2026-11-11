#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int nxt, to, w;
}e[2000005];
int c, n, m, d, q, cnt, dis[500005], t[500005], head[500005];

void add(int u, int v, int w)
{
    e[++cnt] = {head[u], v, w};
    head[u] = cnt;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
    {
        int k, u, v, w;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> v >> w;
            if (j != 1)
            {
                add(u + i * m, v + i * m, 0);
                add(v + i * m, u + i * m, 0);
            }
            add(v, v + i * m, w);
            add(v + i * m, v, w);
            u = v;
        }
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        memset(dis, 0x3f, sizeof(dis));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[a] = 0;
        q.push({0, a});
        while(!q.empty())
        {
            int x = q.top().second, d = q.top().first;
            if (d > dis[x])
                continue;
            for (int i = head[x]; i; i = e[i].nxt)
                if (dis[x] + e[i].w < dis[e[i].to])
                {
                    dis[e[i].to] = dis[x] + e[i].w;
                    q.push({dis[e[i].to], e[i].to});
                }
        }
        cout << t[a] + t[b] + dis[b] << '\n';
    }
    return 0;
}
