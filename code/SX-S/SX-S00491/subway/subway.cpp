#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i, j, k, q, none, none2;
	int a, b, c, d;
	int dis[5005][2005];
	int w[5005];

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> none >> n >> m >> none2 >> q;

	for (i = 1; i <= m; i++) {
		for (j = 1; j < m; j++) {
			dis[j][i] = 0X3f3f3f;
		}
		cin >> w[i];
		dis[m][m] = 0;
	}
	for (i = 0; i < n; i++) {
		cin >> k;
		cin >> a >> b;
		for (j = 1; j < k; i++) {
			cin >> c >> d;
			dis[a][c] = b + d, dis[c][a] = b + d;
			a = c, b = d;
		}
	}
	for (i = 1; i < m; i++) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < m; k++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (i = 0; i < q; i++) {
		cin >> j >> k;
		cout << w[j] + w[j] + dis[j][k] << endl;
	}
	return 0;
}

