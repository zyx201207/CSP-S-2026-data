#include <bits/stdc++.h>

using namespace std;

int c, T;
int n, k;
vector<int> e[2000010];
int ans = -1;
bool st[200010];

void dfs(int u, int x) {
	st[u] = true;

	for (auto v : e[u]) {
		if (((x >> (v - 1)) & 1) && !st[v]) {
			dfs(v, x);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> c >> T;
	while (T--) {
		for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
		cin >> n >> k;
		ans = n + 1;
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		for (int i = 0; i < (1 << n); ++i) {
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1) ++cnt;
			}
			
			if (cnt != k) continue;
			
			for (int j = 1; j <= n; ++j) st[j] = false;
			int cc = 0;
			for (int j = 0; j < n; ++j) {
				if (((i >> j) & 1) && !st[j + 1]) {
					++cc;
					dfs(j + 1, i);
				}
			}
			
			if (cc > 2) continue;

			int res = 0;
//			cout << i << "\n";
			for (int j = 1; j <= n; ++j) {
				if ((i >> (j - 1)) & 1) continue;
				for (int k = 1; k <= n; ++k) st[k] = false;

				queue<pair<int, int>> q;
//				cout << "__" << i << "\n";
				q.push({j, 1});
				st[j] = true; bool is_ = false;
				while (q.size()) {
					auto t = q.front(); q.pop();
//					cout << "-------" << t.first << ' ' << t.second << "\n";

					for (auto v : e[t.first]) {
						if (!st[v]) {
							st[v] = true;
							q.push({v, t.second + 1});
							if ((i >> (v - 1)) & 1) {
								is_ = true;
								res = max(res, t.second);
								break;
							}
						}
					}
					if (is_) break;
				}
			}

//			if (res == 1) cout << i << "\n";
			ans = min(ans, res);
		}
		
		cout << ans << "\n";
	}

	return 0;
}
