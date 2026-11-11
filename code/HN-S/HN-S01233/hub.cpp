# include <bits/stdc++.h>
# define pb push_back
using namespace std ; 
constexpr int N = 1e6 + 5 ; 
int cid , T , n , k , fa[20][N] , dep[N] , s[N] ; 
vector < int > g[N] ; 
bool vis[N] ; 
pair < int , int > edge[N] ; 
int find ( int x ) { return s[x] == x ? x : s[x] = find ( s[x] ) ; }
void merge ( int x , int y ){
	int fx = find ( x ) , fy = find ( y ) ; 
	if ( fx == fy ) return ; 
	s[fy] = fx ; return ; 
}
void dfs ( int u , int fa ) {
	:: fa[0][u] = fa , dep[u] = dep[fa] + 1 ; 
	for ( int j = 1 ; j < 20 ; ++ j ) :: fa[j][u] = :: fa[j - 1][:: fa[j - 1][u]] ;
	for ( auto &v : g[u] ) if ( v != fa ) dfs ( v , u ) ; 
} 
int LCA ( int u , int v ) {
	if ( dep[u] < dep[v] ) swap ( u , v ) ; 
	for ( int j = 19 ; ~ j ; -- j ) if ( ( dep[u] - dep[v] ) >> j & 1 ) u = fa[j][u] ;
	if ( u == v ) return u ; 
	for ( int j = 19 ; ~ j ; -- j ) if ( fa[j][u] != fa[j][v] ) u = fa[j][u] , v = fa[j][v] ;
	return fa[0][u] ;  
}
int getdis ( int u , int v ) { return dep[u] + dep[v] - 2ll * dep[LCA (u , v)] ; }
void solve () {
	cin >> n >> k ; 
	for ( int i = 1 ; i <= n ; ++ i ) g[i].clear () ;
	for ( int i = 1 ; i < n ; ++ i ) { 
		int u , v ; cin >> u >> v ; 
		g[u].pb ( v ) , g[v].pb ( u ) ; 
		edge[i] = { u , v } ; 
	}
	dfs ( 1 , 0 ) ; 
	if ( n <= 10 ) {
		int res = 0 , rres = n ; 
		for ( int S = 0 ; S < (1ll << n) ; ++ S ) {
			res = 0 ; 
			if ( __builtin_popcount ( S ) != k ) continue ;
			iota ( s + 1 , s + n + 1 , 1 ) ;  int cnt = 0 ; vector < int > vec ; 
			for ( int i = 0 ; i < n ; ++ i ) if ( S >> i & 1 ) vis[i + 1] = 1 , vec.pb ( i + 1 ) ; 
			for ( int i = 1 ; i < n ; ++ i ) if ( vis[edge[i].first] && vis[edge[i].second] ) merge ( edge[i].first , edge[i].second ) ; 
			for ( int i = 1 ; i <= n ; ++ i ) if ( vis[i] ) cnt += ( s[i] == i ) , vis[i] = 0 ; 
			if ( cnt > 2 ) continue ; int res = 0 ; 
			for ( int i = 1 ; i <= n ; ++ i ) {
				int mn = n ; 
				for ( auto & v : vec ) mn = min ( mn , getdis ( v , i ) ) ;
				res = max ( res , mn ) ;  
			}
			rres = min ( rres , res ) ; 
		}	
		return cout << rres << '\n' , void () ; 
	}
	else if ( cid >= 13 && cid <= 14 ) {
		// return cout << 
	}
}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) ; 
	freopen ( "hub.in" , "r" , stdin ) , freopen ( "hub.out" , "w" , stdout ) ; 
	cin >> cid >> T ; while ( T -- ) solve () ; return 0 ;  
}