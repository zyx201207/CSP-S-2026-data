#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, M = 5005;
int c, T, n, vis[M], dis[M], g[M];
long long ans, d, a[N];
priority_queue<pair<int, int> >q;
vector<int>e[M];

void dij(int s) {
	for (int i = s; i <= n; i++)
		dis[i] = 1e9, vis[i] = 0, g[i] = 0;
	dis[s] = 0, g[s] = 1;
	q.push({0, s});
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (int i = 0; i < e[x].size(); i++) {
			int v = e[x][i];
			if (dis[v] > dis[x] + 1)
				dis[v] = dis[x] + 1, g[v] = g[x], q.push({-dis[v], v});
			else if (dis[v] == dis[x] + 1) {
				if (g[v] <= 10)
					g[v] += g[x];
			}
		}
	}
	for (int j = s + 1; j <= n; j++)
		if (g[j] == 2)
			ans++;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n <= 5000) {
			for (int i = 1; i <= n; i++) {
				e[i].clear();
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d)
						e[i].push_back(j);
					else
						break;
				}
			}
			for (int i = 1; i <= n; i++)
				dij(i);
			cout << ans << "\n";
		} else if (c >= 11 && c <= 12) {
			if (n <= 2) {
				cout << 0 << "\n";
			} else {
				if (a[3] - a[1] > d)
					cout << 0 << "\n";
				else {
					int cnt = 0;
					for (int i = 1; i <= n; i++) {
						if (a[i] - a[1] > d) {
							cnt = i - 2;
							break;
						}
					}
					if (cnt == 0)
						cnt = n - 1;
					for (int i = 1; i <= n; i++) {
						if (i + 2 * cnt - 1 <= n)
							ans++;
					}
					cout << ans << "\n";
				}
			}
		}
	}
	return 0;
}