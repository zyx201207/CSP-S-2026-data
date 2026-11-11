#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d, vis[5005], a[5004];
vector<int>e[5005];

bool bfs(int s, int f) {
	queue<pair<int, int>>q;
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	vis[s] = 1;
	q.push({s, 0});
	int dis = -1, cnt = 0;
	while (!q.empty()) {
		int u = q.front().first, step = q.front().second;
		q.pop();
		for (auto v : e[u]) {
			if (v == f) {
				if (dis == -1)
					cnt++, dis = step;
				else if (dis == step)
					cnt++;
				if (cnt > 2)
					return false;
			}
			if (!vis[v]) {
				vis[v] = 1;
				q.push({v, step + 1});
			}
		}
	}
	return cnt == 2;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		if (n <= 300) {
			for (int i = 1; i <= n; i++)
				e[i].clear(), cin >> a[i];
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					if (a[j] - a[i] <= d) {
						e[i].push_back(j);
						e[j].push_back(i);
					}
			int ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					ans += bfs(i, j);
			cout << ans << '\n';
		} else {
			while (n--)
				cin >> d;
			cout << "0\n";
		}
	}
	return 0;
}