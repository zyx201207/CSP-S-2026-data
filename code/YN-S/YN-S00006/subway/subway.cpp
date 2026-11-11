#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int M = 500000;
const int N = 500;
vector<pair<int, long long>> sta[M + 5];
vector<pair<int, long long>>::iterator it1, it2;
map<pair<int, int>, long long> mp;
long long w[M + 5];
long long dis[N + 5][N + 5];
int c, n, m, d, q;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dis[i][j] = 0;
			} else {
				dis[i][j] = 1e18;
			}
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) {
				continue;
			}
			for (int j = i; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void query(int x, int y) {
	if (mp.count({x, y})) {
		printf("%lld\n", mp[ {x, y}]);
	}
	long long ans = 1e18;
	int t1, t2;
	for (it1 = sta[x].begin(); it1 != sta[x].end(); it1++) {
		for (it2 = sta[y].begin(); it2 != sta[y].end(); it2++) {
			t1 = (*it1).first;
			t2 = (*it2).first;

			ans = min(ans, w[x] + w[y] + (*it1).second + (*it2).second + dis[t1][t2]);
		}
	}
	mp[ {x, y}] = mp[ {y, x}] = ans;
	printf("%lld\n", ans);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int k, pos, t1, t2, x, y;
	long long cost;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d%lld", &pos, &cost);
			sta[pos].push_back({i, cost});
		}
	}
	init();
	for (int i = 1; i <= m; i++) {
		for (it1 = sta[i].begin(); it1 != sta[i].end(); it1++) {
			for (it2 = it1; it2 != sta[i].end(); it2++) {
				t1 = (*it1).first;
				t2 = (*it2).first;
				dis[t1][t2] = min(dis[t1][t2], (*it1).second + (*it2).second);
				//dis[t2][t1] = min(dis[t1][t2], (*it1).second + (*it2).second);
			}
		}
	}

	floyd();

	while (q--) {
		scanf("%d%d", &x, &y);
		query(x, y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}