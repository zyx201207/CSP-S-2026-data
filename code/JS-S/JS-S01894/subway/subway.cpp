#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef pair<int,i64> PII;

const int N = 510, M = 5e5 + 10, D = 25;
const i64 inf = 1e18;
int c, n, m, d, q;
i64 w [ M ];
vector < PII > nds [ M ];
i64 dis [ N ][ N ];
int main ( ) {
    freopen ( "subway.in", "r", stdin );
    freopen ( "subway.out", "w", stdout );
    ios :: sync_with_stdio ( 0 );
    cin . tie ( 0 ), cout . tie ( 0 );
    cin >> c >> n >> m >> d >> q;
    for ( int i = 1; i <= m; ++i ) cin >> w [ i ];
    for ( int i = 1, k; i <= n; ++i ) {
        cin >> k; 
        for ( int j = 1; j <= k; ++j ) {
            int a; i64 t; cin >> a >> t;
            nds [ a ] . emplace_back ( i, t );
        }
    }
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n; ++j )
            dis [ i ][ j ] = inf;
        dis [ i ][ i ] = 0;
    }
    for ( int i = 1; i <= m; ++i ) {
        if ( nds [ i ] . size ( ) >= 2 ) {
            for ( int j = 0; j < nds [ i ] . size ( ) - 1; ++j ) {
                int bel1 = nds [ i ][ j ] . first; i64 val1 = nds [ i ][ j ] . second;
                for ( int k = j + 1; k < nds [ i ] . size ( ); ++k ) {
                    int bel2 = nds [ i ][ k ] . first; i64 val2 = nds [ i ][ k ] . second;
                    dis [ bel1 ][ bel2 ] = min ( dis [ bel1 ][ bel2 ], val1 + val2 );
                    dis [ bel2 ][ bel1 ] = min ( dis [ bel2 ][ bel1 ], val1 + val2 );
                }
            }
        }
    }
    for ( int k = 1; k <= n; ++k ) for ( int i = 1; i <= n; ++i ) for ( int j = 1; j <= n; ++j ) {
        dis [ i ][ j ] = min ( dis [ i ][ j ], dis [ i ][ k ] + dis [ k ][ j ] );
    }
    while ( q --> 0 ) {
        int x, y; cin >> x >> y;
        i64 res = inf;
        if ( x == y ) continue;
        for ( int i = 0; i < nds [ x ] . size ( ); ++i ) {
            int bel1 = nds [ x ][ i ] . first; i64 val1 = nds [ x ][ i ] . second;
            for ( int j = 0; j < nds [ y ] . size ( ); ++j ) {
                int bel2 = nds [ y ][ j ] . first; i64 val2 = nds [ y ][ j ] . second;
                res = min ( res, val1 + dis [ bel1 ][ bel2 ] + val2 );
            }
        } cout << res + w [ x ] + w [ y ] << '\n'; 
    }
    return 0;
}
/*

t1,2 is so ez,I will get in the wc.
++rp

g++ -std=c++14 -O2 -static -Wall -Wshadow subway.cpp -o b

*/