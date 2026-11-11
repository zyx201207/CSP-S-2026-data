#include <bits/stdc++.h>
using namespace std;
vector<int> linker[1000005];
int n, k;
unsigned long long U;
int a[64], a_l = 0;
bool visited[1000005];
bool check(unsigned long long S)
{
    memset(a, 0, sizeof(a));
    a_l = 0;
    int link = k;
    for (unsigned long long i, j = 1; i <= S; i <<= 1, j++)
        if (i & S)
            a[a_l++] = j;
    for (int i = 1; i < a_l; i++)
        for (int j = 0; j < linker[i].size(); j++)
            if (a[i - 1] == linker[i][j])
                link--;
    return link <= 2;
}
int dfs(int x, int y)
{
    if (visited[x])
        return 0;
    if (x == y)
        return 0;
    int ret = INT_MAX;
    visited[x] = 1;
    for (int i = 0; i < linker[x].size(); i++)
        ret = min(ret, dfs(linker[x][i], y) + 1);
    return ret;
}
int f(unsigned long long S)
{
    int ret = 0;
    for (int i = 0; i < a_l; i++)
        for (int j = 1; j <= n; j++)
        {
            memset(visited, 0, sizeof(visited));
            ret = max(ret, dfs(a[i], j));
        }
    return ret;
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            linker[i].resize(0);
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            linker[u].push_back(v);
            linker[v].push_back(u);
        }
        U = 1 << n;
        int ans = INT_MAX;
        for (unsigned long long i = 1; i <= U; i++)
            if (n - __builtin_popcount(i) == k)
                if (check(i))
                    ans = min(ans, f(i));
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}