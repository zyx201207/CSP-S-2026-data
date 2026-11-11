#include <bits/stdc++.h>
using namespace std ;
int n , m ;
int a[500005] ;
int ans[300005] = {} ;
int main()
{
    freopen("card.in","r",stdin ) ;
    freopen("card.out","w",stdout ) ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++ )
        cin >> a[i] ;

    for ( int i = 1 ; i <= n ; i ++ ){
        int b[500005] = {} ;
        for ( int j = 1 ; j <= n - i + 1 ; j ++ ){
            b[j] = a[ j + i - 1 ] ;
            bool flag = false ;
            for ( int u = 1 ; u < j ; u ++ ){
                if ( flag ){
                    b[u] = 0 ;
                    continue ;
                }
                if ( b[u] == b[j] ){
                    b[u] = 0 ;
                    flag = true ;
                }
            }
        }
        for ( int u = 1 ; u <= n ; u ++ ){
            if ( b[u] )
                ans[b[u]] ++ ;
        }
    }

    cout << ans[1] ;
    for ( int i = 2 ; i <= m ; i ++ )
        cout << " " << ans[i] ;
    return 0 ;
}
