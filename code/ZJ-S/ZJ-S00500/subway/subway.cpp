#include<bits/stdc++.h>
using namespace std;
int g, n, m, t, qu, a[10000010], d[10000010];
struct node {
	int v, w;
};
vector<node> e[10000010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void dij(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		for(auto x : e[u]) {
			int v = x.v, w = x.w;
			if(d[u] + w < d[v]) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> g >> n >> m >> t >> qu;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int k, x[20010], p;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> x[j] >> p;
			int u = i * m + x[j];
			if(j > 1) {
				int v = i * m + x[j - 1];
				e[u].push_back({v, 0}), e[v].push_back({u, 0});
			}
			e[u].push_back({x[j], p});
			e[x[j]].push_back({u, p});
		}
	}
	for(int i = 1; i <= qu; i++) {
		int u, v;
		cin >> u >> v;
		dij(u);
		cout << a[u] + d[v] + a[v] << '\n';
	}
	return 0;
}