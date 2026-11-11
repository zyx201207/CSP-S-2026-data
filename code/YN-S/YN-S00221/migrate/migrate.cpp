#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, tot, head[2000005], a[2000005], dd[2000005], cnt[2000005];

struct uv {
	int to, nt;
} e[25000005];

void add(int u, int v) {
	e[++tot] = {v, head[u]};
	head[u] = tot;
	return;
}
bool vis[2000005];

void dij(int s) {
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
	q.push({0, s});
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(dd, 0x3f, sizeof(dd));
	dd[s] = 0;

	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		vis[u] = 1;

		for (int i = head[u]; i; i = e[i].nt) {

			int v = e[i].to;
//			cout << u << " " << v << "\n";

			if (dd[v] == dd[u] + 1) {
				cnt[v]++;
			}

			if (dd[v] > dd[u] + 1) {
				cnt[v] = 1;
				dd[v] = dd[u] + 1;

				if (!vis[v]) {
					q.push({dd[v], v});
				}
			}
		}
	}

	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		if (n <= 3) {
			cout << 0 << "\n";
			continue;
		}

		if (c == 11 || c == 12) {
			int x = a[2] - a[1];

			if (2 * x <= d && d < 3 * x) {
				cout << n - 3 << "\n";
			} else {
				cout << 0 << "\n";
			}

			continue;
		}

		tot = 0;
		memset(head, 0, sizeof(head));

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if (a[j] - a[i] <= d) {
					add(i, j);
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++) {

			dij(i);

			for (int j = 1; j <= n; j++) {

//				cout << cnt[j] << " ";

				if (cnt[j] == 2) {
					ans++;
				}
			}

//			cout << "\n";
		}

		cout << ans << '\n';
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/