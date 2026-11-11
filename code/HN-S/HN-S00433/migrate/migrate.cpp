#include<bits/stdc++.h>//24~40pts
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int c, T, n;
ll d, pos[N];
vector<int> g[5005];
ll dist[5005][5005], f[5005][5005];
void bfs(int s) {
	for (int i = 1; i <= n; ++ i) {
		dist[s][i] = -1; 
		f[s][i] = 0;
	}
	queue<int> q;
	dist[s][s] = 0;
	f[s][s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (dist[s][v] == -1) {
				dist[s][v] = dist[s][u] + 1;
				f[s][v] += f[s][u];
				q.push(v);
			}
			else if (dist[s][u] + 1 == dist[s][v]) {
				f[s][v] += f[s][u];
			}
		}
	}
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) {
		cin >> pos[i];
		g[i].clear();
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (i == j) {
				continue;
			}
			if (abs(pos[i] - pos[j]) <= d) {
				g[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		bfs(i);
	}
	ll cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			if (f[i][j] == 2) {
				cnt ++;
			}
		}
	}
	cout << cnt << "\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T --) {
		solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
