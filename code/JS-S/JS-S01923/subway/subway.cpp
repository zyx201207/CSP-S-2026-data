#include <bits/stdc++.h>

using namespace std;

long long w[500005], k[505], a[505], t[505], ans[605][605], d[605];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    long long c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(long long i = 1; i <= m; i++)
    {
        cin >> w[i];
    }

    for(int i = 1; i <= 600; i++)
    {
        for(int j = 1; j <= 600; j++)
        {
            ans[i][j] = 605;
        }
    }
    for(long long i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(long long j = 1; j <= k[i]; j++)
        {
            cin >> a[j] >> t[j];
        }
        for(long long j = 1; j <= k[i]; j++)
        {
            for(long long K = 1; K <= k[i]; K++)
            {
                ans[a[j]][a[K]] = t[K];
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int K = 1; K <= m; K++)
            {
                if(ans[i][j] > ans[i][K] + ans[K][j] + ans[K][K])
                {
                    ans[i][j] = ans[i][K] + ans[K][j] + ans[K][K];
                }
            }

        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << w[x] + ans[x][x] + w[y] + ans[x][y]<< endl;
    }
    return 0;
}
