#include<bits/stdc++.h>
using namespace std ;
int n ;
long long m , arr[500005] ;
int main() {
    freopen("crystal.in","r",stdin) ;
    freopen("crystal.out","w",stdout) ;
    ios::sync_with_stdio() ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i] ;
    }
    sort( arr + 1 , arr + 1 + n ) ;
    long long sum = 0 ;
    int ans ;
    for ( int i = 1 ; i <= n ; i++ ) {
        long long d = ( i - 1 ) * ( arr[i] - arr[ i - 1 ] ) ;
        if( sum + d <= m ) {
            sum += d ;
        } else {
            ans = i - 1 ;
            break ;
        }
    }
    cout << ans ;
    return 0 ;
}
