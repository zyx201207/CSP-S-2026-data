#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
int n;
ll d;
ll a[maxn];
struct Edge {
	ll to, w;
	bool operator< (const Edge& c) const {
		return w > c.w;
	}
};
vector<Edge> G[maxn];
ll dis[maxn];
ll cnt[maxn];
bool vis[maxn];
void dijkstra1 (int s) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f3f3f3f3f, vis[i] = false;
	priority_queue<Edge> q;
	q.push({s, 0});
	dis[s] = 0;
	while (q.size()) {
		Edge p = q.top();
		q.pop();
		if (vis[p.to]) continue;
		vis[p.to] = true;
		for (auto e : G[p.to]) {
			if (dis[e.to] > dis[p.to] + e.w) {
				dis[e.to] = dis[p.to] + e.w;
				q.push({e.to, dis[e.to]});
			}
		} 
	}
}
void dijkstra2 (int s) {
	for (int i = 1; i <= n; i++) cnt[i] = 0, vis[i] = false;
	priority_queue<Edge> q;
	q.push({s, 0});
	while (q.size()) {
		Edge p = q.top();
		q.pop();
		if (vis[p.to]) continue;
		vis[p.to] = true;
		for (auto e : G[p.to]) {
			q.push({e.to, p.w + e.w});
			if (p.w + e.w == dis[e.to] && dis[e.to] != 0x3f3f3f3f3f3f3f3f) cnt[e.to]++;
		} 
	}
	cnt[s] = 1;	
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (u == v) continue;
				if (abs(a[u] - a[v]) > d) continue;
				G[u].push_back({v, 1});
			}
		}
		size_t sum = 0;
		for (int u = 1; u <= n; u++) {
			dijkstra1 (u);
			dijkstra2 (u);
			for (int i = 1; i <= n; i++) {
				if (cnt[i] == 2) sum++;
			}
		}
		cout << size_t(sum / 2) << '\n';
	}
	return 0;
} 
