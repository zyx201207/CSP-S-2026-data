#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510, M = 500010, K = 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, dd, q, t, x, y, w[M], v[M][K], d[M][K], num[M];
ll dist[N][N];
int read() {
	int x = 0;
	char c = getchar();
	while(c < 48 || c > 57) c = getchar();
	while(c >= 48 && c <= 57) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return x;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), dd = read(), q = read();
	for(int i = 1; i <= m; i ++) w[i] = read();
	memset(dist, 0x3f, sizeof dist);
	for(int i = 1; i <= n; i ++) dist[i][i] = 0;
	for(int i = 1; i <= n; i ++) {
		t = read();
		while(t --) {
			x = read(), y = read();
			v[x][num[x]] = i;
			d[x][num[x] ++] = y;
		}
	}
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < num[i]; j ++) {
			int u = v[i][j];
			for(int k = j + 1; k < num[i]; k ++) {
				int w = v[i][k];
				int now = d[i][j] + d[i][k];
				if(now < dist[u][w]) dist[u][w] = dist[w][u] = now;
			}
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while(q --) {
		x = read(), y = read();
		int a = num[x], b = num[y];
		ll res = inf;
		for(int i = 0; i < a; i ++)
			for(int j = 0; j < b; j ++)
				res = min(res, d[x][i] + dist[v[x][i]][v[y][j]] + d[y][j]);
		printf("%lld\n", res + w[x] + w[y]);
	}
	return 0;
}