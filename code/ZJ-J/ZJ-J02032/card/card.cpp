#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m, a[500001], outans[300001];

map < int, int > mp;

signed main ( ) {
	
	freopen ( "card.in", "r", stdin );
	
	freopen ( "card.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> n >> m;
	
	for ( int i = 1; i <= n; i++ ) {
		
		cin >> a[i];
		
		mp[a[i]] = i;
		
	}
	
	for ( int i = 1; i <= n; i++ ) { // game ground
		
		for ( int j = i; j <= n; j++ ) {
			
			outans[a[j]]++;
			
			if ( mp[a[j]] != j ) {
				
				j = mp[a[j]];
				
			}
			
		}
		
	}
	
	for ( int i = 1; i <= m; i++ ) {
		
		cout << outans[i] << ' ';
	}
	
	return 0;
	
}

