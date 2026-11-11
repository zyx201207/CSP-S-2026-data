#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
constexpr int N = 500007;
ll n, m;
map<ll, ll> a;
ll mx = 0;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1, x; i <= n; ++i)
        cin >> x, a[x]++, mx = max(mx, a[x]);
    if (!m)
        return cout << mx, 0;
    if (a.size() == 1)
        return cout << n, 0;
    mx = 0;
    a[-1000000000000000ll] = -1;
    auto i = a.begin();
    for (++i; i != a.end(); ++i)
    {
        ll tm = m, crybas = i->first, ans = i->second;
        auto j = i;
        for (--j; j != a.begin() && tm; --j)
        {
            ll diff = crybas - j->first, num = j->second;
            if (tm < diff * num)
            {
                ans += tm / diff;
                break;
            }
            tm -= diff * num;
            ans += num;
        }
        mx = max(mx, ans);
    }
    cout << mx;
    return 0;
}
