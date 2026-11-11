#include<bits/stdc++.h>
using namespace std ;
int n , m , d ;
int w[500005] ;
int len[505] ;
int dist[1005][1005] ;
int a[505][500005] ;
int t[505][500005] ;
int main(){
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    ios::sync_with_stdio() ;
    cin.tie(0) ;
    cout.tie(0) ;
    int c , q ;
    cin >> c >> n >> m >> d >> q ;
    for ( int i = 1 ; i <= m ; i++ ) {
        cin >> w[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> len[i] ;
        for ( int j = 1 ; j <= len[i] ; j++ ) {
            cin >> a[i][j] >> t[i][j] ;
        }
    }
    memset( dist , 0x3f , sizeof( dist ) ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= len[i] ; j++ ) {
            for ( int k = j + 1 ; k <= len[i] ; k++ ) {
                dist[ a[i][j] ][ a[i][k] ] = min( dist[ a[i][j] ][ a[i][k] ] , t[i][j] + t[i][k] ) ;
                dist[ a[i][k] ][ a[i][j] ] = dist[ a[i][j] ][ a[i][k] ] ;
            }
        }
    }
    /*
    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cout << dist[i][j] << " " ;
        }
        cout << "\n" ;
    }
    */
    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if( i == j ) continue ;
            for ( int k = 1 ; k <= m ; k++ ) {
                if ( j == k || i == k ) continue ;
                dist[j][k] = min( dist[j][k] , dist[j][i] + dist[i][k] ) ;
                dist[k][j] = dist[j][k] ;
                //cout << i << " " << j << " " << k << " " << dist[j][k] << " " << dist[j][i] + dist[i][k] << "\n" ;
            }
        }
    }
    /*
    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cout << dist[i][j] << " " ;
        }
        cout << "\n" ;
    }
    */
    while( q-- ) {
        int x , y ;
        cin >> x >> y ;
        cout << dist[x][y] + w[x] + w[y] << "\n" ;
    }
    return 0 ;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
