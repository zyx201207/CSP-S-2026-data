#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 200009, INF = 1e9;
queue<int> q;
vector<int> to[N];
int bcj[N], d[N], c, t, n, k;
int ppc(int ord) {
	int cnt = 0;
	while (ord) cnt++, ord &= ord - 1;
	return cnt;
}
int root(int u) {
	return bcj[u] = bcj[u] == u ? u : root(bcj[u]);
}
bool ok(int ord) {
	for (int i = 1; i <= n; i++) bcj[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j : to[i]) {
			if (!(ord >> i - 1 & 1) || !(ord >> j - 1 & 1)) continue;
			int u = root(i), v = root(j);
			if (u == v) continue;
			bcj[u] = v;
		}
	int r1 = 0, r2 = 0;
	for (int i = 1; i <= n; i++)
		if ((ord >> i - 1 & 1) && root(i) == i) {
//			cout << r1 << ' ' << r2 << ' ' << i << endl;
			if (r2) return 0;
			else if (r1) r2 = i;
			else r1 = i;
		}
	return 1;
}
int bfs(int ord) {
	fill(d + 1, d + n + 1, INF);
	for (int i = 1; i <= n; i++)
		if (ord >> i - 1 & 1) {
			d[i] = 0;
			q.push(i);
		}
	int ans = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : to[u]) {
			if (d[u] + 1 >= d[v]) continue;
			ans = max(ans, d[u] + 1), d[v] = d[u] + 1;
			q.push(v);
		}
	}
	return ans;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int al = 1 << n, ans = INF;
		for (int i = 1; i < al; i++)
			if (ppc(i) == k && ok(i)) ans = min(ans, bfs(i));
//		cout << ok(7) << ' ' << bfs(7) << endl; 
		cout << ans << endl;
		for (int i = 1; i <= n; i++) to[i].clear();
	}
	return 0;
}
/*
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
*/ 
