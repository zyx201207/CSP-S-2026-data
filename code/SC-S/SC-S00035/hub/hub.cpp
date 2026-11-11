#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+3;
int c, t;
int n, k, mn;
int g[32][32], e[32][32];
int a[32];
int fa[32];
bool vis[32];
int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}
void unite(int x, int y) {
	int X = find(x), Y = find(y); 
	if (X == Y) return;
	fa[X] = Y; 
}
int flfl() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = g[j][i] = e[i][j];
		}
	} 
	for (int K = 1; K <= k; K++) {
		int kk = a[K];
		g[kk][kk] = 0;
		for (int I = 1; I <= k; I++) {
			for (int J = 1; J <= k; J++) {
				int i = a[I],j = a[J];
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[j][i] = g[i][j] = g[i][k] + g[k][j];
					res = max(res, g[j][i]);
				}
			}
		}
	} 
}
void dfs(int p, int x) {
	if (p == k + 1) {
		int cnt = 0;
//		for (int i = 1; i <= n; i++) {
//			fa[i] = i;
//			vis[i] = 0;
//		}
//		for (int i = 1; i <= k; i++) {
////			cout << a[i] << ' ';
//			unite(a[i], a[i+1]);
//		}
////		cout << endl;
//		for (int i = 1; i <= n; i++) {
//			vis[fa[i]] = 1;
//		}
//		for (int i = 1; i <= n; i++) {
//			cnt += vis[fa[i]];
//		}
//		if (cnt > 2) return;
		
		mn = min(mn, flfl());
	}
	for (int i = x+1; i <= n; i++) {
		a[p] = i;
		dfs(p+1, i);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		mn = 1e9;
		cin >> n >> k;
		memset(g, 0x3f, sizeof g);
		for (int i = 1; i < n; i++) {
			fa[i] = i;
			int u, v;
			cin >> u >> v;
			e[u][v] = e[v][u] = 1;
		}
		fa[n] = n;
		dfs(1, 0);
		cout << mn << '\n';
	} 
	return 0;
} 