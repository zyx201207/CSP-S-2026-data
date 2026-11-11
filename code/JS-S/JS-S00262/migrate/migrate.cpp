#include <bits/stdc++.h>
using namespace std;

long long x[2000005];
long long p[2000005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long c, t;
    cin >> c >> t;
    while(t--)
    {
        long long n, d;
        cin >> n >> d;
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
            p[i] = abs(x[i] - x[i - 1]);
        }
        for(int i = 1; i <= n; i++)
        {
            long long tmp = 0;
            for(int j = i; j < i + d && j < n; j++) tmp += p[j];
            if(tmp <= d && i + 1 < n)
            {
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
