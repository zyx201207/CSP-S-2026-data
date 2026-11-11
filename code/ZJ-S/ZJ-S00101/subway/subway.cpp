#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 500010;
int w[M];
long long edg[N][N];
vector<pair<int, int> > g[M];

void chkmin(long long&a, long long b) {
	a = (b < a) ? b : a;
}

void qr(int &x) {
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int ccccc, n, m, d, q;
	//scanf("%d%d%d%d%d", &ccccc, &n, &m, &d, &q);
	qr(ccccc); qr(n); qr(m); qr(d); qr(q);
	for (int i = 1; i <= m; i ++ ) qr(w[i]);
	for (int i = 1; i <= n; i ++ ) {
		int k;
		qr(k);
		while (k -- ) {
			int a, t;
			qr(a); qr(t);
			g[a].push_back({i, t});
		}
	}
	memset(edg, 0x3f, sizeof edg);
	for (int i = 1; i <= n; i ++ ) edg[i][i] = 0;
	for (int i = 1; i <= m; i ++ ) {
		for (int j = 0; j < g[i].size(); j ++ )
			for (int k = j + 1; k < g[i].size(); k ++ ) {
				int a = g[i][j].first, b = g[i][k].first;
				chkmin(edg[a][b], g[i][j].second + g[i][k].second);
			}
	}
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			chkmin(edg[i][j], edg[j][i]);
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ ) {
				chkmin(edg[i][j], edg[i][k] + edg[k][j]);
			}
	for (int i = 1; i <= q; i ++ ) {
		int a, b;
		scanf("%d%d", &a, &b);
		long long ans = 2e18;
		for (auto j : g[a])
			for (auto k : g[b]) {
				ans = min(ans, edg[j.first][k.first] + j.second + k.second + w[a] + w[b]);
			}
		printf("%lld\n", ans);
	}
		
	return 0;
} 
//¾¡Á¿¿¨ 
