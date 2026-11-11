#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e6 + 10, M = 4e6 + 10;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long, int> PLI;

int tmp, n, m, d, Q;
int h[N], e[M], ne[M], w[M], idx;
LL dist[N], c[N];
bool st[N];
PII ver[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

LL dijkstra(int S, int T)
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    memset(st, 0, sizeof st);

    priority_queue<PLI, vector<PLI>, greater<PLI>> q;
    q.push({0, S});
    while (q.size())
    {
        int t = q.top().second;
        q.pop();

        if (t == T) return dist[t];

        if (st[t]) continue;
        st[t] = true;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                q.push({dist[j], j});
            }
        }
    }

    return -1;
}

LL bfs(int S, int T)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;

    queue<int> q;
    q.push(S);
    st[S] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        if (t == T) return dist[t] * w[1];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (st[j]) continue;

            st[j] = true;
            dist[j] = dist[t] + 1;
            q.push(j);
        }
    }

    return -1;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &tmp, &m, &n, &d, &Q);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &c[i]);

    int cnt = n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i ++ )
    {
        cnt ++ ;
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= 2 * k; j ++ )
            if (j & 1) scanf("%d", &ver[j + 1 >> 1].first);
            else scanf("%d", &ver[j + 1 >> 1].second);
        int v = cnt;
        for (int j = 1; j <= k; j ++ )
            add(ver[j].first, v, ver[j].second), add(v, ver[j].first, ver[j].second);
    }

    if (tmp >= 12 && tmp <= 19)
    {
        while (Q -- )
        {
            int S, T;
            scanf("%d%d", &S, &T);
            printf("%lld", bfs(S, T) + c[S] + c[T]);
        }
        return 0;
    }

    while (Q -- )
    {
        int S, T;
        scanf("%d%d", &S, &T);
        printf("%lld\n", dijkstra(S, T) + c[S] + c[T]);
    }

    return 0;
}
