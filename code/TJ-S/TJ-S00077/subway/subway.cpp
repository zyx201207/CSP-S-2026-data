#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int w[500005], k[505], a[505][500005], t[505][500005];
int c, n, m, d, q;
int ans = 0;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        //if (c == 7 || c == 8 || c == 9 || c == 10 || c == 11)

    }
    return 0;
}
