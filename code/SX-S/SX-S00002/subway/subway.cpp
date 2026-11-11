#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x[500010], y[500010];
long long w[500010], k[510], t[510][500010], ans, a[510][500010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	// ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线
//     路的站台需要的时间。
//     c, n, m, d, q，分别表示测试点编号、地铁线路数、
//     地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
//     w1, w2, . . . , wm，依次表示从每个地铁站的地铁口走
//     到站厅需要的时间。
	int fi = 0, si = 0;
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		ans += w[x[i]] + w[y[i]];
		//完成了从起始站口/终点站口到首乘线路站台/末乘线路站台的路程↓
		for (int j = 1; j <= n; j++) {
			for (int e = 1; e <= m; e++) {
				if (a[j][e] == x[i]) {
					ans += t[j][x[i]];
					fi = j;
				}
				if (a[j][e] == y[i]) {
					ans += t[j][y[i]];
					si = j;
				}
			}
		}
		//重点：完成中间路程（两种情况：转/不转）
		if (fi == si) {
			for (int j = x[i]; j <= y[i]; j++) {
				if (j == x[i]) {
					continue;
				}
				ans += t[fi][j];
			}
		}//不用换的↑---------------------------------------------------------------------------------------------------------------------------------------------------
		else {
			ans += t[fi + 1][si];
		}
	}
	cout << ans;
	return 0;
}
