#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch & 15);
		ch = getchar();
	}
	return x * f;
} 
const int N = 5e5 + 5;
int C, n, m, u, v, d, q, k, i, j, f[505][505], w[N], res;
queue<int> que;
//vector<int> vt[N];
vector<pair<int, int> > bl[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read();
	n = read();
	m = read();
	d = read();
	q = read(); 
	memset(f, 0x3f, sizeof f); 
	for(i = 1;i <= m;++ i) w[i] = read();
	for(i = 1, k;i <= n;++ i) {
		k = read();
		f[i][i] = 0;
		while(k --) {
			C = read();
			bl[C].push_back({i, read()});
		}
	}
	for(k = 1;k <= m;++ k) {
		for(pair<int, int> it : bl[k]) {
			for(pair<int, int> jt : bl[k]) {
				if(it.first == jt.first) continue;
				f[it.first][jt.first] = min(f[it.first][jt.first], it.second + jt.second);
			}
		}
	}
	for(k = 1;k <= n;++ k)
		for(i = 1;i <= n;++ i)
			for(j = 1;j <= n;++ j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q --) {
		u = read(), v = read();
		res = 0x3f3f3f3f3f3f3f3f;
		for(pair<int, int> it : bl[u])
			for(pair<int, int> jt : bl[v]) {
				res = min(res, f[it.first][jt.first] + it.second + jt.second);
			}
		cout << res + w[u] + w[v] << '\n';
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
