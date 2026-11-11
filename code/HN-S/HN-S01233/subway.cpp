# include <bits/stdc++.h>
# define int long long
# define pb push_back
using namespace std ;
constexpr int INF = 1e18 , M = 5e5 + 5 , N = 505 ; 
int cid , n , m , d , q , k[N] ;
int w[M] , dis[N][N] ; 
vector < int > t[N] ;  
vector < pair < int , int > > sta[M] ;
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) ; 
	freopen ( "subway.in" , "r" , stdin ) , freopen ( "subway.out" , "w" , stdout ) ; 
	cin >> cid >> n >> m >> d >> q ; 
	for ( int i = 1 ; i <= m ; ++ i ) cin >> w[i] ; 
	for ( int i = 1 ; i <= n ; ++ i ) {
		cin >> k[i] , t[i].pb ( 0 ) ;  
		for ( int j = 1 ; j <= k[i] ; ++ j ) {
			int x , y ; cin >> x >> y ; 
			t[i].pb ( y ) , sta[x].pb ( { i , j } ) ;
		}
	}
	for ( int i = 0 ; i <= n ; ++ i ) for ( int j = 0 ; j <= n ; ++ j ) dis[i][j] = INF ; 
	for ( int i = 1 ; i <= n ; ++ i ) dis[i][i] = 0 ; 
	for ( int bb = 1 ; bb <= m ; ++ bb ) {
		for ( auto & v : sta[bb] ) {
			for ( auto & vv : sta[bb] ) {
				dis[v.first][vv.first] = min ( dis[v.first][vv.first] , t[v.first][v.second] + t[vv.first][vv.second] ) ; 
			}
		}
	}
	for ( int k = 1 ; k <= n ; ++ k ) {
		for ( int i = 1 ; i <= n ; ++ i ) {
			for ( int j = 1 ; j <= n ; ++ j ) {
				dis[i][j] = min ( dis[i][j] , dis[i][k] + dis[k][j] ) ; 
			}
		}
	}
	while ( q -- ) {
		int x , y , res = INF ; cin >> x >> y ; 
		for ( auto & a : sta[x] ) for ( auto & b : sta[y] ) 
			res = min ( res , dis[a.first][b.first] + w[x] + w[y] + t[a.first][a.second] + t[b.first][b.second] ) ;
		cout << res << '\n' ;  
	}
	return 0 ; 
}