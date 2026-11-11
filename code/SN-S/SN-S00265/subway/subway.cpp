#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int c, n, m, D, q;
int w[500005];
vector<pair<int, int>> a[500005], e[500005];
int k[500005];
int b[500005];
int d[505][505];
set<pair<int, int>> s; 

inline void dijkstra() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = 1LL << 60;
	for (int i = 1; i <= m; i++) {
		s.clear();
		d[i][i] = 0;
		for (int j = 1; j <= m; j++)
			s.insert({d[i][j], j});
		while (!s.empty()) {
			int x = s.begin()->second;
			s.erase(*s.begin());
			if (d[i][x] >= 1LL << 60)
			for (auto j : e[x])
				if (d[i][j.first] > d[i][x] + j.second) {
					s.erase({d[i][j.first], j.first});
					d[i][j.first] = d[i][x] + j.second;
					s.insert({d[i][j.first], j.first});
				}
		} 
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &D, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			int x, y;
			scanf("%lld%lld", &x, &y);
			a[i].push_back({x, y}), b[x]++;
		}
	}
  	if (c <= 11) {
		for (int i = 1; i <= n; i++)
			for (auto j : a[i])
				for (auto k : a[i])
					if (j.first != k.first) {
						int x = 0;
						if (b[j.first] > 1) x += j.second;
						if (b[k.first] > 1) x += k.second;
						e[j.first].push_back({k.first, x});
					}
		dijkstra();
		while (q--) {
			int x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", d[x][y] + w[x] + w[y]);
		}
	} else if (c <= 19) {
		
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
