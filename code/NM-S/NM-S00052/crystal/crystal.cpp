#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500010];
long long cj[500010];
long long ans = 0;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int zws = n / 2;
    if (n % 2 == 1) zws++;

    int cz = m;

    for (int i = 1; i <= zws; i++) {
        cj[i] = a[zws] - a[i];
    }

    sort(cj + 1, cj + zws + 1);

    for (int i = 1; i <= zws; i++) {
        if (cz - cj[i] >= 0)
        {
            cz -= cj[i];
            ans++;
        }
        else
        {
            cout << ans;
            return 0;
        }
    }

    if (cz <= 0)
    {
        cout << ans;
        return 0;
    }

    int newc = 0;
    int ii = zws;
    while (1)
    {
        if (ii >= n)
        {
            cout << ans;
            return 0;
        }
        newc = a[ii + 1] - a[ii];
        if (cz - ans * newc >= 0)
        {
            cz = cz - ans * newc;
            ans++;
        }
        else
        {
            cout << ans;
            return 0;
        }
        ii++;
    }

    cout << ans;
    return 0;
}
