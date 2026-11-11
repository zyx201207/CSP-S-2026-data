#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 5e5 + 10, E = N * N * 2;
int rd() {
	int c = getchar();
	int op = 1;
	while(c > '9' || c < '0') {
		if(c == '-') op = -1;
		c = getchar();
	}
	int sum = 0;
	while('0' <= c && c <= '9') {
		sum = sum * 10 + c - '0';
		c = getchar();
	} 
	return sum;
}
int n, m, c, d, q;
int w[M];
vector<pair<int, int> > rc[M];
int dist[N][N], ans[N][N];
int head[N], to[E], nxt[E], wt[E], cnt = 0;
void add(int u, int v, int cst) {
	cnt++;
	to[cnt] = v;
	wt[cnt] = cst;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void intol() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[i][j] < 0x3f3f3f3f3f3f3f3f) {
				add(i, j, dist[i][j]);
//				cout << "RP++\n";
			}
		}
	}
}
void dijkstra(int u, int *dis) {
	for(int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f3f3f3f3f;
	dis[u] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, u});
	while(q.size()) {
		int now = q.top().second, d = q.top().first;
		q.pop();
		if(dis[now] != d) continue;
		for(int i = head[now]; i; i = nxt[i]) {
			int v = to[i];
			if(dis[v] > dis[now] + wt[i]) {
				dis[v] = dis[now] + wt[i];
				q.push({dis[v], v});
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for(int i = 1; i <= m; i++) w[i] = rd();
	for(int i = 1; i <= n; i++) {
		int k = rd();
		for(int j = 1; j <= k; j++) {
			int a = rd(), t = rd();
			rc[a].push_back({i, t});
//			rc[i][j].first = rd();
//			rc[i][j].second = rd();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = 0x3f3f3f3f3f3f3f3f;
		} 
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < rc[i].size(); j++) {
			for(int k = 0; k < j; k++) {
				int u = rc[i][j].first, v = rc[i][k].first;
				int wu = rc[i][j].second, wv = rc[i][k].second;
				dist[u][v] = min(dist[u][v], wu + wv);
				dist[v][u] = min(dist[v][u], wu + wv);
//				cout << "::" << u << " " << v << "\n";
			}
		}
	}
	intol();
	for(int i = 1; i <= n; i++) {
		dijkstra(i, ans[i]);
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) cout << dist[i][j] << " ";
//		cout << endl;
//	}
	for(int i = 1; i <= q; i++) {
		int x = rd(), y = rd();
		int su = 0x3f3f3f3f3f3f3f3f;
		for(int j = 0; j < rc[x].size(); j++) {
			for(int k = 0; k < rc[y].size(); k++) {
				int u = rc[x][j].first, v = rc[y][k].first;
				int wu = rc[x][j].second, wv = rc[y][k].second;
				su = min(su, w[x] + w[y] + wu + wv + ans[u][v]);
//				cout << "//" << wu << " " << wv << "\n";
			}
		}
		printf("%lld\n", su);
//		cout << "//" << w[x] << " " << w[y] << "\n";
	}
	return 0; 
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
