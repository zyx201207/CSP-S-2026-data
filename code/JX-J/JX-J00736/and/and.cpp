
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[200005], a[200005], pos[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ll ans = 0, n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        f[i] = a[i] & f[i - 1];
        for (int j = 1; j <= m; j++) pos[i] = i;
    }
    for (int i = m + 1; i <= n; i++)
    {
        int maxp;
        for (int j = 1; j <= m; j++)
        {
            ll x = a[i];
            for (int k = 1; k <= m; k++)
            {
                if (k != j) x &= a[pos[j]];
            }
            if (x > f[i])
            {
                f[i] = x;
                maxp = j;
            }
        }
        pos[maxp] = i;
    }
    cout << f[n];
    return 0;
}
