#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, t[500010], f[500010], k[510], way[510][5010];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		for (int i = 1; i <= n; i++) {
			int f1 = 0, ti = 0;
			for (int j = 1; j <= k[i] * 2; j += 2) {
				if (way[i][j] == v) {
					f1 = j;
					ti = way[i][j + 1];
					break;
				}
			}
			if (f1 != 0) {
				for (int j = 1; j <= k[i] * 2; j += 2) {
					if (way[i][j] != v) {
						int x = f[v] + ti + way[i][j + 1];
						if (f[way[i][j]] > x) {
							q.push(way[i][j]);
							f[way[i][j]] = x;
						}
					}
				}
			}
		}
		q.pop();
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i] * 2; j ++) {
			cin >> way[i][j];
		}
	}
	for (int i = 1; i <= q; i ++) {
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= m; j++) {
			f[j] = INT_MAX;
		}
		f[x] = t[x];
		bfs(x);
		cout << f[y] + t[y] << endl;;
	}
	return 0;
}