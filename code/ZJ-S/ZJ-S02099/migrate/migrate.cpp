#include<bits/stdc++.h>

using namespace std;

#define int long long

int c, t, a[2000001];

signed main ( ) {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdin);
	cin >> c >> t;
	
	while ( t-- ) {
		
		int n, d;
		
		cin >> n >> d;
		
		int ans = 0;
		
		for ( int i = 1; i <= n; i++ ) {
			
			cin >> a[i];
			
		}
		int d;
		for ( int i = 3; i <= n; i++ ) {
			
			int now = i - 1;
			
			while ( a[i] - a[now] < d && a[i] - a[now - 1] < d ) {
				
				now--;
				
			}
			d += i - now; 
			
			
		}
		cout << 1 << (d - 1);
	} 
	
	return 0;
	
}
