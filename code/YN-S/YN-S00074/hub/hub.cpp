#include <bits/stdc++.h>
using namespace std;
int c, T;
int n, k;
vector<int> G[110];
int a[32], vis[32], dis[32], ans;

bool check() {
	int manx = k;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			int flag = 1;
			for (int j = 0; j < G[i].size(); j++) {
				int v = G[i][j];
				if (a[v] && flag) {
					manx--;
					flag = 0;
				}
			}
		}
	}
	if (manx <= 2)
		return true;
	else
		return false;
}

void BFS() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			vis[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < G[now].size(); i++) {
			int v = G[now][i];
			if (vis[v])
				continue;
			dis[v] = dis[now] + 1;
			vis[v] = 1;
			q.push(v);
		}
	}
}

void solve() {
	if (c <= 3) {
		for (int i = 1; i <= n; i++)
			G[i].clear();
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int nk = (1 << n);
		ans = 1e9;
		for (int i = 1; i < nk; i++) {
			if (__builtin_popcount(i) != k)
				continue;
			memset(a, 0, sizeof(a));
			int d = i, tot = 1;
			while (d) {
				if (d & 1)
					a[tot] = 1;
				tot++;
				d >>= 1;
			}
			if (!check())
				continue;
			//cout << i << "R\n";
			memset(vis, 0, sizeof(vis));
			memset(dis, 0, sizeof(dis));
			BFS();
			int rans = -1;

			for (int i = 1; i <= n; i++) {
				//cout << dis[i] << " ";
				if (dis[i] > rans)
					rans = dis[i];
			}
			ans = min(ans, rans);
			//cout << rans << " " << ans << "\n";
		}
		cout << ans << "\n";
	} else if (c == 7 || c == 11 || c == 12) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		cout << 1 << "\n";
	}
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
//注意到k==2时是?!树的重心重的树!?
//怎么判连通块
//状压->__builtin_popcount先筛选一批->连通块个数=点个数->用BFS->BFS第一轮扫到同样在队中的点连通块个数就减一->多于两个就毙了