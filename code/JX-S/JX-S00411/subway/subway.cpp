#include<bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define lowbit(x) (x&(-x))
#define pii pair<int,int>
const int N = 1e3 + 91 ;
const int M = 26 ;
const int mod = 998244353 ;
const int inf = 1e18 ;
int T , Q , c ;
int n , m , d ;
int w[N] ;
int dp[N][N] ;
int p[N] ;
int a[N] , t[N] , tot ;
signed main ( ){
    freopen ( "subway.in" , "r" , stdin ) ;
    freopen ( "subway.out" , "w" , stdout ) ;
    IOS ;
    cin >> c >> n >> m >> d >> Q ;
    for ( int i = 1 ; i <= m ; ++i ){
        cin >> w[i] ;
    }
    for ( int i = 0 ; i < N ; ++i ){
        for ( int j = 0 ; j < N ; ++j ){
            dp[i][j] = inf ;
        }
    }
    for ( int i = 1 ; i <= n ; ++i ){
        cin >> p[i] ;
        for ( int j = 1 ; j <= p[i] ; ++j ){
            ++tot ;
            cin >> a[tot] >> t[tot] ;
        }
        if ( p[i] == 2 ){
            dp[a[tot]][a[tot-1]] = dp[a[tot-1]][a[tot]] = t[tot] + t[tot-1] ;
        }
    }
    for ( int k = 1 ; k < N ; ++k ){
        for ( int i = 1 ; i <= m ; ++i ){
            for ( int j = 1 ; j <= m ; ++j ){
                if ( dp[i][j] > dp[i][k] + dp[k][j] ){
                    dp[i][j] = dp[i][k] + dp[k][j] ;
                }
            }
        }
    }
    while ( Q-- ){
        int x , y ;
        cin >> x >> y ;
        cout << dp[x][y] + w[x] + w[y] << "\n" ;
    }
    return 0 ;
}