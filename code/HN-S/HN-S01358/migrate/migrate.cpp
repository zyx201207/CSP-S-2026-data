#include <bits/stdc++.h>
#define int long long
#define pk push_back
using namespace std;
const int N = 2e6 + 5;
const int inf = 1e9;
int c, t, n, d;
int p[N];
void subA() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	} 
	int one = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i] - p[1] <= d) {
			one++;
		}
	}
	if (one == 1) {
		cout << "0\n";
		return ;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i + 2 * one - 1 <= n) {
			ans++;
		}
	}
	cout << ans << "\n";
	return ;
}
const int M = 1005;
int dis[M][M];
int out[M];
vector<int> g[M];
bool vis[M];
void bfs(int rt) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	queue<int> q;
	q.push(rt);
	dis[rt][rt] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (vis[cur] == 1) continue;
		vis[cur] = 1;
		for (int f = 0; f < g[cur].size(); f++) {
			int nxt = g[cur][f];
			if (dis[rt][cur] + 1 < dis[rt][nxt]) {
				dis[rt][nxt] = dis[rt][cur] + 1;
				q.push(nxt);
			}
		}
	}
	return ;
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		g[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[j] - p[i] <= d) {
				g[i].pk(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
		bfs(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[j] - p[i] <= d) continue;
			for (int k = i; k <= j; k++) {
				for (int f = 0; f < g[k].size(); f++) {
					int l = g[k][f];
					if (dis[i][k] + dis[l][j] + 1 == dis[i][j]) {
						out[l]++;
					}
				}
			}
			int flag = 0;
			for (int k = 1; k <= n; k++) {
				flag += (out[k] == 2);
				if (out[k] > 2) {
					flag = 0;
					break;
				}
			}
			for (int k = 1; k <= n; k++) {
				out[k] = 0;
			}
			if (flag == 1) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return ;
}
void subB() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	} 
	cout << "0\n";
	return ;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	if (c >= 0 && c <= 10) {
		while (t--) {
			solve();
		}	
	} else if (c == 11 || c == 12) {
		while (t--) {
			subA();
		}
	} else if (c > 12) {
		while (t--) {
			subB();
		}
	}
	return 0;
}
/*

*/
