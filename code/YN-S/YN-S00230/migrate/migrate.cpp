#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int c, t, n, a[N], d;
vector<int>g[N];
int dis[N], dis1[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			dis[i] = 0;
			dis1[i] = 0;
			g[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i != j && abs(a[i] - a[j]) <= d) {
					g[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[j] = 1e18;
			}
			queue<int>q;
			dis[i] = 0, dis1[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int t = q.front();
				q.pop();
				for (int v : g[t]) {
					if (dis[t] + 1 < dis[v]) {
						dis[v] = dis[t] + 1;
						dis1[v] = dis1[t];
						q.push(v);
					} else if (dis[t] + 1 == dis[v]) {
						dis1[v] += dis1[t];
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				if (dis1[j] == 2)
					ans++;
				//		cout << dis1[i] << " ";
			}
			//	cout << "\n";
		}
		cout << ans << "\n";
	}

	return 0;
}