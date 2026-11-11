#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    ll ans = 0;

    for (int i = 1; i <= n; ++i)
    {   
        ll l = 1, r = i;
        ll cnt = 0;

        while (l <= r)
        {
            ll mid = (l + r) >> 1;
            if (mid * a[i] - (sum[i] - sum[i - mid]) <= m)
            {
                cnt = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (cnt * a[i] - (sum[i] - sum[i - cnt]) <= m) ans = max(ans, cnt);
        else ans = max(ans, cnt - 1);
    }

    cout << ans << '\n';

    return 0;
}