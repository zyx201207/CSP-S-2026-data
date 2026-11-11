#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M];
vector<int> v[M], t[M];
long long dis[N][N];

long long solve(int x, int y) {
	long long ans = 1e18;
	for (int i = 0; i < v[x].size(); i++) {
		for (int j = 0; j < v[y].size(); j++) {
			ans = min(ans, dis[v[x][i]][v[y][j]] + t[x][i] + t[y][j]);
//			cout << v[x][i] << ' ' << v[y][j] << ' ' << dis[v[x][i]][v[y][j]] + t[x][i] + t[y][j] << '\n';
		}
	}
	return ans + w[x] + w[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(i), t[x].push_back(y);
		}
		for (int j = 1; j <= n; j++) {
			dis[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = 0; k < v[i].size(); k++) {
				if (j == k) continue;
				dis[v[i][j]][v[i][k]] = min(dis[v[i][j]][v[i][k]], (long long)t[i][j] + t[i][k]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][k] + dis[j][k], dis[i][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	return 0;
} 
