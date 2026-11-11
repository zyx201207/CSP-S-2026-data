#include <bits/stdc++.h>
const int maxm = 2e4 + 10;
const int maxm_taskn2 = 5e5 + 10;
long long w[maxm_taskn2], dis[maxm][505];
int c, n, m, d, q, x, y;
long long distrain[505][505];
std::vector<int> train[maxm];
long long disspecial[maxm_taskn2][4];
bool vis[maxm_taskn2][4];
long long solve(int x, int y) {
	long long ans = 1e18 + 50;
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, dis[x][i] + dis[y][i]);
	}
	return ans;
}
void compute() {
	for (int z = 1; z <= m; z++) {
		if (train[z].size() > 1) {
			for (int i = 0; i < train[z].size(); i++) {
				for (int j = i + 1; j < train[z].size(); j++) {
					distrain[train[z][i]][train[z][j]] = std::min(distrain[train[z][i]][train[z][j]], dis[z][train[z][i]] + dis[z][train[z][j]]);
					distrain[train[z][j]][train[z][i]] = distrain[train[z][i]][train[z][j]];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || k == j)
					continue;
				distrain[i][j] = std::min(distrain[i][j], distrain[i][k] + distrain[k][j]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < train[i].size(); j++) {
			for (int z = 1; z <= n; z++) {
				dis[i][z] = std::min(dis[i][z], dis[i][train[i][j]] + distrain[train[i][j]][z]);
			}
		}
	}
}
void solve2() {
	memset(disspecial, 0x3f, sizeof(disspecial));
	memset(vis, false, sizeof(vis));
	long long zuixiaoxianglian = 1e18 + 50;
	for (int i = 1; i <= n; i++) {
		distrain[i][i] = 0;
		int num;
		std::cin >> num;
		for (int j = 1; j <= num; j++) {
			int daoda;
			long long shijian;
			std::cin >> daoda >> shijian;
			disspecial[daoda][i] = shijian;
			vis[daoda][i] = true;
		}
	}
	bool ifnis1 = true; 
	for (int i = 1; i <= m; i++) {
		if (vis[i][1] && vis[i][2])
			ifnis1 = false;
		zuixiaoxianglian = std::min(disspecial[i][1] + disspecial[i][2], zuixiaoxianglian);
	}
	if (ifnis1)
		zuixiaoxianglian = 0; //n = 1
	while (q--) {
		long long cnt = 1e18 + 50;
		std::cin >> x >> y;
		if (vis[x][1] && vis[y][1]) {
			cnt = std::min(cnt, disspecial[x][1] + disspecial[y][1]);
		}
		if (vis[x][2] && vis[y][2]) {
			cnt = std::min(cnt, disspecial[x][2] + disspecial[y][2]);
		}
		if (vis[x][1] && vis[y][2]) {
			cnt = std::min(cnt, disspecial[x][1] + disspecial[y][2] + zuixiaoxianglian);
		}
		if (vis[x][2] && vis[y][1]) {
			cnt = std::min(cnt, disspecial[x][2] + disspecial[y][1] + zuixiaoxianglian);
		}
		std::cout << w[x] + w[y] + cnt; 
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(distrain, 0x3f, sizeof(distrain));
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	if (c >= 22 && c <= 23) {
		solve2();
	} else {
		for (int i = 1; i <= n; i++) {
			distrain[i][i] = 0;
			int num;
			std::cin >> num;
			for (int j = 1; j <= num; j++) {
				int daoda;
				long long shijian;
				std::cin >> daoda >> shijian;
				train[daoda].push_back(i);
				dis[daoda][i] = shijian;
			}
		}
		compute();
		while (q--) {
			std::cin >> x >> y;
			std::cout << solve(x, y) + w[x] + w[y] << "\n";
		}	
	}
}
