#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c, n, m, d, q, minn = 1e18;
int w[505], v[500005][505], vis[500005], x, y;
vector<int> t[500005];
vector<int> g[505];
void dfs(int step, int k, int sum) {
	if(step == y) {
		minn = min(minn, sum + w[y] + v[y][k]);
		return;
	}
	for(auto &i : t[step]) {
		for(auto &j : g[k]) {
			if(j != step) dfs(j, i, sum + v[step][k] + v[step][i]);
		}
	}
}
void solve1() {
	cin >> x >> y;
	for(auto &i : t[x]) {
		dfs(x, i, w[x] + v[x][i]);
	}
	cout << minn;
}
void solve2() {
	cin >> x >> y;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= 2 * k; j++) {
			int a, p;
			cin >> a >> p;
			t[a].push_back(i);
			g[i].push_back(a);
			v[a][i] = p;
		}
	}
	if(c >= 7 && c <= 11) {
		while(q--) solve1();
	}
	else if(c >= 12 && c <= 19) {
		while(q--) solve2();
	}
	return 0;
}
