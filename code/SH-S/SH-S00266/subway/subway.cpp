#include <bits/stdc++.h>
using namespace std;
struct node
{
    int line, stat;
};
int c, n, m, d, q;
vector<node> linker[500005];
int w[500005], t[505][20005], k[505];
bool visited[500005];
long long dfs(int x, int y, int line)
{
    if (visited[x])
        return 0ll;
    if (x == y)
        return 0ll;
    visited[x] = 1;
    int a[505];
    long long ret = 0ll;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < linker[x].size(); j++)
            if (i == linker[x][j].line)
                if (i != line)
                    a[i] += dfs(linker[x][j].stat, y, i) + t[line][x] + t[i][x];
                else
                    a[i] += dfs(linker[x][j].stat, y, i);
    sort(a + 1, a + n + 1);
    return a[1];
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        int last_a;
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
        {
            int a, t;
            scanf("%d %d", &a, &t);
            if (j != 1)
            {
                linker[a].push_back((node){i, last_a});
                linker[last_a].push_back((node){i, a});
            }
            last_a = a;
        }
    }
    while (q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < linker[x].size(); i++)
        {
            memset(visited, 0, sizeof(visited));
            ans = min(ans, dfs(x, y, linker[x][i].line)) + t[linker[x][i].line][i];
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}