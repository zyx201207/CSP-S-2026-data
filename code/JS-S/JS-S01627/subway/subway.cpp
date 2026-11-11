#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    bool l[MAXN][MAXN];
    int w[MAXN], t[505][MAXN], f[505][MAXN], lst[MAXN][MAXN], k[505];
    cin >> c >> n >> m >> d >> q;
    for(int i =1; i<=m; i++)
    {
       cin >> w[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin >> k[i];
        for(int j=1; j<=k[i]; j++)
        {
            cin >> f[i][j] >> t[i][f[i][j]];

        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k[i]-1; j++)
        {
            lst[k[j]][k[j+1]] = t[i][k[j]] + t[i][k[j+1]];
            l[k[j+1]][k[j]] = true;
        }
    }
    for(int i=1; i<=q; i++)
    {
        int x, y;
        cin >> x >> y;

    }
    return 0;
}