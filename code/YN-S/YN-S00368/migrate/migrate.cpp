#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 5e3 + 5, M = 2e6 + 5;
int c, T, n, d, ans;
int x[M], dis[M], inq[N], f[N];
vector<int> G[N];
queue<int> q;

void spfa(int s) {
	for (int i = 1; i <= n; i++)
		dis[i] = n + 5, f[i] = 0;
	inq[s] = f[s] = 1, dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (auto v : G[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				f[v] = f[u];
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			} else if (dis[v] == dis[u] + 1)
				f[v] += f[u];
		}
	}
}

void Clear() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		dis[i] = f[i] = 0;
		G[i].clear();
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	if (c <= 10) {
		while (T--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (x[j] - x[i] > d)
						break;
					G[i].push_back(j);
				}
			}
			for (int i = 1; i <= n; i++) {
				spfa(i);
				for (int j = i + 1; j <= n; j++)
					if (f[j] == 2)
						ans++;
			}
			cout << ans << '\n';
			Clear();
		}
	}
	if (11 <= c && c <= 12) {
		while (T--) {
			int cnt = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			for (int i = 1; i <= n; i++)
				if (x[1] + d < x[i] && x[i] < x[1] + 2 * d)
					cnt++;
			cout << cnt*(n - cnt) << '\n';
		}
	}
	if (13 <= c && c <= 14) {
		while (T--) {
			int pos;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			for (int i = 1; i <= n; i++)
				if (x[i] - d <= x[1] && x[n] <= x[i] + d) {
					pos = i;
					break;
				}
			cout << (pos - 1)*(n - pos) << '\n';
		}
	}
	return 0;
}
