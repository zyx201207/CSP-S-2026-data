#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 5;
ll c, t, n, d, x[N], ans;
bool check()
{
    for (int i = 1; i < n; i++)
    {
        if (x[i] - x[i - 1] != x[i + 1] - x[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        if(check())
        {
            ll d0 = x[2] - x[1];
            if (d0 * 2 <= d && d < d0 * 3)
            {
                ans = n - 4 + 1;
            }
            else
            {
                ans = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}