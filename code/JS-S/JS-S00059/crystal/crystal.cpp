#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,ans;
ll* a;
ll l = LLONG_MAX,r = LLONG_MIN;
bool check(ll x)
{
    ll cnt = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] < x) cnt += x - a[i];
        else break;
    }
    return cnt <= m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    a = new ll[n]();
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        l = min(a[i],l);
        r = max(r,a[i]);
    }
    sort(a,a + n);
    while(l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    for(int i = 0;i < n;i++)
    {
        if(a[i] <= l) ans++;
        else break;
    }
    cout << ans;
    return 0;
}
