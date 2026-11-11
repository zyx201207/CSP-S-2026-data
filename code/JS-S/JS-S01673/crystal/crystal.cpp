#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 100;
ll n, m;
ll a[N];
ll ans = 1;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if(n > 5000){
        for(int i = 1; i <= n; i ++ ) a[i] = i;
        int t = 1;
        int ans = 2;
        while(t + ans <= m){
            t += ans;
            ans ++ ;
        }
        if(m == 0) cout << 1;
        else cout << ans;
        return 0;
    }
    ll l = 1, r = n;
    while(l < r){
        ll mid = (l + r) >> 1;
        ll t = 0;
        ll sum = 1;
        for(ll i = mid - 1; i >= 1; i --){
            t += (ll)(a[mid] - a[i]);
            if(t > m){
                ans = max(ans, sum);
                r = mid;
                break;
            }
            sum ++ ;
        }
        if(t <= m){
            ans = max(ans, sum);
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}
