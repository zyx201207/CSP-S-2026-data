#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long LL;
typedef pair<int, LL> PII;
typedef pair<LL, int> PLI;

const int N = 5010, M = 200010;

int C, n, m, D, Q;
int W[M];
LL ed[N][N];
LL d[N][N];
priority_queue<PLI, vector<PLI>, greater<PLI> > q;
bool st[M];
LL dist[M];
vector<PII> vt[M];

void dijkstra(int S)
{
    for (int i = 1; i <= n; i ++ ) dist[i] = 1e18, st[i] = false;
    dist[S] = 0;
    q.push({0, S});

    while (q.size())
    {
        auto t = q.top(); q.pop();
        int u = t.se;

        if (st[u]) continue;
        st[u] = true;

        for (int j = 1; j <= n; j ++ )
        {
            if (dist[j] > dist[u] + ed[u][j])
            {
                dist[j] = dist[u] + ed[u][j];
                q.push({dist[j], j});
            }
        }
    }

    for (int i = 1; i <= n; i ++ ) d[S][i] = dist[i];
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(ed, 0x3f, sizeof ed);
    memset(d, 0x3f, sizeof d);

    scanf("%d%d%d%d%d", &C, &n, &m, &D, &Q);
    for (int i = 1; i <= m; i ++ ) scanf("%d", &W[i]);
    for (int i = 1; i <= n; i ++ )
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j ++ )
        {
            int x, t;
            scanf("%d%d", &x, &t);
            vt[x].push_back({i, t});
        }
    }

    for (int i = 1; i <= m; i ++ )
    {
        int sz = vt[i].size();
        for (int a = 0; a < sz; a ++ )
            for (int b = 0; b < sz; b ++ )
                if (a != b)
                    ed[vt[i][a].first][vt[i][b].first] = min(ed[vt[i][a].first][vt[i][b].first], vt[i][a].second + vt[i][b].second);
    }

    for (int i = 1; i <= n; i ++ ) dijkstra(i);

    while (Q -- )
    {
        int S, T;
        scanf("%d%d", &S, &T);

        LL ans = 2e18;
        for (auto a : vt[S])
            for (auto b : vt[T])
                ans = min(ans, d[a.first][b.first] + a.second + b.second);

        printf("%lld\n", ans + W[S] + W[T]);
    }
    return 0;
}
