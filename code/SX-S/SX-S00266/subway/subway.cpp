#include <bits/stdc++.h>
using namespace std;


const int maxn = 5e3+100;
typedef pair<pair<int, int>, int> piii;
int n, m, d, p, w[maxn];
int t1[maxn][maxn], h[maxn], e[maxn], w1[maxn], ne[maxn], idx;
long long dist[maxn];
bool st[maxn];

void add(int x, int y, int z) {
	e[idx] = y, w1[idx] = z, ne[idx] = h[x], h[x] = idx++;
}


int dijkstra(int in_, int out_) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	priority_queue<piii, vector<piii>, greater<piii>> q;
	dist[in_] = 0;
	q.push({{0, in_}, 0});
	while (!q.empty()) {
		auto ll = q.top();
		q.pop();
		auto lu = ll.second;
		auto dian = ll.first;
		int u = dian.second;
		if (st[u])
			continue;
		st[u] = 1;
		for (int i = h[u]; ~i; i = ne[i]) {
			int j = e[i], w2 = 0;
			if (u == in_)
				w2 = t1[u][w1[i]];
			if (w1[i] != lu && u != 1) {
				w2 = t1[u][w1[i]] + t1[u][lu];
			}
			if (j == out_)
				w2 += t1[j][w1[i]];
			if (dist[j] > dist[u] + w2) {
				dist[j] = dist[u] + w2;
				q.push({{dist[j], j}, w1[i]});
			}
		}
	}
	return dist[out_];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;
	memset(h, -1, sizeof h);
	cin >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		int a1;
		for (int j = 1; j <= k; j++) {
			int a2 = 0, t = 0;
			cin >> a2 >> t;
			t1[a2][i] = t;
			if (j > 1)
				add(a1, a2, i);
			a1 = a2;
		}
	}
	while (p--) {
		int in_, out_;
		cin >> in_ >> out_;
		cout << dijkstra(in_, out_) + w[in_] + w[out_] << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
