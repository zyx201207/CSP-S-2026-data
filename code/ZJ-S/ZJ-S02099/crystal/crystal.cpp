#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m, a[500001], pre[500001];

bool check ( int x ) {
	
	// i - x -> i
	//     2 -> 3
	
	for ( int i = x; i <= n; i++ ) {
		
		if ( ( x * a[i] - pre[i] + pre[i - x] <= m ) && ( x * a[i] >= pre[i] - pre[i - x] ) ) {
			
			return true;
			
		}
		
	}
	
	return false;
	
} 

signed main ( ) {
	
	freopen ( "crystal.in", "r", stdin );
	
	freopen ( "crystal.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> n >> m;
	
	for ( int i = 1; i <= n; i++ ) {
		
		cin >> a[i];
		
	}
	
	sort ( a + 1, a + n + 1 );
	
	for ( int i = 1; i <= n; i++ ) {
		
		pre[i] = pre[i - 1] + a[i];
		
	}
	
	int l = 1, r = n + 1; // 二分能有多少个水晶一致 
	
	while ( l + 1 < r ) {
		
		int mid = ( l + r ) >> 1;
		
		if ( check ( mid ) ) {
			
			l = mid;
			
		}
		
		else {
			
			r = mid;
			
		}
		
	}
	
	cout << l;
	
	return 0;
	
}
