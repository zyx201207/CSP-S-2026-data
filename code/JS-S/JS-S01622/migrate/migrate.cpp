#include<bits/stdc++.h>
using namespace std ;
int n ;
long long arr[2000005] , d ;
int nxt[2000005] ;
int len ;
int cntans = 0 ;
void dfs( int x , int cnt , int v ) {
    //cout << x << "!!!\n" ;
    if ( cntans > 2 || x > n ) return ;
    if ( x == v ) {
        if ( cnt == len ) cntans++ ;
        return ;
    }
    if ( cnt >= len ) return ;
    for ( int i = min( nxt[x] , n ) ; i > x ; i-- ) {
        dfs( i , cnt + 1 , v ) ;
        if ( cntans > 2 ) return ;
    }
}
int main() {
    freopen("migrate.in","r", stdin) ;
    freopen("migrate.out","w",stdout) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int T , c ;
    cin >> c >> T ;
    while( T-- ) {
        long long ans = 0 ;
        cin >> n >> d ;
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> arr[i] ;
        }
        for ( int i = 1 , x = 1 ; i <= n ; i++ ) {
            if ( arr[ x + 1 ] - arr[i] > d && x >= i && arr[x] - arr[i] <= d ) {
                nxt[i] = x ;
            } else if ( arr[x] - arr[i] > d ) {
                nxt[i] = -1 ;
            } else {
                while( 1 ) {
                    if ( x >= n) break ;
                    x++ ;
                    if ( arr[ x + 1 ] - arr[i] > d && x >= i ) {
                        break ;
                    }
                }
                nxt[i] = x ;
            }
            //cout << i << " " << nxt[i] << "?\n" ;
        }
        for ( int u = 1 ; u <= n ; u++ ) {
            for ( int v = u + 1 ; v <= n ; v++ ) {
                int x = u ;
                len = 0 ;
                cntans = 0 ;
                bool f = 0 ;
                while( x < v ) {
                    if ( nxt[x] == -1 || nxt[x] == x ) {
                        f = 1 ;
                        break ;
                    }
                    x = nxt[x] ;
                    len++ ;
                    //cout << x << "\n" ;
                }
                if ( f ) break ;
                dfs( u , 0 , v ) ;
                //cout << u << " " << v << " " << cntans << "\n" ;
                if ( cntans == 2 ) ans++ ;
            }
        }
        cout << ans << "\n" ;
    }
    return 0 ;
}
