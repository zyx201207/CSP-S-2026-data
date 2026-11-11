#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
const int MAXN = 1e5 + 10;
int w[MAXN];
int fa[MAXN];
int a[505][MAXN];
int t[505][MAXN];
int k[505];
int x[MAXN], y[MAXN];
vector< pair<int, int> >g[MAXN];

void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}

int find(int num) {
	return fa[num] == num ? num : fa[num] = find(fa[num]);
}

void merge(int n1, int n2) {
	int f1 = find(n1), f2 = find(n2);
	if (f1 == f2)
		return;
	fa[n1] = fa[n2];
}
bool vis[MAXN];
int dist[MAXN];

void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > >Q;
	Q.push({0, s});
	while (!Q.empty()) {
		int d = Q.top().first;
		int u = Q.top().second;
		Q.pop();
		if (vis[u])
			continue;
		for (auto e : g[u]) {
			int v = e.first;
			int w = e.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				Q.push({dist[v], v});
			}
		}
		vis[u] = 1;
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	//cout << "1!!!!!!!!!!!" << endl;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	//cout << "2!!!!!!!!!!!" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		//cout << "3!!!!!!!!!!!" << endl;
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
		}
		//cout << "4!!!!!!!!!!!" << endl;
		for (int j = 1; j <= k[i]; j++) {
			for (int l = 1; l <= k[i]; l++) {
				if (j == l)
					continue;
				g[j].push_back({a[i][l], t[i][i] + t[i][l]});
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= q; i++) {
		int s = x[i];
		int end = y[i];
		dijkstra(s);
		cout << w[s] + dist[end] + w[end] << "\n";
	}
	return 0;
}