#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[200005],res;
bool cmp(ll x, ll y)
{
    return x > y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1; i <= n; i ++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout << a[1];
        return 0;
    }
    if(m==2)
    {
        ll ans = 0;
        for(ll i = 1; i <= n; i ++)
        {
            for(ll j = i+1; j <= n; j ++)
            {
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if(m==n)
    {
        ll ans = 1;
        for(ll i = 1; i <= n; i ++)
        {
            ans &= a[i];
        }
        cout << ans;
    }
    cout << a[m];
    return 0;
}
