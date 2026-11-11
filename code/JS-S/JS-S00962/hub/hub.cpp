#include<bits/stdc++.h>

using namespace std;

vector<int> to[2000005];
int dis[2000005];
int on[2000005];
vector<int> s;
bool ok;
int tdis[2000005];
int q[2000005];
int mx[2000005], m2[2000005];
int up[2000005];
int sz[2000005];
int mid;
int s2;

void dfs(int x, int fa) {
	for (int v: to[x]) if (v != fa) dis[v] = dis[x] + 1, dfs(v, x);
}

void dft(int x, int fa, int bn) {
	if (x == bn) ok = 1;
	if (ok) return;
	s.push_back(x);
	for (int v: to[x]) if (v != fa) dft(v, x, bn);
	if (ok) return;
	s.pop_back();
}

void dfu(int x, int fa) {
	tdis[x] = m2[x] = mx[x] = 0;
	for (int v: to[x])
		if (v != fa and !on[v]) {
			dfu(v, x);
			if (tdis[v] + 1 > mx[x]) m2[x] = mx[x], mx[x] = tdis[v] + 1;
			else m2[x] = max(m2[x], tdis[v] + 1);
			tdis[x] = max(tdis[x], tdis[v] + 1);
		}
}

void dfv(int x, int fa) {
	if (tdis[x] >= mid) s2 = min(s2, -up[x]);
	for (int v: to[x])
		if (v != fa and !on[v]) {
			up[v] = up[x] + ((mx[x] == tdis[v] + 1 ? mx[x] : m2[x]) < mid);
		}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, _;
	cin >> c >> _;
	while (_--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) to[i].clear();
		memset(on, 0, sizeof(on));
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dis[1] = 0;
		dfs(1, 0);
		int u = max_element(dis + 1, dis + n + 1) - dis;
		dis[u] = 0;
		dfs(u, 0);
		int v = max_element(dis + 1, dis + n + 1) - dis;
		s.clear(), ok = 0;
		s.push_back(0);
		dft(u, 0, v);
		int len = s.size();
		s.push_back(v);
		for (int i = 1; i <= len; i++) on[s[i]] = i;
		for (int i = 1; i <= len; i++) dfu(s[i], 0);
		int l = -1, r = len - 1;
		while (l < r - 1) {
			for (int i = 1; i <= len; i++) q[i] = 0;
			mid = (l + r + 1) >> 1;
			int s1 = s2 = 0;
			int l1 = s.size(), r2 = 1;
			for (int i = 1; i <= len; i++) {
				dfv(s[i], 0);
				int x, y;
				if (tdis[s[i]] >= mid) x = y = i;
				else x = i - (mid - tdis[s[i]]), y = i + (mid - tdis[s[i]]);
				x = max(x, 1), y = min(y, len);
				l1 = min(l1, y), r2 = max(r2, x);
				q[y + 1] = max(q[y + 1], x);
			}
			int r1 = l1;
			for (int i = l1 + 1; i <= r2; i++) {
				r1 = max(r1, q[i]);
				s1 = min(s1, -(i - r1 - 1));
			}
			int tg = 0;
			for (int i = 1; i <= n; i++) tg += !on[i] and tdis[i] >= mid;
			if (min(s1, s2) + max(1, r2 - l1 + 1) + tg <= k) r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
}