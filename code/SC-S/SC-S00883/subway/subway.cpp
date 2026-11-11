#include<bits/stdc++.h>
#define int long long 

using namespace std ; 

const int N = 510 , M = 5e5 + 10 ; 
int n , mape[ N ][ N ] ; 
int m , belong[ M ][ 30 ] , belong_size[ M ] , cost[ M ] , belong_cost[ M ][ 30 ] ;  

int c , d , q ; 

signed main()
{
    freopen( "subway.in" , "r" , stdin ) ; 
    freopen( "subway.out" , "w" , stdout ) ;
    scanf( "%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &q ) ;
    for( int i = 1 ; i <= m ; i ++ ) scanf( "%lld" , &cost[ i ] ) ; 
    
    for( int i = 1 ; i <= n ; i ++ ) 
    {
        int k ; 
        scanf( "%lld" , &k ) ;   
        for( int j = 1 ; j <= k ; j ++ ) 
        {
            int o , p ; 
            scanf( "%lld%lld" , &o , &p ) ;
            belong[ o ][ ++ belong_size[ o ] ] = i ; 
            belong_cost[ o ][ belong_size[ o ] ] = p ;  
        } 
        for( int j = 1 ; j <= n ; j ++ ) mape[ i ][ j ] = LLONG_MAX ; 
        mape[ i ][ i ] = 0 ;
    } 
    for( int i = 1 ; i <= m ; i ++ ) 
    {
        for( int j = 1 ; j <= belong_size[ i ] ; j ++ ) 
        {
            for( int s = 1 ; s < j ; s ++ ) 
            {
                mape[ belong[ i ][ j ] ][ belong[ i ][ s ] ] = 
                    min( mape[ belong[ i ][ j ] ][ belong[ i ][ s ] ] , 
                         belong_cost[ i ][ j ] + belong_cost[ i ][ s ] ) ; 
                mape[ belong[ i ][ s ] ][ belong[ i ][ j ] ] =
                 mape[ belong[ i ][ j ] ][ belong[ i ][ s ] ] ;
            }
        }
    }    
    

    for( int i = 1 ; i <= n ; i ++ ) 
    {
        for( int j = 1 ; j < i ; j ++ ) 
        {
            if( j == i ) continue ; 
            for( int k = 1 ; k <= n ; k ++ ) 
            {
                if( k == j || k == i ) continue ; 
                if( mape[ i ][ k ] == LLONG_MAX ) continue ; 
                if( mape[ k ][ j ] == LLONG_MAX ) continue ; 
                mape[ i ][ j ] = min( mape[ i ][ k ] + mape[ k ][ j ] , mape[ i ][ j ] ) ; 
                mape[ j ][ i ] = mape[ i ][ j ] ;   
            }
        }
    }
    while( q -- ) 
    {
        int xr , yr ; 
        scanf( "%lld%lld" , &xr , & yr ) ; 
        int ans = LLONG_MAX ; 
        for( int i = 1 ; i <= belong_size[ xr ] ; i ++ )
        {
            for( int j = 1 ; j <= belong_size[ yr ] ; j ++ ) 
            {
                ans = min( ans , cost[ xr ] + cost[ yr ] + belong_cost[ xr ][ i ] + belong_cost[ yr ][ j ] + mape[ belong[ xr ][ i ] ][ belong[ yr ][ j ] ] ) ; 
            }
        }
        printf( "%lld\n" , ans ) ;  
    }
    return 0 ; 
}