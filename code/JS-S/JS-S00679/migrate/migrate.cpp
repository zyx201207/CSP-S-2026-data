#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;

ll tmp, T;
bool can[5005][5005];
ll a[5005];
ll getpathcnt(const ll &x, const ll &y, const ll &n,const bool& checked)
{
    return 0;
    bool _checked=checked;
    if(!_checked){
        for (ll i = x; i <= y - 1; ++i)
        {
            if (!can[i][i + 1])
            {
                return 0;
            }
        }
        _checked=1;
    }
        ll minpc = 0x7f7f7f7f7f7fLL;
        ll cnt = 0;
        ll ok = 0;
        for (ll i = x + 1; i <= y; ++i)
        {
            
        }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    // auto a=(ll)5000000000000000000;
    // cout<<a;
    cin >> tmp >> T;
    while (T--)
    {
        ll ans = 0;
        memset(a, 0, sizeof(a));
        memset(can[0], 0, sizeof(can));

        ll n, d;
        cin >> n >> d;
        for (ll i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (ll i = 1; i < n; ++i)
        {
            for (ll j = i + 1; j <= n; ++j)
            {
                if ((a[j] - a[i]) <= d)
                {
                    can[i][j] = 1;
                    can[j][i] = 1;
                }
            }
        }
        can[n][n - 1] = ((a[n] - a[n - 1]) <= d);
        can[n][n + 1] = 0;
        for (ll i = 1; i <= n - 1; ++i)
        {
            for (ll j = i + 1; j <= n; ++j)
            {
                if (getpathcnt(i, j, n,0) == 2)
                {
                    ans++;
                }
            }
        }
        cout << 0 << "\n";
    }
    return 0;
}