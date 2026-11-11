#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<char> s(n+1);
    for(ll i=1;i<=n;++i)
    {
        cin >> a[i] >> s[i];
    }
    ll l=1;
    ll r=n;
    ll lt;
    ll rt;
    ll ans=0;
    while(l<r)
    {
        lt=a[l];
        rt=a[r];
        if(s[l]==s[r])
        {
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r])l++,r--;
            else
            {
                a[l]-=a[r];
                r--;
            }
        }
        else
        {
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else if(a[l]==a[r])
            {
                ans+=a[l];
                l++;
                r--;
            }
            else
            {
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }
        }
    }
    cout << ans;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}