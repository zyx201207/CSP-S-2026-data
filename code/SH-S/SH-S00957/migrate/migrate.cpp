#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5010;

int C, T;
int pre[N], ne[N];
int n;
LL D;
LL X[N];
LL sp[N][N], sn[N][N];
LL ans;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &C, &T);

    while (T -- )
    {
        ans = 0;

        scanf("%d%lld", &n, &D);
        for (int i = 1; i <= n; i ++ ) scanf("%lld", &X[i]);
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                sp[i][j] = sn[i][j] = 0;
        for (int i = 1, j = 1; i <= n; i ++ )
        {
            while (j < n && X[j + 1] - X[i] <= D) j ++ ;
            ne[i] = j;
        }
        for (int i = n, j = n; i; i -- )
        {
            while (j > 1 && X[i] - X[j - 1] <= D) j -- ;
            pre[i] = j;
        }

        for (int i = 1; i <= n; i ++ )
            for (int u = ne[i], p = i, j = 1; u != p; p = u, u = ne[u], j ++ )
                sn[i][j] = sn[i][j - 1] + u;
        for (int i = n; i; i -- )
            for (int u = pre[i], p = i, j = 1; u != p; p = u, u = pre[u], j ++ )
                sp[i][j] = sp[i][j - 1] + u;

        for (int i = 1; i <= n; i ++ )
            for (int u = i, j = i + 1, d = 1; j <= n; j ++ )
            {
                if (ne[u] == u) break;
                if (j == ne[u] + 1) d ++ , u = ne[u];
                if (sn[i][d - 1] - sp[j][d - 1] == 1) ans ++ ;
            }

        printf("%lld\n", ans);
    }
    return 0;
}
