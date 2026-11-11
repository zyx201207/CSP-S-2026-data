#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    vector<ll> pre(n+1, 0);
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin()+1, a.end());
    for (ll i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    ll ans = INT_MIN;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            ll sum = pre[j]-pre[i-1]+m;
            ll cnt = j + 1 - i;
            if (sum % cnt == 0 && (sum / cnt >= a[j]))
            {
                //cout << i << ' ' << j <<' '<<  cnt << ' '<<sum << endl;
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
    return 0;
}
