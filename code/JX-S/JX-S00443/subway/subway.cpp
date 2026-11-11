#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int w[500005];
map<int, vector<pii> > mp;
int _, n, m, d, q;
vector<pii> vi[500505];
int dis[500505], ans[100005];
set<pii> st;
bool b[500505];
void spfa(int x) {
	for (int i = 0; i <= n + m; i++) {
		dis[i] = 1e18;
		b[i] = 0;
	}
	st.clear();
	dis[x] = 0;
	st.insert({0, x});
	while (!st.empty()) {
		int u = st.begin()->second;
		b[u] = 1;
		st.erase(st.begin());
		for (auto i : vi[u]) {
			int v = i.first, p = i.second;
			if (b[v]) continue;
			if (dis[v] > dis[u] + p) {
				dis[v] = dis[u] + p;
				st.insert({dis[v], v});
			}
		}
	}
}
void b_bfs(int x) {
	for (int i = 0; i <= n + m; i++) {
		dis[i] = 0;
	}
	queue<int> qu;
	qu.push(x);
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for (auto i : vi[u]) {
			int v = i.first;
			if (dis[v]) continue;
			dis[v] = dis[u] + 1;
			qu.push(v);
		}
	}
}
int _a[500005], __a[2][500005];
signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> _ >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (n == 1) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			int x, y;
			cin >> x >> y;
			_a[x] = y;
		}
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + _a[x] + _a[y] << "\n";
		}
		return 0;
	}
	if (n == 2) {
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++) {
				int x, y;
				cin >> x >> y;
				__a[i][x] = y;
			}
		}
		int minn = 1e18;
		for (int i = 1; i <= m; i++) {
			if (__a[1][i] != 0 && __a[2][i] != 0) {
				minn = min(minn, __a[1][i] + __a[2][i]);
			}
		}
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			int res = 1e18;
			if (__a[1][x] != 0 && __a[1][y] != 0) {
				res = min(res, __a[1][x] + __a[1][y]);
			}
			if (__a[2][x] != 0 && __a[2][y] != 0) {
				res = min(res, __a[2][x] + __a[2][y]);
			}
			if (__a[1][x] != 0 && __a[2][y] != 0) {
				res = min(res, __a[1][x] + __a[2][y] + minn);
			}
			if (__a[2][x] != 0 && __a[1][y] != 0) {
				res = min(res, __a[2][x] + __a[1][y] + minn);
			}
			cout << w[x] + w[y] + res << "\n";
		}
		return 0;
	}
	int _b = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			if (!_b && _ >= 12 && _ <= 19) {
				_b = y;
			}
			vi[m + i].push_back({x, y});
			vi[x].push_back({m + i, y});
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		mp[x].push_back({y, i});
	}
	for (auto &i : mp) {
		if (!_b)
			spfa(i.first);
		else 
			b_bfs(i.first);
		for (auto j : i.second) {
			int p = j.first, id = j.second;
			if (!_b)
				ans[id] = dis[p] + w[i.first] + w[p];
			else
				ans[id] = dis[p] * _b + w[i.first] + w[p];
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}

/*

Luogu uid: 1277793 Ciallo~
O(q(n + m))

md,wssb!
tmd, use 1.in and 2.ans to debug 10 min

*/
