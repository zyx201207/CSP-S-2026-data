#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int a[N];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, d;
        cin >> n >> d;
        int tmp = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == 1)
            {
                tmp = a[i];
            }
            a[i] -= tmp;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 3; a[j] - a[i] <= 2 * d + 1 && j <= n; j++)
            {
              //  cout << a[j] - a[i] << '\n';
                if (a[j] - a[i] == 2 * d - 1)
                {
                    ans++;
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
