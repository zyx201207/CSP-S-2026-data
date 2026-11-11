#include <bits/stdc++.h>
using namespace std;
int c, t;
long long ans;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        int n, d, x[2000005];
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin>>x[i];
        }
        int p = x[n] - x[n - 1];
        if (d / p > 1)
        {
            ans = (x[n] - x[1]) / d + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
