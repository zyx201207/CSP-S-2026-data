#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
int c, n, m, d, q;
int w[M], k[N], x[Q], y[Q];
long long D[1005][1005];
long long dis[M + N];
bool vis[M + N];
vector<pair<int, int> > g[M + N];
void dijkstra(int s) {
	for(int i = 1; i <= m + n; i++) {
		dis[i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<pair<int, int> > q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()) {
		auto k = q.top();
		q.pop();
		int u = k.second;
//		cout << u << "\n";
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto edge : g[u]) {
			int v = edge.first, w = edge.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		}
	}
}
void dijkstra1(int s) {
	for(int i = 1; i <= m + n; i++) {
		D[s][i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<pair<int, int> > q;
	q.push({0, s});
	D[s][s] = 0;
	while(!q.empty()) {
		auto k = q.top();
		q.pop();
		int u = k.second;
//		cout << u << "\n";
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto edge : g[u]) {
			int v = edge.first, w = edge.second;
			if(D[s][v] > D[s][u] + w) {
				D[s][v] = D[s][u] + w;
				q.push({-D[s][v], v});
			}
		}
	}
}
void bfs(int s) {
	for(int i = 1; i <= m + n; i++) {
		dis[i] = 0;
		vis[i] = 0;
	}
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto edge : g[u]) {
			int v = edge.first;
			if(vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}
int read() {
	int res = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * flag;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	int T = 0;
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++) {
		k[i] = read();
		for(int j = 1; j <= k[i]; j++) {
			int u = read(), w = read();
			T = w;
			int v = i + m;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	for(int i = 1; i <= q; i++) x[i] = read(), y[i] = read();
	if(q <= 2000 && m <= 400) {
		for(int i = 1; i <= q; i++) {
			dijkstra(x[i]);
			cout << w[x[i]] + dis[y[i]] + w[y[i]] << "\n";
		}
	}
	else if(q <= 2000){
		for(int i = 1; i <= q; i++) {
			bfs(x[i]);
			cout << w[x[i]] + T * dis[y[i]] + w[y[i]] << "\n";
		}
//	cout << 1 << "\n";
	}
	else {
		for(int i = 1; i <= m; i++) dijkstra1(i);
		for(int i = 1; i <= q; i++) cout << w[x[i]] + D[x[i]][y[i]] + w[y[i]] << "\n";
	}
	return 0;
}
