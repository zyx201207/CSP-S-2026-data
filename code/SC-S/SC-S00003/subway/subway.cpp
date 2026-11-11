#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int a[maxn][maxn];
int c, n, m, d, p, cnt;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> p;
	cnt = 2 * n + 1;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i < maxn; ++i) {
		a[i][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[i][n + i] = a[n + i][i] = x;
	}
	for (int i = 1; i <= m; i++) {
		int t, f = 0;
		cin >> t;
		while (t--) {
			int u, w;
			cin >> u >> w;
			a[u + n][cnt] = a[cnt][u + n] = w;
			if (!f) {
				f = 1;
			} else {
				a[cnt - 1][cnt] = a[cnt][cnt - 1] = 0;
			}
			cnt++;
		}
	}
	for (int k = 1; k <= cnt; ++k) {
		for (int i = 1; i <= cnt; ++i) {
			for (int j = 1; j <= cnt; ++j) {
				if (a[i][k] + a[k][j] < a[j][i]) {
					a[i][j] = a[j][i] = a[i][k] + a[k][j];
				}
			}
		}
	}
	while (p--) {
		int u, v;
		cin >> u >> v;
		cout << a[u][v] << "\n";
	}
	return 0;
}