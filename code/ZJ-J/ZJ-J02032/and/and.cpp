#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m, a[200001];

map < int, int > mp;

int chek ( int x ) {
	
	return x & ( x - 1 );

}

int lowbit ( int x ) {
	
	return x & ( -x );
}

int ansofone = 0;

void dfs ( int i, string s, int sum ) {
	
	if ( sum == m ) {
		
		bool f = 1;
		
		int now = 0;
		
		for ( int i = 0; i < s.size ( ); i++ ) {
			
			if ( s[i] == '1' && f ) {
				
				now = a[i];
				
				f = 0;
				
			}
			
			else if ( s[i] == '1' ) {
				
				now & a[i];
				
			}
			
		}
		
		ansofone = max ( ansofone, now );
		
		return;
		
	}
	
	if ( n - i < m - sum - 1 ) return;
	
	dfs ( i + 1, s + '0', sum );
	
	dfs ( i + 1, s + '1', sum + 1 );
}

signed main ( ) {
	
	freopen ( "and.in", "r", stdin );
	
	freopen ( "and.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> n >> m;
	
	int maxx = -1, SUMOFZ = 0;
	
	for ( int i = 1; i <= n; i++ ) {
		
		cin >> a[i];
		
		maxx = max ( maxx, a[i] );
		
		if ( a[i] == 0 ) {
			
			SUMOFZ++;
			
		}
		
	}
	
	if ( SUMOFZ >= n - m + 1 ) {
		
		cout << 0;
		
		return 0;
		
	}
	
	if ( m == n ) {
		
		int ans = a[1];
		
		for ( int i = 1; i <= n; i++ ) {
			
			ans = ans & a[i];
			
		}
		
		cout << ans;
		
		return 0;
		
	}
	
	if ( m == 1 || maxx == 0 ) {
		
		cout << maxx;
		
		return 0;
		
	}
	
	if ( m == 2 ) {
		
		int ans = 0;
		
		for ( int i = 1; i <= n; i++ ) {
			
			for ( int j = i + 1; j <= n; j++ ) {
				
				ans = max ( ans, a[i] & a[j] );
				
			}
			
		}
		
		cout << ans;
		
		return 0;
		
	}
	
	if ( chek ( maxx + 1 ) == 0 ) {
		
		sort ( a + 1, a + n + 1 );
		
		int ans = a[n];
		
		m--;
		
		for ( int i = n - 1; i >= 1; i-- ) {
			
			if ( m == 0 ) break;
			
			ans = ans & a[i];
			
			m--;
			
		}
		
		cout << ans;
		
		return 0;
		
	}
	
	if ( n <= 20 ) {
		
		dfs ( 0, "", 0 );
		
		cout << ansofone;
		
		return 0; 
		
	}
	
	if ( maxx < 4 ) {
		
		int num0 = 0, num1 = 0, num2 = 0, num3 = 0;
		
		for ( int i = 1; i <= n; i++ ) {
			
			if ( a[i] == 0 ) num0++;
			
			if ( a[i] == 1 ) num1++;
			
			if ( a[i] == 2 ) num2++;
			
			if ( a[i] == 3 ) num3++;
			
		}
		
		if ( num3 >= m ) {
			
			cout << 3;
			
			return 0;
			
		}
		
		if ( num3 + num2 >= m ) {
			
			cout << 2;
			
			return 0;
			
		}
		
		if ( num3 + num2 + num1 >= m ) {
			
			cout << 1;
			
			return 0;
			
		}
		
		cout << 0;
		
		return 0;
		
	}
	
	int maxwei = 0;
	
	for ( int i = 0; ( 1 << i ) <= maxx; i++ ) {
		
		mp[i] = 0;
		
		maxwei = i;
		
	}
	
	for ( int i = 1; i <= n; i++ ) {
		
		int x = a[i];
		
		int wei = 0;
		
		while ( x ) {
			
			if ( x & 1 ) mp[wei]++;
			
			x = x >> 1;
			
			wei++;
		
		}
		
	}
	
	int ans = 0;
	
	int M = m;
	
	for ( int i = maxwei; i >= 0; i-- ) {
		
		if ( M == 0 ) break;
		
		if ( mp[i] >= m ) {
			
			ans = ans | ( 1 << i );
			
			M--;
			
		}
	
	}
	
	cout << ans;
	
	return 0;
	
}

