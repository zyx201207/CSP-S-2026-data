#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
const ll INF = 1e18;
ll c, n, m, d, q, ans = INF;
ll w[N], a[N], t[N];
struct node {
	ll a, t;
};
struct Node {
	ll v, w;
};
vector <node> ve[N];
vector <Node> g[N];
queue <ll> qu;
ll dist[N];
void dij (int s, int f) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	qu.push (s);
	dist[s] = 0;
	while (!qu.empty ()) {
		int u = qu.front();
		qu.pop();
		for (auto e : g[u]) {
			ll v = e.v, w = e.w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				qu.push (v);
			}
		}
	}
	ans = dist[f];
	return ;
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			if (j != 1) {
				g[a[j - 1]].push_back ({a[j], t[j - 1]});
			} 
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dij (x, y);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
