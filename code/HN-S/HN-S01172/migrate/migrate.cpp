#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 10;

int c, t, n, d, x[N], dis[N], minn = 2e18;
vector<int> nbr[N];
bool vis[N];

void dfs1(int u, int tar, int sum) {
	if (sum > minn)
		return;
	if (sum > dis[u])
		return;
	dis[u] = sum; 
	if (u == tar) {
		minn = min(minn, sum);
		return;
	}
	for (int v : nbr[u]) {
		dfs1(v, tar, sum + 1);
	}
	return;
}

int cnt = 0;

void dfs2(int u, int tar, int sum, int minn) {
	if (sum > minn)
		return;
	if (cnt > 2)
		return;
	if (u == tar) {
		cnt++;
		return;
	}
	for (int v : nbr[u]) {
		dfs2(v, tar, sum + 1, minn);
	}
	return;
}

//void bfs() {
//	queue<int> q;
//	q.push(1);
//	dis[1] = 0;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int v : nbr[u]) {
//			if (dis[v] > dis[u] + 1) {
//				dis[v] = dis[u] + 1;
//				cnt[v] = cnt[u];
//			} else if (dis[v] == dis[u] + 1) {
//				cnt[v] += cnt[u];
//			} 
//		}
//	}
//	
//}

void Solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		nbr[i].clear();
		dis[i] = 2e18;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(x[j] - x[i]) <= d)
				nbr[i].push_back(j);
			else
				break;
		} 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			minn = 2e18;
			dfs1(i, j, 0);
			cnt = 0;
			dfs2(i, j, 0, minn);
			if (cnt == 2) {
				ans++;
			}
		} 
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		Solve();
	}
	return 0;
}

