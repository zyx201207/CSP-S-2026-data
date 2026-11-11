#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, ans = 0, cnt = INT_MAX;
int w[500009];
map<pair<int, int>, int>mp;
vector<vector<int>>a, h;
vector<vector<int>>t;

struct s {
	int x, num, num2;
};

void bfs(int x, int y) {
	queue<s>q;
	for (int i : a[x]) {
		q.push({i, 0, x});
		mp[ {i, x}] = 1;
	}
	while (!q.empty()) {
		s to = q.front();
		q.pop();
		if (to.num2 == y) {
			cnt = min(cnt, to.num);
			continue;
		}
		for (int i : h[a[to.x][0]]) {
			if (!mp[ {i, to.x}]) {
				q.push({i, to.num + t[to.x][i], i});
				mp[ {i, to.x}]++;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k ; j++) {
			int na, nt;
			cin >> na >> nt;
			h[i].push_back(na);
			a[na].push_back(i);
			t[i][na] = nt;
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ans += w[x] + w[y];
		bfs(x, y);
		ans += cnt;
		cnt = INT_MAX;
	}
	return 0;
}
