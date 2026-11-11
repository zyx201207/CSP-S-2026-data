#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
    int f = 1;
    ll x = 0;
    int ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll n, m;
ll a[500010];
ll ans = 0;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    ll d = 0, l = 1;
    for(int i = 2; i <= n; i++)
    {
        while(d > m)
        {
            l++;
            d -= (a[i] - a[l]);
        }
        ans = max(ans, i - l);
        d += (a[i] - a[i - 1]) * (i - l);
    }
    cout << ans << endl;
    return 0;
}
