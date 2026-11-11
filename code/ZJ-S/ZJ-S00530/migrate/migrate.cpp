#include <iostream>
#include <cstring>

#define int long long

using std::cin;
using std::cout;

const int N = 5000;

int f[N + 10][N + 10];
int c, T;
int x[N + 10], l[N + 10];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--)
    {
        int n, d, ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1, j = 1; i <= n; i++)
        {
            while (x[j] < x[i] - d)
                j++;
            l[i] = j;
        }
        l[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                memset(f[j], 0, sizeof(f[j]));
            f[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                for (int k = l[j]; k < j; k++)
                {
                    for (int t = 1; t <= j - i; t++)
                    {
                        f[j][t] += f[k][t - 1];
                        if (f[j][t])
                            break;
                    }
                }
                for (int t = 1; t <= j - i; t++)
                    if (f[j][t])
                    {
                        if (f[j][t] == 2)
                            ans++;
                        // cout << i << ' ' << j << ' ' << t << '\n';
                        break;
                    }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}