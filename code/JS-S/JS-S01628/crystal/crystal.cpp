#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n,m,a[N];
bool check(ll x) 
{
    ll sum = 0;
    for (ll i = 1; i <= x; i++) sum += a[i];
    if (x * a[x] - sum <= m) return true;
    for (ll i = x + 1; i <= n; i++) 
    {
        sum = sum - a[i - x] + a[i];
        if (x * a[i] - sum <= m) return true;
    }
    return false;
}
int main() 
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    ll lft = 1,rgt = n + 1;
    while (lft < rgt) 
    {
        ll mid = (lft + rgt) / 2;
        if (check(mid)) lft = mid + 1;
        else rgt = mid;
    }
    cout << rgt - 1 << endl;
    return 0;
}
