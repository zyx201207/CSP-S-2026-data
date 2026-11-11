#include <bits/stdc++.h>
using namespace std;
int TTT, T, n;
long long d;
const int N = 2e6 + 10;
long long a[N];

vector<int>e[N];

long long dis[N], cnt[N];
bool vis[N];
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0, cnt[s] = 1;
	priority_queue<pair<long long, int>>q;
	q.push({0, s});
	while (q.size()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (auto v : e[x]) {
			if (dis[v] > dis[x] + 1) {
				dis[v] = dis[x] + 1;
				cnt[v] = cnt[x];
				q.push({-dis[v], v});
			} else if (dis[v] == dis[x] + 1) {
				cnt[v] += cnt[x];
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> TTT >> T;
	while (T--) {
		cin >> n >> d;
		bool flg = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
				flg = 1;
			e[i].clear();
		}
		if (n > 5000 && !flg) {
			int s = a[2] - a[1];
			if (s > d) {
				cout << 0 << "\n";
				continue;
			}
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				ans += (n - i - 1) / (d / s);
			}
			cout << ans << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
			for (int j = i + 1; j <= n; j++) {
				if (dis[j] == 0x3f3f3f3f)
					continue;
				if (cnt[j] == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
