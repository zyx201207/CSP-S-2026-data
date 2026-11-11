#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10;
int c, t, n, k;
int dis [ N ];
vector < int > g [ N ];

void sol1 ( ) { 
    int ans = 1e9;
    for ( int S = 0; S < 1 << n; ++S ) {
        if ( __builtin_popcount( S ) != k ) continue;
        queue < int > q;
        for ( int i = 1; i <= n; ++i ) dis [ i ] = 1e9;
        for ( int i = 0; i < n; ++i ) {
            if ( ( S >> i ) & 1 ) q . emplace ( i + 1 ), dis [ i + 1 ] = 0;
        } int cnt = 0;
        while ( !q . empty ( ) ) {
            int u = q . front ( ); q . pop ( );
            for ( auto v : g [ u ] ) {
                if ( dis [ v ] == 0 && dis [ u ] == 0 ) ++cnt;
                if ( dis [ v ] != 1e9 ) continue;
                dis [ v ] = dis [ u ] + 1;
                q . emplace ( v );

            }
        } int res = 0; 
        if ( cnt < k - 2 ) continue;
        for ( int i = 1; i <= n; ++i ) res = max ( dis [ i ], res );
        ans = min ( ans, res );
    } cout << ans << '\n';
}
int main ( ) {
    freopen ( "hub.in", "r", stdin );
    freopen ( "hub.out", "w", stdout );
    ios :: sync_with_stdio ( 0 );
    cin . tie ( 0 ), cout . tie ( 0 );
    for ( cin >> c >> t; t; --t ) {
        cin >> n >> k;
        for ( int i = 1; i <= n; ++i ) g [ i ] . clear ( );
        for ( int i = 1, u, v; i < n; ++i ) {
            cin >> u >> v;
            g [ u ] . emplace_back ( v );
            g [ v ] . emplace_back ( u );
        }
        if ( c <= 3 ) sol1 ( );
        else if ( 13 <= c && c <= 14 ) { cout << ( n - k + 3 ) / 4 << '\n'; }
    }
    return 0;
}
/*
g++ -std=c++14 -O2 -static -Wall -Wshadow hub.cpp -o d

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

fuck i can't get into wc
*/