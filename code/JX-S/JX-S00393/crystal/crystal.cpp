#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005];
ll s[500005];
ll n,m;
bool check(ll siz)
{
    ll minn = 1e18+1;
    for(ll i = 1,j = siz;j<=n;i++,j++)
    {
        ll val = a[j]*siz-(s[j]-s[i-1]);
        minn = min(minn,val);
    }
    return minn<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(ll i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)s[i] = s[i-1]+a[i];
    ll ans = 0;
    ll l = 1,r = n;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}
