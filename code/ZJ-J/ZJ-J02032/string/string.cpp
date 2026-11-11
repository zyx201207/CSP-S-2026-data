#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, a[200001];

char c[200001];

int len = 0;

signed main ( ) {
	
	freopen ( "string.in", "r", stdin );
	
	freopen ( "string.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> n;
	
	for ( int i = 1; i <= n; i++ ) {
		
		int nn;
		
		char nc;
		
		cin >> nn >> nc;
		
		if ( nc == c[ len ] ) {
			
			a[ len ] += nn;
			
		}
		
		else {
			
			len++;
			
			c[ len ] = nc;
			
			a[ len ] = nn;
			
		}
		
	}
	
	
	int i = 1, j = len;
	
	if ( len == 1 ) {
		
		cout << 0;
		
		return 0;
		
	}
	
	int ans = 0;
	
	while ( i < j ) {
		
		if ( a[i] >= a[j] ) {
			
			if ( c[i] == c[j] ) {
				
				a[i] -= a[j];
				
				j--;
				
				continue;
				
			}
			
			else {
				
				ans += a[j];
				
				a[i] -= a[j];
				
				j--;
				
				continue;
				
			}
			
		}
		
		else {
			
			if ( c[i] == c[j] ) {
				
				a[j] -= a[i];
				
				i++;
				
				continue;
				
			}
			
			else {
				
				ans += a[i];
				
				a[j] -= a[i];
				
				i++;
				
				continue;
				
			}
			
		}
		
	}
	
	cout << ans;
	
	return 0;
	
}

