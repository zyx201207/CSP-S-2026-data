#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll n , m , a[500010] , s[500010] ;
ll ans ;
bool check ( ll l , ll r ) {
    ll tot = s[r-1]-s[l-1] ;
    if ( (r-l)*a[r] <= tot+m ) return true ;
    else return false ;
}
int main () {
    freopen("crystal.in","r",stdin) ;
    freopen("crystal.out","w",stdout) ;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    cin >> n >> m ;
    for ( ll i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    sort(a+1,a+n+1) ;
    for ( ll i = 1 ; i <= n ; i ++ ) s[i]=s[i-1]+a[i] ;
    for ( ll i = 1 ; i <= n ; i ++ ) {
        ll l = 1 , r = i , mid = (l+r)/2 , res=mid ;
        while ( l <= r ) {
            mid = (l+r)/2 ;
            if ( check(mid,i) ) {
                res = mid ;
                r = mid-1 ;
            } else {
                l = mid+1 ;
            }
        }
        ans = max(ans,i-res+1) ;
    }
    cout << ans ;
    return 0 ;
}
