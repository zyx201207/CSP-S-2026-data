#include <bits/stdc++.h>
using namespace std ;
int n , a[200005] ;
char c[200005] ;
long long dift , ans ;
int main()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ )
        cin >> a[i] >> c[i] ;
    int p = 1 , q = n ;
    while ( p <= q )
    {
        if ( c[p] == c[q]) dift = 0 ;
        if ( c[p] != a[q]) dift = min ( a[p] , a[q] ) ;
        ans += dift ;
        if ( a[p] > a[q] )
        {
            q -- ;
            a[p] -= a[q] ;
        }
        else if ( a[p] < a[q]){
            p ++ ;
            a[q] -= a[p] ;
        }
        else {
            a[p] = 0 ;
            p ++ ;
            a[q] = 0 ;
            q -- ;
        }
    }
    cout << ans ;
    return 0 ;
}
