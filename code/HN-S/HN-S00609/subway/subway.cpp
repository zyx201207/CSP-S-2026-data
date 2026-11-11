#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int c, n, m, d, q;
int out[N], step[N][N];
bool vis[N];
vector<vector<int>> line;
void solve(int s);
int lout[N][N], sons[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	line.resize(n);
	for (int i = 1; i <= m; i ++) {
		cin >> out[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> sons[i];
		line[i].resize(sons[i]);
		for (int j = 1; j <= sons[i]; j ++) {
			cin >> line[i][j];
			step[i][line[i][j]] = 0;
			cin >> lout[i][line[i][j]];
		}
	}
	memset(step, 0x3f, sizeof step);
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		solve(i);
	};
	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << out[l] + out[r] + step[l][r] << endl;
	}
	return 0;
}
//void solve(int x) {
//	for (auto u : line[x]) {
//		step[x][u] = min(step[x][u], step[])
//	}
//}
void solve(int x) {
	queue<int> que;
	que.push(x);
	while (que.size()) {
		int th = que.front();
		que.pop();
		for (auto u : line[th]) {
			if (!vis[u]) {
				que.push(u);
				step[th][u] = min(step[th][u], step[x][th] + lout[])
			}
		}
	}
}
