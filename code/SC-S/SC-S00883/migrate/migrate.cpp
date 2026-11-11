#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int N = 2e6 + 199 ; 
int t , c ;
int n ;  
int distant[ N ] ; 
int mape[ N ] , cont[ N ] , ans = 0 ; 

void dfs( int now_data , int step , int k ) 
{
    for( int i = 1 ; i <= n ; i ++ ) 
    {
        if( now_data == i || mape[ i ] < step + 1 ) continue ; 
        
        if( abs( distant[ i ] - distant[ now_data ] ) <= k ) 
        {
            if( mape[ i ] == step + 1 && cont[ i ] == 1 )  
            {
                cont[ i ] ++ , ans ++ ; 
                dfs( i , step + 1 , k ) ; 
            }
            else if( mape[ i ] == step + 1 && cont[ i ] != 1 )
            {
                ans -- ; 
                dfs( i , step + 1 , k) ; 
            }
                
            else if( mape[ i ] > step + 1 ) 
            {
                mape[ i ] = step + 1 ;
                cont[ i ] = 1 ; 
                dfs( i , step + 1 ,k) ; 
            }
        }
    }
    return ; 
}

signed main()
{
    freopen( "migrate.in" , "r" , stdin ) ; 
    freopen( "migrate.out" , "w" , stdout ) ; 
    scanf( "%lld%lld" , &c , &t ) ; 
    while( t -- ) 
    {
        int d ; 
        scanf( "%lld%lld" ,&n , &d ) ; 
        if( c == 12 || c == 11 )
        {
            for( int i = 1 ; i <= n ; i ++ ) scanf( "%lld" , &distant[ i ] ) ; 
            if( distant[ 2 ] - distant[ 1 ] >= d )
            {
                printf( "0\n" ) ; 
                continue ; 
            }
            else 
            {
                int u = d / ( distant[ 2 ] - distant[ 1 ] ) ; 
                if( u == 2 ) 
                {
                    printf( "%lld\n" , n - 3 ) ; 
                    continue ; 
                }
                if( n - u * 2 + 1 < 0 ) 
                {
                    printf( "0\n" ) ; 
                    continue ; 
                }
                printf( "%lld\n" , n - u * 2 + 1 ) ; 
                continue ; 
            }
        }
        else
        {
            int d , ans1 = 0 ; 
            scanf( "%lld%lld" ,&n , &d ) ; 
            for( int i = 1 ; i <= n ; i ++ ) scanf( "%lld" , &distant[ i ] ) ; 
            for( int i = 1 ; i <= n ; i ++ ) 
            {
                for( int j = 1 ; j <= n ; j ++ ) mape[ j ] = INT_MAX , cont[ j ] = 0 ; 
                ans = 0 ; 
                mape[ i ] = 0 ;
                dfs( i , 0 , d ) ; 
                ans1 += ans ; 
            }
            printf( "%lld\n" , ans1 ) ;  
        }
    }
    return 0 ; 
}