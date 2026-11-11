#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e4 + 10;
int c, n, m, d, q;
int w[N];
ll dist[N][N];

int main () {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(dist , 0x3f3f3f3f , sizeof dist);
	for (int i = 1; i <= m; i++) 
		dist[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		ll sum = 0;
		for (int j = 1; j <= k; j++) {
			int v, w; cin >> v >> w;
			sum += w;
			dist[i][v] = dist[v][i] = sum;
		}
	}
	
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dist[i][j] = min(dist[i][j] , 
								 dist[i][k] + dist[k][j] + w[j] + w[i]);
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		cout << dist[x][y] << "\n";
	}
	return 0;
}
