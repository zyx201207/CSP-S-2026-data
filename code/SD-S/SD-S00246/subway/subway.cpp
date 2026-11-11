#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

typedef pair<int, int> pii;

const int M = 5e5 + 5;
const int N = 5e2 + 5; 
const int T = 1e3 + 5;

int c, m, n, d, q;
int W[M];
int a[N][N], t[N][N];
int dis[T][T];
bool vis[N][T];

struct edge {
	int v, tag;
};
vector<edge> G[M]; 

int Dijkstral(int u, int tag) {
	
}

void solve(int u, int v) {
	int tag = 0;
	for (int i = 1; i <= n; ++ i) {
		int tmp;
		if (vis[i][u]) tmp = i;
		dfs(u, v, tmp, dis);		
	} 
}

int dfs(int u, int V, int tag, int dis) {
	for (edge e : G[u]) {
		int v = e.v, tmp = e.tag;
		if (v == V) {
			if (tag == tmp) return dis;
			return dis + t[tmp][v];
		}
		if (tag == tmp) {
			
		}
	}
}


int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	
	c = read(), m = read(), n = read(), d = read(), q = read();
	
	for (int i = 1; i <= m; ++ i) {
		W[i] = read();
	}
	
	for (int i = 1; i <= n; ++ i) {
		int k;
		k = read();
		for (int j = 1; j <= k; ++ j) {
			a[i][j] = read();
			vis[i][a[i][j]] = 1;
			t[i][j] = read();
			if (j >= 2) {
				int u = a[i][j - 1], v = a[i][j], tag = i;
				G[u].push_back({v, tag});
				G[v].push_back({u, tag}); 
			}
		}
	}
	
	while (q --) {
		int u, v;
		u = read(), v = read();
		ans = tag1 = tag2 = 0;
		ans = solve(u, v);
		ans += W[u] + W[v];
		printf("%d", ans);
	}
	
	puts("我常常追忆过去"); 
	
	return 0;
}
