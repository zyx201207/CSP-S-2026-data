#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int c, n, m, d, q, w[N], a[N][N], t[N][N], k[N];
int g[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(g, 0x3f, sizeof g);
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++) {
			cin >> a[i][j] >> t[i][j];
			g[i][j] = t[i][j];
		}
	}
	for(int s = 1;s <= m;s ++) 
		for(int i = 1;i <= m;i ++) 
			for(int j = 1;j <= m;j ++) 
				g[i][j] = min(g[i][j], g[i][s] + g[s][j]);
	while(q --) {
		int x, y;
		cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}