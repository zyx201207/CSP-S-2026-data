#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 510, M = 1010, D = 30, INF = 0x3f3f3f3f;
int c, n, m, d, q;
int w[M], k[N], a[N][M], t[N][M];
int x, y, ans;
int dist[M][M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++) cin >> a[i][j] >> t[i][j];
	}
	while(q --) {
		cin >> x >> y;
		cout << w[x] + w[y] << endl;
	}
	
	return 0;
}
