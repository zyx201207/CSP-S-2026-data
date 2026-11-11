#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005];
ll b[500005];
ll k[500005];
ll s[500005];
ll n,m;
ll ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1;i <= n;i ++)cin>>a[i];
    sort(a + 1,a + n + 1);
    for(ll i = 2;i <= n;i ++)
    {
        b[i] = a[i] - a[i - 1];
        s[i] = s[i - 1] + b[i];
        k[i] = k[i - 1] + (i - 1) * b[i];
    }
    for(ll i = 1;i <= n;i ++)
    {
        if(b[i] > m)break;
        while(a[i] == a[i + 1] && i <= n)i ++;
        ll j = 1;
        ll sum = k[i] - s[j];
        ll cnt = i;
        while(sum > m && j <= i)
        {
            if(cnt < ans)break;
            j ++;
            cnt --;
            sum = sum - s[i] + s[j];
        }
        ans = max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
