//2026.10.31  zyb  migrate
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, d, x[N], ans;
vector<int>e[N];
int dis[N], cnt[N];
bool vis[N];

priority_queue<pair<int, int> >q;
void dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		dis[i] = 1e9;
		cnt[i] = 0;
	}
	cnt[s] = 1, dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (auto v : e[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = 0;
				q.push({-dis[v], v});
			}
			if (dis[v] == dis[u] + 1)
				cnt[v] += cnt[u];
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int id, T;
	cin >> id >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		if (n == 0) {
			cout << "0\n";
			continue;
		}
		bool flagA = true;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i > 2 && x[i] - x[i - 1] != x[2] - x[1])
				flagA = false;
		}
		if (flagA) {
			if (d < 2 * (x[2] - x[1]))
				cout << "0\n";
			else
				cout << max(n - d / (x[2] - x[1]) * 2 + 1, 0LL) << '\n';
			continue;
		}
		if (n > 5000) {
			for (int i = 1; i < n; i++) {
				int L = upper_bound(x + 1, x + n + 1, x[i] - d) - x;
				int R = lower_bound(x + 1, x + n + 1, x[i + 1] + d) - x - 1;
				if (x[R] - x[i - 1] > d && x[i + 2] - x[L] > d) {
					ans++;
				}
			}
			cout << ans << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			int j = i - 1;
			while (j && x[i] - x[j] <= d) {
				e[i].push_back(j);
				e[j].push_back(i);
				j--;
			}
		}
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
			for (int i = 1; i <= n; i++)
				ans += (cnt[i] == 2);
		}
		cout << ans / 2 << '\n';
	}
	return 0;
}