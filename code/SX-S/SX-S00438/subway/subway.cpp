#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[1000], k[1000], a, t[1000][1000], x, y, t1[1000][1000], tx, s = 0;

int f(int x1) {
	if (t1[x1][y] != 0)
		return t1[x1][y];
	int l = 0, l1;
	for (int i = 1; i <= n; i++) {
		if (t[x1][i] != 0) {
			l1 = t[x1][i] + f(i);
			if (l1 < l || l == 0)
				l = l1;
		}
	}
	t1[x1][y] = l;
	return l;
}

int main() {
//	freopen("subway.in ", "r", stdin);
//	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a;
			cin >> t[a][i];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (t[i][j] != 0) {
				for (int z = j + 1; z <= n; z++) {
					if (t[i][z] != 0) {
						if (t1[j][z] > t[i][z] + w[j] || t1[j][z] == 0)
							t1[j][z] = t[i][z] + w[j];
					}
				}
			}
		}
	}
	while (cin >> x >> y) {
		s = 0;
		for (int i = 1; i <= m; i++) {
			if (t[x][i] != 0) {
				tx = w[x] + t[x][i] + f(i);
				if (tx < s || s == 0)
					s = tx;
			}
		}
		cout << s;
	}
	return 0;
}