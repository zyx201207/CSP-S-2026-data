#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long a[N];
int main()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    long long c, q;
    cin >> c >> q;
    while (q--)
    {
        long long n, m;
        cin >> n >> m;
        cin >> a[1] >> a[2];
        long long k = a[2] - a[1];
        bool f = false;
        for (long long i = 3;i <= n;i++)
        {
            cin >> a[i];
            if (a[i] - a[i - 1] != k)
            {
                f = true;
            }
        }
        if (a[n] - a[1] <= m)
        {
            cout << 0 << endl;
            continue;
        }
        long long x;
        for (long long i = 1;i <= n;i++)
        {
            if (a[i] - a[1] <= m && a[n] - a[1] <= m)
            {
                x = i;
                break;
            }
        }
        if (!f)
        {
            if (m % k == 0 || m <= k * 2)
            {
                cout << 0 << endl;
                continue;
            }
            long long x = m / k;
            cout << n - (2 * x - 1) << endl;
        }
        else
        {
            if (a[n] - a[1] <= m)
            {
                cout << 0 << endl;
            }
            else
            {
                long long ans = 0;
                for (long long j = x + 1;j <= n;j++)
                {
                    if (a[j] - a[x - 1] <= m && a[j] - a[x + 1] > m && a[j] - a[x - 2] > m)
                    {
                        ++ans;
                    }
                    else
                    {
                        if (a[j] - a[x - 1] > m && a[j] - a[x + 1] <= m && abs (a[j] - a[x + 2]) > m)
                        {
                            ++ans;
                        }
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
