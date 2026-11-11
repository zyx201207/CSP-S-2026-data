#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;

int c, n, m, d, qq, w[N], k[505], a[505][N], t[505][N], x, y;
vector <pair<int, int>> e[N];
bool f[N];

struct T {
	int pos, sum, id;
};
queue <T> q;


int bfs(int s, int ed) {
	memset(f, 0, sizeof s);
	q.push({s, w[s], 0});
	//f[s] = 1;
	while (!q.empty()) {
		T old = q.front();
		if (old.pos == ed)
			return old.sum + w[ed];
		q.pop();
		for (int i = 0; i < e[old.pos].size(); i++) {
			int v = e[old.pos][i].first, id = e[old.pos][i].second;
			if (id == old.id) {
				q.push({v, old.sum, id});
				//f[v] = 1;
				continue;
			}
			if (f[v])
				continue;
			q.push({v, old.sum + t[id][old.pos] + t[id][v], id});
			//f[v] = 1;
		}
	}
}

signed main() {
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][a[i][j]];
		}
		for (int j = 2; j <= k[i]; j++) {
			e[a[i][j - 1]].push_back({a[i][j], i});
		}
	}
	for (int i = 1; i <= qq; i++) {
		cin >> x >> y;
		cout << bfs(x, y) << endl;
	}
	return 0;
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