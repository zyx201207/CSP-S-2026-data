#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505][500005],t[500005],k,x,y,u,v,sum = 0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for (int i = 1;i <= 505;i++)
    {
        for (int j = 1;j <= 500005;j++)
        {
            a[i][j] = 0;
        }
    }
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> t[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> k;
        for (int j = 1;j <= k;j++)
        {
            cin >> x >> y;
            a[j][x] = y;
        }
    }
    for (int i = 1;i <= q;i++)
    {
        cin >> u >> v;
        sum = t[u] + t[v];
        for (int j = 1;j <= n;j++)
        {
            sum += a[j][u] + a[j][v];
        }
        cout << sum << endl;
    }
    return 0;
}
