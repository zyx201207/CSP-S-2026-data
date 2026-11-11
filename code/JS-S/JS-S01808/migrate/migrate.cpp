#include <bits/stdc++.h>
using namespace std;
long long x[2000005], rdc[2000005];
int main()
{
//    freopen("migrate.in", "r", stdin);
//    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        long long n;
        long long d;
        cin >> n >> d;
        memset(x, 0, n);
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            rdc[i] = rdc[i - 1] + x[i];
        }
        for (int u = 1; u <= n; u++)
        {
            for (int v = u + 2; v <= n; v++)
            {
                int ans = 0, rem = u, i = u;
                while (i <= v)
                {
                    if (abs(x[i] - x[rem]) > d)
                    {
                        rem = i - 1;
                        i = rem;
                        ans++;
                    }
                    i++;
                }
                ans++;
                int anss = 0, remm = u, dd = 0;
                for (int i = u; i <= v; i++)
                {
                    if (abs(rdc[remm] - remm[i]) <= d)
                    {
                        dd = max(dd, abs(rdc[remm] - remm[i]));
                        remm = i;
                        i = remm;
                    }
                }
                for (int i = u; i <= v; i++)
                {
                    if (abs(rdc[remm] - remm[i]) == dd)
                    {
                        anss++;
                    }
                }
            }
        }
        cout << anss << endl;
    }
}
