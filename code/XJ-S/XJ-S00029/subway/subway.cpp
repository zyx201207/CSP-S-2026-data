#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
const int N = 5e5 + 555, M = 10e5 + 5;
int head[N], to[M], nxt[M], w[M];
int idx = 0;

void add_edge(int u, int v, int val) {
	idx++;
	w[idx] = val;
	to[idx] = v;
	nxt[idx] = head[u];
	head[u] = idx;
}

long long dis[N];
bool visited[N];
void solve(int start) {
	memset(dis, 0x3f, sizeof dis);
	memset(visited, 0, sizeof visited);
	visited[start] = true;
	dis[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, start});
	while (!pq.empty()) {
		pair<int, int> pr = pq.top(); pq.pop();
		int d = pr.first;
		int u = pr.second;
//		if (d >= dis[u]) continue;
		
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (dis[v] > (long long)d + w[i]) {
				dis[v] = d + w[i];
				pq.push({dis[v], v});
			}
		}
	}
}

int ddd[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; ++i) {
		int val;
		cin >> val;
		ddd[i] = val;
	}

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			add_edge(i, a + n, t);
			add_edge(a + n, i, t);
		}
	}
	
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		solve(u + n);
		cout << ddd[u] + dis[v + n] + ddd[v] << '\n';
	}
	
	return 0;
} 
