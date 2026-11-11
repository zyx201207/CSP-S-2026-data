#include <bits/stdc++.h>
using namespace std;

int a[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        if (d == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = i + 2; j <= n; j++)
            {
                if (((j - i) % d) % 2 == 1)
                {
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}
