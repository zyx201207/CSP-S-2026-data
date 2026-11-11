#include<bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define lowbit(x) (x&(-x))
#define pii pair<int,int>
const int N = 4e6 + 91 ;
const int M = 26 ;
const int mod = 998244353 ;
const int inf = 1e18 ;
int T , Q , c ;
int n , m , d ;
int a[N] ;
int R[N] ;
int cnt[N] ;
int dp[N] , f[N] ;
signed main ( ){
    freopen ( "migrate.in" , "r" , stdin ) ;
    freopen ( "migrate.out" , "w" , stdout ) ;
    IOS ;
    cin >> c >> T ;
    while ( T-- ){
        int ans = 0 ;
        cin >> n >> d ;
        for ( int i = 1 ;i <= n ; ++i ){
            cin >> a[i] ;
        }
        for ( int i = 1 ; i <= n ; ++i ){
            int k = i , p= 1 ;
            while ( p ){
                if ( k + p > n || a[k+p] - a[i] > d ){
                    p /= 2 ;
                }else if ( a[k+p] - a[i] <= d ){
                    k += p ;
                    p *= 2 ;
                }
            }
            R[i] = k ;
            // cout << R[i] << "--\n" ;
        }
        for ( int j = 1 ; j <= n ; ++j ){
            f[j] = 1 ;
            for ( int i = j - 1 ; i >= 1 ; --i ){
                int minn = inf ;
                for ( int h = i + 1 ; h <= R[i] && h <= j ; ++h ){
                    if ( dp[h] <= minn ) minn = dp[h] ;
                }
                int sum = 0 ;
                for ( int h = i + 1 ; h <= R[i] && h <= j ; ++h ){
                    if ( dp[h] == minn ) sum += f[h] ;
                }
                dp[i] = minn + 1 ;
                f[i] = sum ;
                if ( f[i] == 2 ){
                    ++ans ;
                }
            }
            for ( int i = 1 ; i <= j ; ++i ){
                dp[i] = f[i] = 0 ;
            }
        }
        cout << ans << "\n" ;
    }
    return 0 ;
}