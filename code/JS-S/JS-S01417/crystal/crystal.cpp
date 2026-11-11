#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ll n , m; cin >> n >> m;
    for (ll i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a + 1 + n);
    ll l = 1 , r = n , ans = -1;
    while(l <= r){
        ll mid = l + r >> 1 , cnt = m , sum = 0;
        for (ll i = mid;i >= 1;i--){
            cnt -= a[mid] - a[i];
            if (cnt < 0) break;
            sum++;
        }
        ans = max(ans , sum);
        if (cnt >= 0){
            l = mid + 1;
        }else r = mid - 1;
    }
    ll sum = ans;
    for (ll i = ans + 1;a[i] == a[ans];i++) sum++;
    cout << sum;
    return 0;
}
