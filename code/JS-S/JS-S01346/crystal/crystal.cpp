#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], ans;
ll d[500005],v[500005],pre[500005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1; i <= n; i ++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i = 1; i <= n; i ++){
        d[i] = a[i]-a[i-1];
        v[i] = d[i]*(i-1);
        pre[i] = v[i]+pre[i-1];
    }
    ll l = 1, r = 1;
    while(l<=r && r <= n){
        while(pre[r] - pre[l-1] <= m && r <= n){
            ans = max(ans,r-l+1);
            r ++;
        }
        while(pre[r] - pre[l-1] > m && l <= r)l ++;
    }
    cout << ans << '\n';
    return 0;
}
