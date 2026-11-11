#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

namespace PTqwq {
	
i64 readqwq() {
	i64 x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 5e5 + 50;

i64 curC, n, m, cntD, Q, dis[568][568], sta[N];
vector<pair<i64, i64>> st[568];
vector<pair<i64, i64>> stQry[N];

void initG() {
	curC = readqwq();
	n = readqwq();
	m = readqwq();
	cntD = readqwq();
	Q = readqwq();
	for (i64 i = 1; i <= m; ++ i) {
		sta[i] = readqwq();
	}
	for (i64 i = 1; i <= n; ++ i) {
		i64 cnt = readqwq();
		for (i64 j = 1; j <= cnt; ++ j) {
			i64 x = readqwq();
			i64 y = readqwq();
			st[i].emplace_back(x, y);
			stQry[x].emplace_back(i, y);
		}
	}
}

const i64 infLL = 1e18;

void Solve() {
	initG();
	for (i64 i = 1; i <= n; ++ i) {
		for (i64 j = 1; j <= n; ++ j) {
			dis[i][j] = infLL;
			if (i == j) {
				dis[i][i] = 0;
			}
		}
	}
	for (i64 i = 1; i <= m; ++ i) {
		for (auto x : stQry[i]) {
			for (auto y : stQry[i]) {
				if (x.first != y.first) {
					dis[x.first][y.first] = min(dis[x.first][y.first], x.second + y.second); 
				}
			}
		}
	}
	for (i64 mid = 1; mid <= n; ++ mid) {
		for (i64 i = 1; i <= n; ++ i) {
			for (i64 j = 1; j <= n; ++ j) {
				dis[i][j] = min(dis[i][j], dis[i][mid] + dis[mid][j]);
			}
		}
	}
	for (i64 i = 1; i <= Q; ++ i) {
		i64 ans = infLL;
		i64 x = readqwq();
		i64 y = readqwq();
		for (auto u : stQry[x]) {
			for (auto v : stQry[y]) {
				ans = min(ans, dis[u.first][v.first] + u.second + v.second);
			}
		}
		ans += sta[x];
		ans += sta[y];
		printf("%lld\n", ans);
	}
}
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
