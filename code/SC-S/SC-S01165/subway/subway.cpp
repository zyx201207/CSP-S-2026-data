#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 505
#define maxm 500005
#define inf 0x3f3f3f3f3f3f3f3fLL
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
int c, n, m, d, q;
int w[maxm], s[maxn][maxn], a[maxn][maxn], t[maxn][maxn];
vector<int> z[maxn];
void floyed() {
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (s[i][k] != inf && s[k][j] != inf)
					s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
}
void solve() {
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) {
			s[i][j] = inf;
			if (i == j) s[i][j] = 0;
		}
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k;
		k = read();
		for (int j = 1; j <= k; j++) {
			a[i][j] = read();
			t[i][a[i][j]] = read();
			z[i].push_back(a[i][j]);
		}
		for(size_t l = 0;l < z[i].size();l++)
			for(size_t r = l + 1;r < z[i].size();r++){
				int x = z[i][l], y = z[i][r];
				s[x][y] = s[y][x] = t[i][x] + t[i][y];
			}
	}
	floyed();
	for (int i = 1; i <= q; i++) {
		int x, y, ans;
		x = read(), y = read();
		ans = w[x] + w[y] + s[x][y];
		printf("%lld\n", ans);
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	solve();
	return 0;
}