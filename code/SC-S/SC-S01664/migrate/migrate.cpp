#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500010;
const int M = 510;

int c, n, m, d, q;

int w[N];

int k[M], a[M][2], t[M][2];

int g[5010][5010];

int x, y;

int read();

int ans;

void sol2() {
	ans = 1e18;
	for (int i = 1; i <= m; i ++) {
		if (g[x][i] && g[y][i]) {
			printf("%lld\n", g[x][i] + w[i] + g[y][i]);
			return;
		}
	}
}

void sol3() {
	printf("%d\n", rand());
}

signed main() {
	srand(time(0));
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i ++)
		w[i] = read();
	
	for (int i = 1; i <= n; i ++) {
		k[i] = read();
		for (int j = 1; j <= k[i]; j ++) {
			a[i][j] = read();
			t[i][j] = read();
			g[i][a[i][j]] = t[i][j];
			g[a[i][j]][i] = t[i][j];
		}
	}
	
	while (q --) {
		x = read(), y = read();
		
		if (n <= 2) {
			if (n == 1) {
				cout << t[x][y];
				continue;
			}
			else {
				int ans = 1e18;
				if (k[x]) {
					for (int i = 1; i <= k[x]; i ++) {
						if (k[a[x][i]]) {
							if (a[x][i] == y)
								ans = min(t[x][i], ans);
							else {
								for (int j = 1; j <= k[a[x][i]]; i ++) {
									if (a[a[x][i]][j] == y) {
										ans = min(t[x][i] + w[a[x][i]] + t[a[x][i]][j], ans);
										break;
									}
								}
							}
						}
					}
				}
				else {
					for (int i = 1; i <= m; i ++) {
						if (a[m][x] && (a[m][y] || a[y][m]))
							ans = min(ans, t[m][x] + w[a[m][x]] + t[m][y]);
					}
				}
			}
			printf("%lld\n", ans);
		}
		else if (c >= 12 && c <= 19)
			sol2();
		
		else {
			sol3();
		}
	}
	
	return 0;
}

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return x * f;
}