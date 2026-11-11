#include<bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define lowbit(x) (x&(-x))
#define pii pair<int,int>
const int N = 1e6 + 91 ;
const int M = 26 ;
const int mod = 998244353 ;
const int inf = 1e18 ;
int T , Q ;
int n , m ;
int a[N] ;
int b ;
int sum[N] ;
bool check ( int l , int r ){
    int cnt = 0 ;
    cnt = ( r - l + 1 ) * b ;
    cnt -= ( sum[r] - sum[l-1] ) ;
    return (cnt <= m) ;
}
signed main ( ){
    freopen ( "crystal.in" , "r" , stdin ) ;
    freopen ( "crystal.out" , "w" , stdout ) ;
    IOS ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++i ){
        cin >> a[i] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++i ){
        sum[i] = sum[i-1] + a[i] ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++i ){
        b = a[i] ;
        int k = i , p = 1 ;
        while ( p ){
            if ( k - p < 1 || check ( k - p , i ) == false ){
                p /= 2 ;
            }else if ( check ( k - p , i ) == true ){
                k -= p ;
                p *= 2 ;
            }
        }
        ans = max ( ans , i - k + 1 ) ;
    }
    cout << ans << "\n" ;
    return 0 ;
}