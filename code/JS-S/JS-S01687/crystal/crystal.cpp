#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 500005 ;
ll n , m , i , l , r , mid , ans , sum[MAXN] , a[MAXN] ;
bool check(ll x){
    ll minn = LONG_LONG_MAX ;
    for(ll i=1;i<=n-x+1;i++){
        minn = min(minn,a[i+x-1]*x-(sum[i+x-1]-sum[i-1])) ;
    }
    return minn<=m ;
}
int main(){
    freopen("crystal.in","r",stdin) ;
    freopen("crystal.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m ;
    for(i=1;i<=n;i++){
        cin >> a[i] ;
    }
    sort(a+1,a+1+n) ;
    for(i=1;i<=n;i++){
        sum[i] = sum[i-1]+a[i] ;
    }
    l = 1 ;
    r = n ;
    while(l<=r){
        mid = (l+r) >> 1 ;
        if(check(mid)){
            l = mid+1 ;
            ans = mid ;
        }else {
            r = mid-1 ;
        }
    }
    cout << ans ;
    return 0 ;
}
