#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
ll d, a[5007], dp[5007][5007], dist[5007][5007]; 
int main () {
	freopen ( "migrate.in", "r", stdin );
	freopen ( "migrate.out", "w", stdout );
	int c, t;
	scanf ( "%d %d", &c, &t );
	while ( t-- ) {
		scanf ( "%d %lld", &n, &d );
		for ( int i = 1; i <= n; i++ ) scanf ( "%lld", &a[i] );
		for ( int i = 1; i <= n; i++ ) {
			for ( int j = 1; j <= n; j++ ) {
				fill ( dist[i] + 1, dist[i] + n + 1, inf );
				fill ( dp[i] + 1, dp[i] + n + 1, 0 );
			}
		}
		for ( int i = 1; i <= n; i++ ) {
			for ( int l = i - 1; l >= 1 && a[i] - a[l] <= d; l-- ) {
				dp[l][i] = 1;
				dist[l][i] = 1;
			}
			for ( int r = i + 1; r <= n && a[r] - a[i] <= d; r++ ) {
				dp[i][r] = 1;
				dist[i][r] = 1;
			}
		}
		int ans = 0;
		for ( int l = 3; l <= n; l++ ) {
			for ( int b = 1; b <= n - l + 1; b++ ) {
				int e = b + l - 1;
				if ( dist[b][e] == 1 ) continue;
				for ( int i = b + 1; i < e; i++ ) {
					if ( dist[b][i] + dist[i][e] < dist[b][e] ) {
						dist[b][e] = dist[b][i] + dist[i][e];
						dp[b][e] = dp[b][i] * dp[i][e];
					} else if ( dist[b][i] + dist[i][e] == dist[b][e] ) {
						dp[b][e] += dp[b][i] * dp[i][e];
					}
				}
				if ( dp[b][e] == 2 ) ans++;
			}
		}
		printf ( "%d\n", ans );
	}
	return 0;
} 
