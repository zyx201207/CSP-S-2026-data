#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
ll a[114514];

bool cmp(ll x, ll y)
{
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, cmp);
    if (n <= 25)
    {
        ll ans = a[1];
        for (ll i = 2; i <= m; i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
    }

    else if(m==n)
    {
        ll ans=a[1];
        for(ll i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }

        cout<<ans;
    }

    // m=n-1
    else if (m == n - 1)
    {
        ll ans = 0;
        ll man = 2147483647;
        for (ll i = 1; i <= n; i++)
        {
            if (i != 1)
                ans = a[1];
            if (i == 1)
                ans = a[2];
            for (ll j = 1; j <= n; j++)
            {
                if (i != 1 && j != i && j!=1)
                    ans = ans & a[j];
                if (i == 1 && j != 1 && j != 2)
                    ans = ans & a[j];
            }
            man = max(man, ans);
        }
        cout<<man;
    }

    return 0;
}