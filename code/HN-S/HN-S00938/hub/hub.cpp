#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int constexpr N = 1e6 + 5;
struct DSU {
	vector<int> fa;
	DSU( int n ) : fa( n + 1 ) {
		for ( int i = 1; i <= n; ++i )
		{ fa[ i ] = i; }
	}
	int find( int x ) {
		if ( x == fa[ x ] ) { return x; }
		return fa[ x ] = find( fa[ x ] );
	}
	void merge( int x, int y ) { fa[ find( x ) ] = find( y ); }
	bool same( int x, int y ) { return find( x ) == find( y ); }
	int count() {
		int ans = 0;
		for ( int i = 1; i < fa.size(); ++i ) {
			if ( i == fa[ i ] )
			{ ++ans; }
		}
		return ans;
	}
};

vector<int> tree[ N ];
int fa[ N ], depth[ N ] = { 0 };

void dfs( int cur, int p ) {
	for ( int child : tree[ cur ] ) {
		if ( child == p ) { continue; }
		fa[ child ] = cur;
		depth[ child ] = depth[ cur ] + 1;
	}
}

int constexpr Log = 20;
int up[ Log ][ N ];
void pre( int n ) {
	for ( int i = 1; i <= n; ++i ) {
		up[ 0 ][ i ] = fa[ i ];
		for ( int k = 1; k <= Log; ++k )
		{ up[ k ][ i ] = up[ k - 1 ][ up[ k - 1 ][ i ] ]; }
	}
}

int getlca( int u, int v ) {
	if ( depth[ u ] < depth[ v ] ) { swap( u, v ); }
	if ( depth[ u ] > depth[ v ] ) {
		int diff = depth[ u ] - depth[ v ];
		for ( int k = Log; k >= 0; --k ) {
			if ( diff & ( 1 << k ) )
			{ u = up[ k ][ u ]; }
		}
	}
	if ( u == v ) { return v; }
	for ( int k = Log; k >= 0; --k ) {
		int p = up[ k ][ u ], q = up[ k ][ v ];
		if ( p == q ) { continue; }
		u = p;
		v = q;
	}
	return fa[ u ];
}

int dist( int u, int v ) {
	int lca = getlca( u, v ), ans = 0;
	while ( u != lca ) {
		u = fa[ u ];
		++ans;
	}
	while ( v != lca ) {
		v = fa[ v ];
		++ans;
	}
	return ans;
}

bool is_valid_mask( int curmask, int k, int n, DSU &tree_dsu, vector<int> &chosen ) {
	for ( int i = 1; i <= n; ++i ) {
		if ( curmask & 1 ) {
			if ( chosen.size() > k ) { return false; }
			chosen.push_back( i );
		}
		curmask >>= 1;
	}
	if ( chosen.size() >= k ) { return false; }
	DSU dsu( n );
	for ( int u : chosen ) {
		for ( int v : chosen ) {
			if ( u != v && tree_dsu.same( u, v ) )
			{ dsu.merge( u, v ); }
		}
	}
	return dsu.count() <= 2;
}

int main() {
	freopen( "hub.in", "r", stdin );
	freopen( "hub.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int c, t; cin >> c >> t;
	while ( t-- ) {
		int n, k; cin >> n >> k;
		for ( int i = 1; i <= n; ++i )
		{ tree[ i ].clear(); }
		DSU tree_dsu( n );
		for ( int i = 1; i < n; ++i ) {
			int u, v; cin >> u >> v;
			tree[ u ].push_back( v );
			tree[ v ].push_back( u );
			tree_dsu.merge( u, v );
		}
		dfs( 1, 0 );
		pre( n );
		int ans = 2e9;
		for ( int mask = ( 1 << k ); mask < ( 1 << n ); ++mask ) {
			vector<int> chosen;
			if ( !is_valid_mask( mask, k, n, tree_dsu, chosen ) )
			{ continue; } 
			unordered_set<int> uch( chosen.begin(), chosen.end() );
			int cur = 0;
			for ( int i = 1; i <= n; ++i ) {
				int di = 2e9;
				if ( uch.count( i ) ) { di = 0; }
				else {
					for ( int j : chosen )
					{ di = min( di, dist( i, j ) ); }
				}
				cur = max( cur, di ); 
			}
			ans = min( ans, cur );
		}
		cout << ans << '\n';
	}

	return 0;
}

