#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t, n, d, cnt = 0;
    int x[100001];
    bool y = 1;
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> d;
        for (int j = 1; j <= n; j++)
        {
            cin >> x[j];
        }
        for (int k = 1; k <= n - d - 1; k++)
        {
            for (int l = k; l <= d + k; l++)
            {
                if (x[l + 1] - x[l] > d)
                {
                    y = 0;
                    break;
                }
            }
            if (y)
            {
                cnt++;
            }
        }
        if (n % 2 == 1 && d % 2 == 1)
        {
            cnt--;
        }
        cout << cnt << endl;
        cnt = 0;
        y = 1;
    }
}
