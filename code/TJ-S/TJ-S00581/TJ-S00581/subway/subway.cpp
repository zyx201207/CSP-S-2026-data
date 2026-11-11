#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int t[ ( int )5e5 + 5 ];
int dist[ ( int )5e5 + 5 ];
bool vis[ ( int )5e5 + 5 ];
struct node {
	int a, t;
};
vector<node> g[ ( int )5e5 + 5 ];
int c, n, m, d, q;

void dij( int x ) {
	memset( dist, 0x3f, sizeof dist );
	dist[ x ] = 0;
	vis[ x ] = true;
	priority_queue<int, vector<int>, greater<int>> q;
	q.push( x );
	while ( q.size() ) {
		int v{ q.top() };
		q.pop();
		if ( vis[ v ] ) continue;
		vis[ v ] = true;
		for ( node u: g[ v ] ) {
			if ( dist[ u.a ] > dist[ v ] + u.t ) {
				dist[ u.a ] = dist[ v ] + u.t;
				q.push( u.a );
			}
		}
	}
	memset( vis, false, sizeof vis );
}

int main() {
	freopen( "subway.in", "r", stdin );
	freopen( "subway.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cin >> c >> n >> m >> d >> q;
	for ( int i{ 1 }; i <= m; i ++ ) cin >> t[ i ];
	int k, a, w;
	for ( int i{ 1 }; i <= n; i ++ ) {
		cin >> k;
		while ( k -- ) {
			cin >> a >> w;
			g[ i ].push_back( { a, w } );
			g[ a ].push_back( { i, w } );
		}
	}
	int x, y;
	while ( q -- ) {
		cin >> x >> y;
		dij( x );
		cout << dist[ y ] << t[ x ] + t[ y ] << endl;
	}
	return 0;
	
} 
