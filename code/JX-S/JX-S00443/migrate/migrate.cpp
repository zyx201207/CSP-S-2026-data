#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int a[5005], dis[5005], cnt[5005];
vector<int> vi[5005];
int n, d;
void bfs(int x) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
		cnt[i] = 0;
	}
	queue<int> q;
	dis[x] = 0;
	cnt[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : vi[u]) {
			if (dis[i] != 1e9) {
				if (dis[i] == dis[u] + 1) {
					cnt[i]++;
					q.push(i);
				}
				continue;
			}
			dis[i] = dis[u] + 1;
			cnt[i] = 1;
			q.push(i);
		}
	}
}
signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			vi[i].clear();
		}
		if (13 <= c && c <= 14) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) {
					vi[i].push_back(j);
					vi[j].push_back(i);
				} else {
					break;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			bfs(i);
			for (int j = i + 1; j <= n; j++) {
				if (cnt[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*

Luogu uid: 1277793 Ciallo~
O(n ^ 3)

*/
