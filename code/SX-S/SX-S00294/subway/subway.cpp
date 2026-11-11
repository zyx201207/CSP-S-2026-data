#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int ct = 500100;
int c;
ull n, m, d, q, t[ct][25], line[550][ct], station[ct][25], x, y, ans;

vector<pair<ull, ull> >vec[ct];
bool vis[ct];

void bfs() {
	ull time = (1ULL << 63) - 1 + (1ULL << 63);
	memset(vis, 0, sizeof vis);
	queue<pair<ull, pair<ull, ull> > >q;
	for (auto k : vec[x])
		q.push({t[x][k.first], {k.first, k.second}});
	while (!q.empty()) {
		ull l = q.front().second.first, sta = q.front().second.second, tt = q.front().first;
		q.pop();
		if (sta == y)
			time = min(time, tt + t[sta][l]);
		else {
			for (auto k : vec[sta]) {
				if (k.first != l)
					q.push({tt + t[sta][l] + t[sta][k.first], {k.first, k.second}});
				else
					q.push({tt, {k.first, k.second}});
			}
		}
	}
	ans += time;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ull i = 1; i <= m; ++i)
		cin >> t[i][0];

	for (ull i = 1; i <= n; ++i) {
		cin >> line[i][0];

		for (ull j = 1; j <= line[i][0]; ++j) {
			cin >> line[i][j];
			if (j != 1) {
				vec[line[i][j]].push_back({i, line[i][j - 1]});
				vec[line[i][j - 1]].push_back({i, line[i][j]});
			}
			station[line[i][j]][station[line[i][j]][0]] = i;
			station[line[i][j]][0]++;
			cin >> t[line[i][j]][i];
		}
	}

	while (q--) {
		cin >> x >> y;
		ans = t[x][0] + t[y][0];
		bfs();
		cout << ans << '/n';
	}
	return 0;
}
