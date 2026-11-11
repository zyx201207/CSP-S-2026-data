#include <bits/stdc++.h>
using namespace std;
int _C, n, m, d, q;
int w[401];//1mb
int k[201];//1mb
int a[201][401];//1mb
int t[201][401];//1mb


int zhankou[401], zhanting[401]; //每个地铁站的各个部分图上节点名称，1mb
int by_[8801];//图上节点属于的站
int c[8801][8801] = {0}; //296mb
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> _C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}

	vector<int>g[8801];//296mb
	int tot = 0;
	for (int i = 1; i <= m; i++) { //站口和站厅
		tot++;
		zhankou[i] = tot;
		by_[tot] = i;
		tot++;
		zhanting[i] = tot;
		by_[tot] = i;
		g[zhanting[i]].push_back(zhankou[i]);
		g[zhankou[i]].push_back(zhanting[i]);
		c[zhanting[i]][zhankou[i]] = w[i];
		c[zhankou[i]][zhanting[i]] = w[i];
	}
	for (int i = 1; i <= n; i++) {//线路
		int last_zhantai = -1; //该线路上一个站台
		for (int j = 1; j <= k[i]; j++) { //站台
			int zhan = a[i][j];
			tot++;
			g[zhanting[zhan]].push_back(tot);
			g[tot].push_back(zhanting[zhan]);
			c[zhanting[zhan]][tot] = t[i][j];
			c[tot][zhanting[zhan]] = t[i][j];
			by_[tot] = zhan;
			if (last_zhantai != -1) {
				g[last_zhantai].push_back(tot);
				g[tot].push_back(last_zhantai);
				c[tot][last_zhantai] = 0;
				c[last_zhantai][tot] = 0;
			}
			last_zhantai = tot;
		}
	}
	for (int r_ = 1; r_ <= q; r_++) {
		int x, y;
		cin >> x >> y;
		int start;
		start = zhankou[x];
		int dep[8801] = {0};
		bool vis[8801] = {0};
		int ans = -1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		q.push({0, start});
		dep[start] = 0;
		vis[start] = 1;
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (by_[u] == y) {
				int v = -1;
				for (int ii = 0; ii < g[u].size(); ii++) {
					v = g[u][ii];
					if (c[u][v] > 0) {
						break;
					}
				}
				ans = dep[u] + c[u][v] + w[y];
				break;
			} else {
				for (int ii = 0; ii < g[u].size(); ii++) {
					int v = g[u][ii];
					if (vis[v] == 0) {
						vis[v] = 1;
						dep[v] = dep[u] + c[u][v];
						q.push({dep[v], v});
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}