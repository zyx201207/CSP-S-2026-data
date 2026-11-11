#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int son, wts, wtf, self, father;
}edge[1000005];
void add(int u, int v, int f, int wts, int wtf)
{
    edge[u].self = u;
    edge[u].son = v;
    edge[u].father = f;
    edge[u].wts = wts;
    edge[u].wtf = wtf;
}
int w[500005], k[505], a[505][500005], t[505][500005];
int depth[500005], logn[25][500005];
void deep(int x, int n, int finall)
{
    int i = x;
    while (i == finall)
    {
        depth[i] = depth[edge[i].son] - 1;
        i = edge[i].father;
    }
    depth[i] = depth[edge[i].son] - 1;
    for (int j = 1; j <= n; j++)
    {
        if (depth[i] != 0)
            continue;
        else
        {
            depth[i] = depth[edge[i].father] + 1;
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (j == 2)
                add(a[i][j - 1], a[i][j], -1, t[i][j] + t[i][j - 1], -1);
            if (j >= 3)
            {
                add(a[i][j - 1], a[i][j], a[i][j - 2], t[i][j] + t[i][j - 1], t[i][j - 1] + t[i][j - 2]);
            }
        }
    }
    depth[a[n][k[n]]] = m;
    for (int i = n; i >= 1; i--)
    {
        deep(a[i][k[i]], k[i], a[i][1]);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << depth[i] << endl;
    }
}
