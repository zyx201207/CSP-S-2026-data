#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[500010], sum[500010], ans;

ll check(ll x)
{
    ll tans = 1;
    ll sum = 0;
    ll i = x-1;
    while(i != 0)
    {
        if (sum + (a[x] - a[i]) > m)
            break;
        sum = sum + a[x] - a[i];
        i--;
        tans++;
    }
    return tans;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if (n <= 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, check(i));
        }
        cout << ans;
    }
    else
    {
        ll sum = 0;
        ll cha = a[2] - a[1];
        ll add = cha;
        ans = 1;
        while(ans <= n)
        {
            if (sum + add > m)
                break;

            sum += add;
            add += cha;
            ans++;
        }
        cout << min(ans, n);
    }
    return 0;
}
