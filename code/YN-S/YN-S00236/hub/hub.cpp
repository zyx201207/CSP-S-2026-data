#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, T, n, k, Max[N], vis[N], f[N], V[N], ans;
vector<int>e[N];

int find(int x) {
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}

bool check() {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (auto v : e[i]) {
			if (vis[i] && vis[v])
				f[find(i)] = find(v);
		}
	}
	unordered_set<int>stk;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			stk.insert(find(i));
	}
	if (stk.size() <= 2)
		return 1;
	return 0;
}

int ds() {
	queue<pair<int, int>>pq;
	for (int i = 1; i <= n; i++) {
		V[i] = 0;
		if (vis[i]) {
			pq.push({i, 0});
		}
	}
	int Ans = 0;
	while (!pq.empty()) {
		int x = pq.front().first, res = pq.front().second;
		pq.pop();
		if (V[x])
			continue;
		V[x] = 1;
		Ans = max(Ans, res);
		for (auto v : e[x]) {
			pq.push({v, res + 1});
		}
	}
	return Ans;
}

void p(int x, int su) {
	if (x == n + 1) {
		if (su)
			return;
		if (check()) {
			ans = min(ans, ds());
		}
		return;
	}
	if (su) {
		vis[x] = 1;
		p(x + 1, su - 1);
		vis[x] = 0;
	}
	p(x + 1, su);
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (c == 13 || c == 14) {
			int m = n / 2;
			if (k == n) {
				cout << 0 << "\n";
				continue;
			}
			if (k >= m) {
				cout << 1 << "\n";
				continue;
			}
			cout << (m - k + 3) / 4 + 1 << "\n";
		} else {
			if (k == n) {
				cout << 0 << "\n";
				continue;
			}
			if (k >= n / 2) {
				cout << 1 << "\n";
				continue;
			}
			ans = 1e9;
			p(1, k);
			cout << ans << "\n";
		}
	}
	return 0;
}
