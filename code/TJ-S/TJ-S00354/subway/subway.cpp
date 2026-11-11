#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[5007], a[5007], t[5007];
ll g[5007][5007], dist[5007][5007];
int main () {
	freopen ( "subway.in", "r", stdin );
	freopen ( "subway.out", "w", stdout );
	scanf ( "%d %d %d %d %d", &c, &n, &m, &d, &q );
	for ( int i = 1; i <= m; i++ ) scanf ( "%d", &w[i] );
	for ( int i = 1; i <= m; i++ ) {
		fill ( g[i] + 1, g[i] + m + 1, inf );
		fill ( dist[i] + 1, dist[i] + m + 1, inf );
		g[i][i] = dist[i][i] = 0;
	}
	for ( int i = 1; i <= n; i++ ) {
		int k;
		scanf ( "%d", &k );
		for ( int j = 1; j <= k; j++ )
		scanf ( "%d %d", &a[j], &t[j] );
		for ( int j = 1; j <= k; j++ ) {
			for ( int l = j + 1; l <= k; l++ ) {
				g[a[j]][a[l]] = g[a[l]][a[j]] = min ( g[a[j]][a[l]], 1ll * t[j] + t[l] );
				dist[a[j]][a[l]] = dist[a[l]][a[j]] = g[a[j]][a[l]];
			}
		}
	}
	for ( int k = 1; k <= m; k++ ) {
		for ( int i = 1; i <= m; i++ ) {
			for ( int j = 1; j <= m; j++ ) {
				dist[i][j] = min ( dist[i][j], dist[i][k] + dist[k][j] );
			}
		}
	}
	for ( int i = 1; i <= q; i++ ) {
		int b, e;
		scanf ( "%d %d", &b, &e );
		printf ( "%lld\n", dist[b][e] + w[b] + w[e] );
	}
	return 0;
} 
