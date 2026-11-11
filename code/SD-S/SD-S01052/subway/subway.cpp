#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;

int c, n, m, d, p, w[500010];
vector <int> a[N], t[N];
vector <ll> vis[N];
vector <pair<int, int>> r[500010];
ll ans, as;

void dfs(int x, int y, int e, int sum, int flag) {
	if(a[x][y] == e) {
		ans = min(ans, sum + as + t[x][y]);
		return ;
	}
	if(vis[x][y] <= sum) return ;
	vis[x][y] = sum;
	if(flag == 0) for(int i = 1; i < a[x].size(); i ++) dfs(x, i, e, sum, 1);
	else {
		for(int i = 0; i < r[a[x][y]].size(); i ++) {
			if(r[a[x][y]][i].first != x) dfs(r[a[x][y]][i].first, r[a[x][y]][i].second, e, sum + t[x][y] + t[r[a[x][y]][i].first][r[a[x][y]][i].second], 0);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		int k; cin >> k;
		a[i].push_back(0), t[i].push_back(0), vis[i].push_back(0);
		for(int j = 1; j <= k; j ++) {
			int x, y; cin >> x >> y;
			a[i].push_back(x), t[i].push_back(y), vis[i].push_back(1e18);
			r[x].push_back({i, j});
		}
	}
	while(p --) {
		ans = 1e18;
		int s, e; cin >> s >> e;
		for(int i = 0; i < r[s].size(); i ++) {
			for(int j = 1; j <= n; j ++) {
				for(int k = 0; k < vis[j].size(); k ++) vis[j][k] = 1e18;
			}
			as = w[s] + w[e] + 0ll + t[r[s][i].first][r[s][i].second];
			dfs(r[s][i].first, r[s][i].second, e, 0, 0);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
