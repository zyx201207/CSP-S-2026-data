#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 510, M = 5e5 + 10;
const LL INF = 4e18;
int h[N + M], e[M * 2], ne[M * 2], w[M * 2], idx;
int n, m, d, q;
int val[M];
int bx[N], v[N], len;
LL dist[N][N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    int idxcase;
    scanf("%d%d%d%d%d", &idxcase, &n, &m, &d, &q);
    for(int i = 1; i <= m; i ++) scanf("%d", &val[i]);
    for(int i = 1; i <= n; i ++)
    {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j ++)
        {
            int a, t;
            scanf("%d%d", &a, &t);
            add(a, i + m, t), add(i + m, a, t);
        }
    }
    for(int i = 1; i <= m; i ++)
    {
        len = 0;
        for(int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j] - m;
            for(int l = 1; l <= len; l ++)
                dist[k][bx[l]] = dist[bx[l]][k] = min(dist[k][bx[l]], (LL)v[l] + w[j]);
            bx[++ len] = k, v[len] = w[j];
        }
    }
    for(int i = 1; i <= n; i ++) dist[i][i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int k = 1; k <= n; k ++)
            for(int j = 1; j <= n; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while(q --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        LL ans = INF;
        for(int i = h[x]; ~i; i = ne[i])
        {
            int ux = e[i] - m;
            for(int j = h[y]; ~j; j = ne[j])
            {
                int vx = e[j] - m;
                ans = min(ans, val[x] + val[y] + dist[ux][vx] + w[i] + w[j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
// (g++ -std=c++14 -O2 -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wconversion subway.cpp -o subway && ./subway && diff subway.out subway2.ans)