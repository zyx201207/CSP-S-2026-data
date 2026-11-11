#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int x, y;
long long ans;
int k[505];
int w[500005];
int zhan[505];
int a[505][500005];
int t[505][500005];

struct node {
	int d = 0, t[25];
	int b[505];
} f[500005];

void dfs( int z, int h, long long time ) {
	if ( z == y ) {
		ans = max(time, ans);
		return;
	}
	if ( z >= k[h] )
		return;
	if ( z <= 0 )
		return;
	dfs(z + 1, h, time);
	dfs(z - 1, h, time);
	for ( int i = 1 ; i <= f[z].d ; i++ ) {
		dfs(f[z].b[f[z].t[i]], f[z].t[i], time + t[h][f[z].b[h]] + t[f[z].t[i]][f[z].b[f[z].t[i]]]);
	}
}


int main() {
	cin >> n >> m >> d >> q;
	for ( int i = 1 ; i <= m ; i++ )
		cin >> w[i];
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> k[i];
		for ( int j = 1 ; j <= k[i] ; j++ ) {
			cin >> a[i][j] >> t[i][j];
			f[a[i][j]].d++;
			f[a[i][j]].t[f[a[i][j]].d] = i;
			f[a[i][j]].b[i] = j;
		}
	}
	while ( q-- ) {
		cin >> x >> y;
		ans = -1;
		for ( int i = 1 ; i <= f[x].d ; i++ )
			dfs(f[x].b[f[x].t[i]], f[x].t[i], w[x] + t[f[x].t[i]][f[x].b[f[x].t[i]]]);
	}
	cout << ans;

	return 0;
}
