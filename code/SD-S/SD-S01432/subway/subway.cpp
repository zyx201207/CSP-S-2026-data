#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50000;
ll w[MAXN];
ll dis[MAXN];
bool vis[MAXN];
ll a[MAXN];
ll t[MAXN];
vector <pair <int, int>> g[MAXN];
void dj (int s) {
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
	pq.push({0, s});
	dis[s] = 0;
	while (!pq.empty ()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (auto e : g[u]) {
			int v = e.first;
			int w = e.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}
void solve () {
	int c, n, m ,d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int h = j + 1; h <= k; h++) {
				g[a[j]].push_back({a[h], t[j] + t[h]});
				g[a[h]].push_back({a[j], t[j] + t[h]});
			}
		}
	}
	while (q--) {
		memset (dis, 0x3f, sizeof (dis));
		memset (vis, false, sizeof (vis));
		int x, y;
		cin >> x >> y;
		dj (x);
		ll ans = w[x] + w[y];
		ans += dis[y];
		cout << ans << "\n";
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve ();
	return 0;
}
