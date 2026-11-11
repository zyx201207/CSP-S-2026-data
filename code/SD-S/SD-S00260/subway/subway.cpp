#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char a = getchar();
	while (a < '0' || a > '9') {
		if (a == '-') f = -1;
		a = getchar();
	}
	while (a >= '0' && a <= '9') {
		x = x * 10 + a - '0';
		a = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 500, M = 5e5 + 10, D = 22, Q = 1e5 + 10;
int c, n, m, d, q;
int w[M];
int p[M];//k i表示第i个站台连着地铁线路的数量 
int a[M][D];//a i j表示在第i个站台连着的第j个地铁线路 
int t[M][D];//t i j表示在第i个站台连着的第j个地铁线路台到大厅的时间 
int dis[N][N];//dis i j表示第i个线路到第j个线路转乘最少需要多少时间 
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		int k = read();
		while (k--) {
			int x = read(), y = read();
			a[x][++p[x]] = i;
			t[x][p[x]] = y;
//			cout << " ? " << x << " ? " << y << " ? " << p[x] << " ? " << a[x][p[x]] << " ? " << t[x][p[x]] << " ? \n";
		}
	}
	for (int i = 1; i <= n; ++i) for (int j = 1; j < i; ++j) dis[i][j] = dis[j][i] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; ++i) {
		if (p[i] < 2) continue;
		for (int j = 1; j <= p[i]; ++j) {
			for (int k = 1; k < j; ++k) {
				dis[a[i][j]][a[i][k]] = dis[a[i][k]][a[i][j]] = t[i][j] + t[i][k];
//				cout << a[i][j] << "!!!" << a[i][k] << "!!!" << t[i][j] << "!!!" << t[i][k] << "!!!\n";
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			cout << dis[i][j] << "  ";
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= q; ++i) {
		int x = read(), y = read();
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 1; j <= p[x]; ++j) {
			for (int k = 1; k <= p[y]; ++k) {
//				cout << ans << ":" << a[x][j] << ":" << a[y][k] << ":" << w[x] << ":" << w[y] << ":" << t[x][j] << ":" 
//				<< t[y][k] << ":" << dis[a[x][j]][a[y][k]] << ":\n";
				if (w[x] + w[y] + t[x][j] + t[y][k] + dis[a[x][j]][a[y][k]] < ans) {
					ans = w[x] + w[y] + t[x][j] + t[y][k] + dis[a[x][j]][a[y][k]];
				}
//				ans = min(ans, w[x] + w[y] + t[x][j] + t[y][k] + dis[a[x][j]][a[y][k]]);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
