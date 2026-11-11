#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500010];
vector<vector<int> >pa(500010);
vector < vector<int>> xian(550);
int t[510][5005];

struct QQ {
	int u;
	long long step;
	int last;
	bool operator<(const QQ &other) const {
		return step > other.step;
	}
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, tx;
			cin >> a >> tx;
			pa[a].push_back(i);
			xian[i].push_back(a);
			t[i][a] = tx;
		}
	}
	while (q--) {
		int qi, jie;
		cin >> qi >> jie;
		priority_queue<QQ> qq;
		qq.push({qi, 0, 0});
		long long dis[n + 1][m + 1];
		memset(dis, 0x3f3f3f3f3f, sizeof(dis));
		while (!qq.empty()) {
			int  u = qq.top().u, last = qq.top().last;
			long long step = qq.top().step;
			qq.pop();
//			cout << u << " " << step << " " << last << endl;
			int s = pa[u].size();
			for (int i = 0; i < s; i++) {
				int x = xian[i].size();
				if (pa[u][i] != last) {
					for (int j = 0; j < x; j++) {
						if (pa[xian[i][j]].size() > 1) {
							if (dis[i][xian[i][j]] > step + t[i][u]) {
								dis[i][xian[i][j]] = step + t[i][u];
								qq.push({xian[i][j], step + t[i][u], i});
							}
						} else {
							dis[i][xian[i][j]] = min(step + t[i][xian[i][j]], dis[i][xian[i][j]]);
						}
					}
				}
			}
		}
		long long ans = 1e18;
		for (int i = 0; i <= n; i++) {
			ans = min(ans, dis[i][jie] + t[i][jie]);
		}
		ans = ans + w[qi] + w[jie];
		cout << ans << endl;
	}
	return 0;
}
