#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 1005, D = 25, Q = 100005;

int c, n, m, d, q, k[N], a[N][M], t[N][M], x, y;
ll cost, f[M][M], w[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(f, 0x3f3f3f3f, sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++) {
		cin >> k[i];
		for (int j = 1;j <= k[i];j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int fir = 1;fir < k[i];fir++) {
			for (int sec = fir + 1;sec <= k[i];sec++) {
				cost = (long long)t[i][fir] + t[i][sec];
				f[a[i][fir]][a[i][sec]] = min(cost, f[a[i][fir]][a[i][sec]]);
				f[a[i][sec]][a[i][fir]] = min(cost, f[a[i][sec]][a[i][fir]]);
			}
		}
	}
		
	for (int k = 1;k <= m;k++) {
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= m;j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		cin >> x >> y;
			
		cout << f[x][y] + w[x] + w[y] << "\n";
	}
	
	return 0;
}
