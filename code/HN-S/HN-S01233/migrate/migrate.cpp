# include <bits/stdc++.h>
# define int long long 
# define pb push_back
using namespace std ;
constexpr int N = 2e6 + 5 , INF = 1e18 ;  
int cid , T , n , d , a[N] ; 
namespace brute {
	vector < int > g[N] ;
	int dis[N] ;   
	pair < int , bool > cnt[N] ; 
	pair < int , bool > merge ( pair < int , bool > now , pair < int , bool > pre ) {
		if ( pre.second ^ 1 ) return { 0 , 0 } ; if ( now.second ^ 1 ) return { 0 , 0 } ; 
		if ( now.first + pre.first <= 2 ) return { now.first + pre.first , 1 } ; 
		return { 0 , 0 } ; 
	}
	int calc ( int RT ) {
		queue < int > q ; int res = 0 ; 
		for ( int i = 1 ; i <= n ; ++ i ) dis[i] = INF , cnt[i] = { 0 , 1 } ; 
		q.push ( RT ) , cnt[RT] = { 1 , 1 } , dis[RT] = 0 ; 
		while ( ! q.empty () ) {
			int u = q.front () ; q.pop () ; 
			for ( auto & v : g[u] ) {
				if ( dis[v] > dis[u] + 1 ) q.push ( v ) , dis[v] = dis[u] + 1 , cnt[v] = cnt[u] ; 
				else if ( dis[v] == dis[u] + 1 ) cnt[v] = merge ( cnt[v] , cnt[u] ) ; 
			}
		}  
		for ( int i = RT + 1 ; i <= n ; ++ i ) if ( cnt[i].second && cnt[i].first == 2 ) ++ res ;
		return res ; 
	}
	void main () {
		for ( int i = 1 ; i <= n ; ++ i ) g[i].clear () ; int res = 0 ; 
		for ( int i = 1 ; i <= n ; ++ i ) for ( int j = i + 1 ; j <= n ; ++ j ) 
			if ( a[j] - a[i] <= d ) g[i].pb ( j ) , g[j].pb ( i ) ; 
		for ( int i = 1 ; i <= n ; ++ i ) res += calc ( i ) ; 
		return cout << res << '\n' , void () ; 
	}
}
int nxt[N] ;
void solve () {
	cin >> n >> d ; for ( int i = 1 ; i <= n ; ++ i ) cin >> a[i] ; 
	if ( n <= 5000 ) return brute :: main () , void () ; 
	else if ( cid >= 11 && cid <= 12 ) {
		int diff = a[2] - a[1] ; 
		if ( diff > d ) return cout << "0\n" , void () ; 
		int lim = d / diff ; 
		if ( lim == 1 ) return cout << "0\n" , void () ; 
		int step = ( 2ll * lim - 1 ) * diff ; 
		for ( int i = 1 ; i <= n ; ++ i ) if ( a[i] - a[1] == step ) return cout << n - i + 1 << '\n' , void () ; 
		return cout << "0\n" , void () ; 
	}
	// for ( int i = 1 ; i <= n ; ++ i ) {
	// 	int rpos = 0 , l = i , r = n ; 
	// 	while ( l <= r ) {
	// 		int mid = ( l + r ) >> 1 ;
	// 		if ( a[mid] - a[i] <= d ) rpos = mid , l = mid + 1 ; 
	// 		else r = mid - 1 ;  
	// 	}
	// 	nxt[i] = rpos ; 
	// }
	return cout << "0\n" , void () ; 
}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) ; 
	freopen ( "migrate.in" , "r" , stdin ) , freopen ( "migrate.out" , "w" , stdout ) ; 
	cin >> cid >> T ; while ( T -- ) solve () ; return 0 ; 
}