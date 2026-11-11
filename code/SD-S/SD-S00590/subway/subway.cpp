#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn = 505;
const int maxm = 5e5 + 5;
int xian1, xian2;
ll val1, val2;
int sizx, sizy, x, y;
ll ans;
int xianxu1, xianxu2;
ll tim1, tim2;
ll dist[maxn][maxn];
vector<pair<ll, int> > G[maxn];
void dijkstra(int s) {
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > minHeap;
	minHeap.push({0, s});
	dist[s][s] = 0;
	while (!minHeap.empty()) {
		int u = minHeap.top().second;
		ll dis = minHeap.top().first;
		minHeap.pop();
		if (dis != dist[s][u]) {
			continue;
		}
		int siz = G[u].size();
		for (int i = 0; i < siz; i ++) {
			ll w = G[u][i].second;
			int v = G[u][i].first;
			if (dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w;
				minHeap.push({dist[s][v], v});
			}
		}
	}
}
ll c, n, m, d, q;
ll w[maxn], k[maxn];
pair<int, int> taktim[maxm][21];
int xbb[maxm];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = (ll)read();
	n = (ll)read();
	m = (ll)read();
	d = (ll)read();
	q = (ll)read();
	for (int i = 1; i <= m; i ++) {
		w[i] = (ll)read();
		xbb[i] = 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		k[i] = (ll)read();
		for (int j = 1; j <= k[i]; j ++) {
			int a = read();
			int t = read();
			cout << a << " " << t << "\n";
			taktim[a][xbb[a]] = {i, t};
			xbb[a] ++;
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = 2e18;
		}
	}
	for (int i = 1; i <= m; i ++) {
		int xb = xbb[i];
		for (int j = 0; j < xb; j ++) {
			for (int k = j + 1; k < xb; k ++) {
				xian1 = taktim[i][j].first;
				xian2 = taktim[i][k].first;
				val1 = (ll)taktim[i][j].second;
				val2 = (ll)taktim[i][k].second;
				if(xian1 == xian2) {
					continue;
				}
				/*
				dist[xian1][xian2] = min(dist[xian1][xian2], val1 + val2);
				dist[xian2][xian1] = min(dist[xian2][xian1], val1 + val2);
				*/
				
				G[xian1].push_back({xian2, val1 + val2});
				G[xian2].push_back({xian1, val1 + val2});
				
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		dijkstra(i);
		/*
		for (int k = 1; k <= n; k ++) {
			for (int j = 1; j <= n; j ++) {
				dist[k][j] = min(dist[k][j], dist[k][i] + dist[i][j]);
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
		*/
	}
	while(q --) {
		x = read();
		y = read();
		sizx = xbb[x];
		sizy = xbb[y];
		ans = 2e18;
		for (int i = 0; i < sizx; i ++) {
			for (int j = 0; j < sizy; j ++) {
				xianxu1 = taktim[x][i].first;
				xianxu2 = taktim[y][j].first;
				tim1 = (ll)taktim[x][i].second;
				tim2 = (ll)taktim[y][j].second;
				ans = min(ans, w[x] + w[y] + dist[xianxu1][xianxu2] + tim1 + tim2);
			}
		}
		printf("%lld\n", ans);
	}
}
