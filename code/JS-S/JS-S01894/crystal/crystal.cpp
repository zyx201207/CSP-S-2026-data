#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

const int N = 5e5 + 10;
int n, ans = 0; 
i64 m, a [ N ], sum [ N ];

int main ( ) {
    freopen ( "crystal.in", "r", stdin );
    freopen ( "crystal.out", "w", stdout );
    ios :: sync_with_stdio ( 0 );
    cin . tie ( 0 ), cout . tie ( 0 );
    cin >> n >> m;
    for ( int i = 1; i <= n; ++i ) cin >> a [ i ];
    sort ( a + 1, a + 1 + n ); // if merges = a[i]
    for ( int i = 1; i <= n; ++i )
        sum [ i ] = a [ i ] + sum [ i - 1 ];
    for ( int i = 1; i <= n; ++i ) {
        int L = 1, R = i;
        while ( L <= R ) {
            int mid = ( L + R ) >> 1;
            if ( sum [ i ] - sum [ i - mid ] + m >= 1ll * mid * a [ i ] )
                L = mid + 1;
            else R = mid - 1;
        } ans = max ( ans, L - 1 );
    } cout << ans << '\n';
    return 0;
}
/*

xi xi,I will win!

g++ -std=c++14 -O2 -static -Wall -Wshadow crystal.cpp -o a

*/