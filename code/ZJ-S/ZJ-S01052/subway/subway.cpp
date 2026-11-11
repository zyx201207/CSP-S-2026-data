#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ft first
#define sd second
const int M = 5e5 + 10;
const int INF = 4e18;
int c, n, m, d, q;
int w[M];
int f[505][505];
vector<pair<int,int> > opt[M];
char buf[1 << 20], *p1, *p2;
char gc() {
	if (p1 == p2) {
		p1 = buf;
		p2 = buf + fread(buf, 1, 1 << 20, stdin);
		if (p1 == p2) return EOF;
	}
	return *p1++;
}
void read(int& x) {
	x = 0;
	int fh = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') fh = -1;
	for (; isdigit(c); c = gc()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= fh;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	read(c), read(n), read(m), read(d), read(q);
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1, k; i <= n; i++) {
		read(k);
		for (int j = 1, a, t; j <= k; j++) {
			read(a), read(t);
			opt[a].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = INF;
	for (int op = 1; op <= m; op++) {
		for (int i = 0; i < opt[op].size(); i++) {
			for (int j = 0; j < opt[op].size(); j++) {
				int idxi = opt[op][i].ft, idxj = opt[op][j].ft;
				int ii = opt[op][i].sd, jj = opt[op][j].sd;
				if (i == j) {
					f[idxi][idxj] = f[idxj][idxi] = 0;
					continue;
				}
				int t = ii + jj;
				f[idxi][idxj] = min(f[idxi][idxj], t);
				f[idxj][idxi] = min(f[idxj][idxi], t);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		read(x), read(y);
		int ans = INF;
		int k1 = 0, k2 = 0;
		for (int i = 0; i < opt[x].size(); i++) {
			for (int j = 0; j < opt[y].size(); j++) {
				int idx = opt[x][i].ft, idy = opt[y][j].ft;
				if (ans > f[idx][idy]) {
					ans = f[idx][idy], k1 = i, k2 = j;
				}
			}
		}
		cout << ans + w[x] + w[y] + opt[x][k1].sd + opt[y][k2].sd << '\n';
	}
	return 0;
}