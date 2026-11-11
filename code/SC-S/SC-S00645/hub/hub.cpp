#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 300 + 25;

int c, t, n, k, x, y, ans = 1e18;

map<int, int> mp;
void dfs(vector<int> pts, vector<vector<int>> &g, int fat, int now) {
	if (pts.size() == k) {
		int cc = 0;
		for (auto i : pts) {
			for (auto k : pts) {
				if (i != k && mp[i] == 1 && mp[k] == 1) 
					cc++;
			}
		}
		if (k - cc / 2 > 2) {
			return;
		}
		queue<pair<int, int>> q;
		for (auto i : pts) {
			q.push({i, 0});
		}
		vector<int> cp(50, 1e18);
		int res = 0;
		while (q.size()) {
			auto ft = q.front();
			q.pop();
			for (auto i : g[ft.first]) {
				if (ft.second + 1 < cp[i]) {
					q.push({i, ft.second + 1});
					cp[i] = ft.second + 1;
					res = max(res, cp[i]);
				}
			}
		}
		if (res < ans) {
			ans = min(res, ans);
//			for (auto i : pts) {
//				cout << i << ' ' ;
//			}
//			cout << '\n';
		}
	}
	
	for (auto i : g[now]) {
		if (i != fat) {
			pts.push_back(i);
			mp[i] = 1;
			dfs(pts, g, now, i);
			mp[i] = 0;
			pts.pop_back();
			mp[i] = 2;
			dfs(pts, g, now, i);
			mp[i] = 0;
		}
//		cout << "while\n";
		
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		vector<vector<int>> g(n + 1, vector<int>());
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans = 1e18;
		for (int i = 1; i <= n; i++) {
			mp[i] = 1;
			dfs({i}, g, 0, i);
			mp[i] = 2;
			dfs({}, g, 0, i);
			mp[i] = 0;
		}
		cout << ans << '\n';
	}
	
	return 0;
}