#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5007;
int c, t, n;
int x[N], d, dis[N][N], num[N];
vector<int> e[N];
queue<int> q;
map<pair<int, int>, int> ans;
inline
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = 1e10;
	}
	ans.clear();
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (abs(x[i] - x[j]) <= d) e[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		q.push(i);
		dis[i][i] = 0;
		for (int j = 1; j <= n; j++) num[j] = 1; 
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				if (dis[i][u] + 1 < dis[i][v]) {
					dis[i][v] = dis[i][u] + 1;
					num[v] = num[u];
					q.push(v);
				} else if (dis[i][u] + 1 == dis[i][v]) {
					num[v] += num[u];
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (num[j] == 2) {
				if (i > j) ans[{j, i}] = 1;
				else ans[{i, j}] = 1;
			} 
		}
	}
	cout << ans.size() << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}

