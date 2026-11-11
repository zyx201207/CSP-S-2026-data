#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 7;
const ll MAXM = 1e18 + 7;
ll n, m, ans = 0;
ll a[MAXN];
map<ll, ll> mp;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    int k = 0;
    for (auto i : mp) {
        ll num = i.first;
        if (m - k < mp[num]) continue;
        mp[num + 1] += mp[num];
        k += mp[num];
        mp[num] = 0;
        ans = max(ans, mp[num + 1]);
    }
    cout << ans << '\n';
    return 0;
}