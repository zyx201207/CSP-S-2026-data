#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef pair<int,int> PII;
const int N = 2e6 + 10;
int c, t, n; i64 d;
i64 x [ N ];

bool flag [ N ]; // shi fou neng bei kua guo

vector < int > nds [ N ];
int dq [ N ], hh, tt;
i64 f [ N ], g [ N ];

void solve ( ) {
    cin >> n >> d; i64 ans = 0;
    for ( int i = 1; i <= n; ++i ) cin >> x [ i ];/*, nds [ i ] . clear ( );
    x [ n + 1 ] = (i64)3e18;
   for ( int i = 1; i <= n; ++i ) {
        int ptr = upper_bound ( x + 1, x + 1 + n, x [ i ] + d ) - x - 1;
        cerr << i << " : " << ptr << '\n';
        if ( ptr == i ) { flag [ i ] = 1; continue; }
        if ( x [ ptr ] + d < x [ ptr + 1 ] ) continue;
        if ( ptr - 2 <= i || x [ ptr - 2 ] + d >= x [ ptr + 1 ] ) continue;
        cerr << "pushed in " << ptr + 1 << '\n';
        nds [ ptr + 1 ] . emplace_back ( i );
    } dq [ hh = tt = 1 ] = 0; 
    for ( int i = 1; i <= n; ++i ) {
        cerr << i << " : ";
        for ( int ele : nds [ i ] ) {
            cerr << ele << ' '; dq [ ++tt ] = ele;
        } cerr << '\n';
        while ( tt - hh + 1 > 2 ) ++hh;
        if ( tt - hh == 1 ) ans += dq [ tt ] - dq [ hh ];
        if ( flag [ i ] ) dq [ hh = tt = 1 ] = i;
    } cout << ans << '\n';*/
    int cnt = 0;
    for ( int i = 1; i <= n; ++i ) {
        f [ i ] = 0, g [ i ] = 1, g [ i - 1 ] = 0;
        for ( int j = i + 1; j <= n; ++j ) {
            f [ j ] = 1e8;
            int k = lower_bound ( x + 1, x + 1 + n, x [ j ] - d ) - x; // zui xiao ke zhuan yi dian
            if ( k < i ) k = i;
            int w = upper_bound ( f + k, f + j, f [ k ] ) - f - 1; // zui da ke zhuan yi dian
            f [ j ] = f [ k ] + 1;
            g [ j ] = g [ j - 1 ] + g [ w ] - g [ k - 1 ];
    //        if ( i == 3 && j == 8 ) cerr << w << ' ' << k << ' ' << g [ w ] << ' ' << g [ k ] << '\n';
            if ( g [ j ] - g [ j - 1 ] == 2 ) ++cnt;
//            cerr << f [ j ] << ' ' << g [ j ] << ' ' << k << " " << w << " )) ";
         //   cerr << i << " -> " << j << ' ' << g [ j ] - g [ j - 1 ] << '\n';
        } //cerr << '\n';
    } cout << cnt << '\n';
    return;
}

vector < int > vec [ N ];

void solve2 ( ) {
    cin >> n >> d; i64 ans = 0;
    for ( int i = 1; i <= n; ++i ) cin >> x [ i ], vec [ i ] . clear ( ), flag [ i ] = 0;
    x [ n + 1 ] = (i64)3e18;
    // kaolv wang qian zou ke yi zou duo shao bu

    for ( int i = 1; i <= n; ++i ) {
        int ptr1 = upper_bound ( x + 1, x + 1 + n, x [ i ] + d ) - x - 1; // zui yuan neng dao de zui yuan chu
        int ptr2 = upper_bound ( x + 1, x + 1 + n, x [ ptr1 ] + d ) - x - 1;
        int ptr21 = ptr1 - 1, ptr22 = upper_bound ( x + 1, x + 1 + n, x [ ptr21 ] + d ) - x - 1;
        if ( ptr1 == i ) flag [ i ] = 1;
        if ( ptr21 > i ) {
            int ptr31 = ptr21 - 1, ptr32 = upper_bound ( x + 1, x + 1 + n, x [ ptr31 ] + d ) - x - 1;
            if ( ptr31 > i && ptr32 + 1 <= ptr22 ) {
//                cerr << i << "[ " << ptr32+1 <<" , " << ptr22 << " ]\n"; // [max(ptr1,ptr32)+1,ptr22]
                 vec [ ptr32 + 1 ] . emplace_back ( i );// vec [ ptr22 ] . emplace_back ( i );
            }
            else if ( ptr31 <= i && ptr1 + 1 <= ptr22 ) {
//                cerr << i << "??[ " << ptr1+1 <<" , " << ptr22 << " ]\n"; // [ptr1 + 1,ptr22]
                 vec [ ptr1 + 1 ] . emplace_back ( i );//, vec [ ptr22 ] . emplace_back ( i );
            }
        }
    } set < int > s; s . insert ( 0 );
    for ( int i = 1; i <= n; ++i ) {
        for ( auto ele : vec [ i ] ) s . insert ( ele );
        if ( s . size ( ) < 2 ) continue;
        ans += *s . rbegin ( ) - * ( --s . rbegin ( ) );
        if ( flag [ i ] ) s . clear ( ), s . insert ( i );
    }
    cout << ans << '\n';
    return;
}

int main ( ) {
    freopen ( "migrate.in", "r", stdin );
    freopen ( "migrate.out", "w", stdout );
    ios :: sync_with_stdio ( 0 );
    cin . tie ( 0 ), cout . tie ( 0 );
    for ( cin >> c >> t; t; --t ){
        if ( c <= 10 ) solve ( );
        else solve2 ( );
    }
    return 0;
}
/*

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
9

0 1
8 3
0 1 2 4 8 10 11 13
8

I have thought 9min,stop to do t4
kawaii t4,back to do t3

g++ -std=c++14 -O2 -static -Wall -Wshadow migrate.cpp -o c

now 15:21,I have got 100+100+0+0=200

fuck 17:22 I have got 100+100+0+0

if my score > 300,I can escape the mid-term exam

maybe one day, I'll get in the JS Province Team

zong you yi tian, just today!

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/