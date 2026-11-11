#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005000;
const int H = 1055;
int n, k, cid, d[N], w[N], dis[H][H];
vector <int> G[N];
queue <int> q;
vector <int> ps;
void calc () {
	for (int i = 1; i <= n; i++) {
		d[i] = 0x3f3f3f3f;
	}
	for (int h : ps) {
		q.push (h);
		d[h] = 0;
	}
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (int v : G[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push (v);
			}
		}
	}
	return;
}
int ans = 0x3f3f3f3f;
bool vis[N], ok[N];
void bfs (int sp) {
	q.push (sp);
	vis[sp] = 1;
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (int v : G[u]) {
			if (ok[v] and !vis[v]) {
				q.push (v);
				vis[v] = 1;
			} 
		}
	}
	return;
}
void checkit () {
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		ok[i] = 0;
		vis[i] = 0;
	}
	int ltk = 0;
	for (int g : ps) {
		ok[g] = 1;
	}
	for (int g : ps) {
		if (!vis[g]) {
			ltk++;
			bfs (g);
		}
	}
	calc ();
	for (int i = 1; i <= n; i++) {
		mx = max (mx, d[i]);
	}
	if (ltk <= 2) {
		ans = min (ans, mx);
	}
	for (int g : ps) {
		ok[g] = 0;
	}
	return;
}
void Dfs (int u, int cnt) {
	if (n - u + cnt < k) return;
	if (cnt == k) {
		checkit ();
		return;
	}
	ps.emplace_back (u + 1);
	Dfs (u + 1, cnt + 1);
	ps.pop_back ();
	Dfs (u + 1, cnt);
	return;
}
inline void baosou () {
	Dfs (0, 0);
	cout << ans << "\n";
	return;
}
inline void add (int u, int v) {
	G[u].emplace_back (v);
	return;
}
inline void solve () {
	ans = 0x3f3f3f3f;
	ps.clear ();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		G[i].clear ();
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add (u, v);
		add (v, u);
	}
	if (cid <= 3) {
		baosou ();
		return;
	}
	return;
}
int main () {
//	freopen ("migrate3.in", "r", stdin);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	int T;
	cin >> cid >> T;
	while (T--) {
		solve ();
	}
	return 0;
}
/*
17:50还剩40(30)分钟 应该240分 
再来40分 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
