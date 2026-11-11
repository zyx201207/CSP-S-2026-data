#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m;
ll a[N];
ll q[N];
bool check(ll x, ll qnwl)
{
    ll que = q[qnwl - 1] - q[x - 1];
    ll zong = a[qnwl] * (qnwl - x);
    ll need = zong - que;
    return need <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;++i)
    {
        q[i] = q[i - 1] + a[i];
    }
    ll ans = LLONG_MIN;
    for(int i = 1;i <= n;++i)
    {
        ll l = 1;
        ll r = i;
        while(l < r)
        {
            ll m = (l + r) / 2ll;
            if(check(m, i))
            {
                r = m;
            }
            else
            {
                l = m + 1ll;
            }
        }
        //cout << i << ": " << l << "\n";
        ll tmp = i - r + 1ll;
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}
