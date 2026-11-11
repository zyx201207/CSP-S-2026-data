#include<bits/stdc++.h>

#define int long long 

using namespace std ; 

const int N = 5e5 + 10 ; 

int input[ N ] ;

int n , m ; 

signed main()
{
    freopen( "crystal.in" , "r" , stdin ) ; 
    freopen( "crystal.out" , "w" , stdout ) ; 

    scanf( "%lld%lld" , &n , &m ) ; 
    for( int i = 1 ; i <= n ; i ++ ) 
        scanf("%lld" , &input[ i ] ) ; 
    sort( input + 1 , input + 1 + n ) ; 
    int l = 1 , r = 1 , cost = 0 ; 
    int ans = 0 ;
    while( input[ r + 1 ] == input[ r ] && r <= n ) r ++ ;
    if( r == n + 1 ) 
    {
        printf( "%lld" , n ) ;
        return 0 ;
    }
    ans = max( ans , r - l + 1 ) ; 
    for( ; r <= n ; ) 
    {
        r ++ ;
        if( r > n ) break ; 
        int bridge = input[ r ] - input[ r - 1 ] , wind = r - l ; 
        while( input[ r + 1 ] == input[ r ] && r <= n )
        {
            r ++ ; 
        } 
        cost += wind * bridge ; 
        while( cost > m && l < r ) 
        {
            cost -= input[ r ] - input[ l ] ;
            l ++ ; 
        } 
        ans = max( ans , r - l + 1 ) ; 
    }
    printf( "%lld" , ans ) ; 

    return 0; 
}