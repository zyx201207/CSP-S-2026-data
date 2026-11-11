#include <bits/stdc++.h>
using namespace std;
int w[500010], bis[510][510], vis[510];
vector<int> a[2010], b[2010];

int main() {
	long long c, n, m, d, p, k, a1, a2, b1, b2, x, y;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (k <= 1) {
			continue;
		}
		cin >> a1 >> a2 >> b1 >> b2;
		a[a1].push_back(b1);
		a[b1].push_back(a1);
		b[a1].push_back(a2 + b2);
		b[b1].push_back(a2 + b2);
	}
	queue<int> q;
	memset(bis, 0x7f, sizeof(bis));
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		bis[i][i] = 0;
		q.push(i);
		vis[i] = 1;
		long long u = 0, v = 0, len = 0;
		while (!q.empty()) {
			u = q.front();
			q.pop();
			vis[u] = 0;
			len = a[u].size();
			for (int j = 0; j < len; j++) {
				v = a[u][j];
				if (!vis[v] && bis[i][v] > (bis[i][u] + b[u][j])) {
					q.push(v);
					vis[v] = 1;
					bis[i][v] = bis[i][u] + b[u][j];
				}
			}
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> x >> y;
		cout << bis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}
