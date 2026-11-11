#include<bits/stdc++.h>

using namespace std;

#define int long long

int c, n, m, d, q, kou[40001], dis[40001][505];

bool vis[40001][505];

struct edge {
	
	int v, w, op;
	
};

pair<int, int> a[40001];

vector < edge > eEe[40001][505]; 

priority_queue < pair< int, pair< int, int > > > qp;

signed main ( ) {
	
	freopen ( "subway.in", "r", stdin );
	
	freopen ( "subway.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> c >> n >> m >> d >> q;
	
	for ( int i = 1; i <= m; i++ ) {
		
		cin >> kou[i];
		
	}
	
	int sumof;
	
	for ( int i = 1; i <= n; i++ ) {
		
		cin >> sumof;
		
		for ( int j = 1; j <= sumof; j++ ) {
			
			int v, w;
			
			cin >> v >> w;
			
			a[j] = {v, w};
			
		}
	
		for ( int j = 1; j <= sumof; j++ ) {
			
			for ( int k = j + 1; k <= sumof; k++ ) {
				
				eEe[ a[j].first ][i].push_back ( { a[k].first, 0, i } );
				
				eEe[ a[k].first ][i].push_back ( { a[j].first, 0, i } );
				
			}
			
			eEe[ a[j].first ][i].push_back ( { a[j].first + m, a[j].second, 0 } );
			
			eEe[ a[j].first + m ][0].push_back ( { a[j].first, a[j].second, i } );
		}
		
	}
	
	for ( int i = 1; i <= q; i++ ) {
		
		int s, e;
		
		cin >> s >> e;
		
		for ( int i = 0; i <= m + m; i++ ) {
			
			for ( int j = 0; j <= n; j++ ){
				dis[i][j] = LONG_LONG_MAX;
				vis[i][j] = 0;
			} 
			
		}
		
		dis[s + m][0] = 0;
		
		qp.push ( { 0, { s + m, 0 }} );
		
		while ( !qp.empty ( ) ) {
			
			int u, OP;
			
			u = qp.top().second.first;
			
			OP = qp.top().second.second;
			
			qp.pop ( );
			
			
			if ( vis[u][OP] ) continue;
			
			vis[u][OP] = 1;
			
			for ( auto V : eEe[u][OP] ) {
//				if ( u == 7 && V.v == 2 && V.op == 2 ) cout << dis[]
				if ( ( dis[V.v][V.op] > dis[u][OP] + V.w ) && ( ( OP == 0 ) || ( OP == V.op ) || ( V.op == 0) ) ) {
					dis[V.v][V.op] = dis[u][OP] + V.w;
					if ( vis[V.v][V.op] == 0 ) {
						qp.push ( { -dis[V.v][V.op], { V.v, V.op }} );
					}
					
				}
			
			}
			
		}
		cout << kou[s] + kou[e] + dis[e+m][0]<<'\n';
		
	}
	
	return 0;
	
}
