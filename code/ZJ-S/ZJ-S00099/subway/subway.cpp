#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 505;
const int maxm = 500005;
const int maxk = 500005;
int c, n, m, d, q, w[maxm], k, a[maxk], t[maxk], x, y;
int f[maxm][maxn], l, r, u, v, vis[maxm];
pair<int, int> que[maxm*10];
vector< pair<int, int> > e[maxm];
int bfs(int x, int y) {
	memset( f, 0, sizeof(f) );
	l = 1, r = 1;
	for(int i = 0; i < e[x].size(); ++i) {
		f[x][ e[x][i].first ] = w[x] + e[x][i].second;
		que[r++] = {e[x][i].first, x};
	}
	vis[x] = 1;
	while(l < r) {
		u = que[--r].first;
		v = que[r].second;
		vis[v] = 1;
		for(int w = 0; w < e[x].size(); ++w) {
			if(!vis[ e[x][w].second ]) {
				if( e[x][w].first == u ) {
					f[ e[x][w].second ][ e[x][w].first ] = f[v][u];
					que[r++] = {e[x][w].first, e[x][w].second};
				} else {
					f[ e[x][w].second ][ e[x][w].first ] = f[v][u] + t[u] + t[ e[x][w].first ];
					que[r++] = {e[x][w].first, e[x][w].second};
				}
			}
		}
	}
	int res = 0x3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		res = min(res, f[y][i]);
	}
	return res;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i)
		cin >> w[i];
	for(int i = 1; i <= n; ++i) {
		cin >> k;
		for(int j = 1; j <= 2*k; ++j) {
			cin >> a[j] >> t[j];
			e[ a[ j-1 ] ].push_back( {i, a[j]} );
			e[ a[j] ].push_back( {i, a[ j-1 ]} );
		}
	}
	for(int i = 1; i <= q; ++i) {
		cin >> x >> y;
		cout << bfs(x, y) << '\n';
	}
	return 0;
}
