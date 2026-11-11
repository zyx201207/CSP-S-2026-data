#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
int w[20010], t[510][20010], k[510], a[510][20010];
bool vis[20010];

long long bfs(int u, int v) {
	memset(vis, 0, sizeof vis);
	priority_queue<pair<int, long long>> q;
	q.push(make_pair(u, 0));
	vis[u] = true;
	while (!q.empty()) {
		int now = q.top().first;
		long long val = q.top().second;
		cout << now << endl;
		if (now == v) return val;
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= k[i]; ++j) 
				if (!vis[a[i][j]]) q.push(make_pair(a[i][j], t[i][j] + val)), vis[a[i][j]] = true;
	}
	return -1;
}

int main( ) {
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
			cin >> a[i][j] >> t[i][j];
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << bfs(x, y) << '\n';
	}
	return 0;
}