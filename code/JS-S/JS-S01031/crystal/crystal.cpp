#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
ll n;
ll k;
ll ans;
ll a[N];
ll sum[N];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
int main()
{
    openfile("crystal");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for(ll i = 1;i <= n;++i)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(ll i = 1;i <= n;++i)
        sum[i] = sum[i - 1] + a[i];
    ll l = n;
    for(ll r = n;r >= 1;--r)
    {
        while(l >= 1 && r * a[r] - sum[r - 1] - k <= l * a[r] - sum[l - 1])
        {
            ans = max(ans,r - l + 1);
            l--;
        }
    }
    cout << ans;
    return 0;
}
