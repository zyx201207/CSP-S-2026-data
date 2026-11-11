#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd()
{
    ll a = 0, q = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            q = -1;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        a = (a << 3) + (a << 1) + (ch ^ 48);
        ch = getchar();
    }
    return a * q;
}
const ll N = 5e3 + 10;
ll cc, t, n, x[N], f[N][N], c[N][N], d;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cc = rd(), t = rd();
    while(t--)
    {
        n = rd(), d = rd();
        for (ll i = 1; i <= n; i++)
        {
            x[i] = rd();
        }
        for (ll i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                f[i][j] = 0;
                c[i][j] = 2 * n;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i + 1; j <= n; j++)
            {
                if (x[j] - x[i] <= d)
                {
                    f[i][j] = 1;
                    c[i][j] = 1;
                }
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i + 1; j <= n; j++)
            {
                if (f[i][j])
                {
                    for (ll k = 1; k < i; k++)
                    {
                        if (c[k][j] > c[i][j] + c[k][i])
                        {
                            c[k][j] = c[i][j] + c[k][i];
                            f[k][j] = 1;
                        }
                        else if(c[k][j] == c[i][j] + c[k][i]&&c[k][j]!=2*n)
                        {
                            f[k][j]++;
                        }
                    }
                }
            }
        }
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i + 1; j <= n; j++)
            {
                if (f[i][j] == 2)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
