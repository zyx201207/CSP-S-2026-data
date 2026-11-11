#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct node {
	long long x, w;
	bool operator < (const node &b) const {
		return w > b.w;
	}
};
long long ans, dis[505][505];
vector<node> v[1000005];
int c, n, m, d, q, a[500005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1, k; i <= m; i++) {
		cin >> k;
		for(int x, w; k--;)
			cin >> x >> w, v[x].push_back({i, w});
	}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			if(i ^ j)
				dis[i][j] = inf;
	for(int i = 1; i <= n; i++)
		for(auto j : v[i])
			for(auto k : v[i])
				dis[j.x][k.x] = dis[k.x][j.x] = min(dis[j.x][k.x], j.w + k.w);
	for(int k = 1; k <= m; k++)
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int x, y; q--;) {
		cin >> x >> y, ans = inf;
		for(auto i : v[x])
			for(auto j : v[y])
				ans = min(ans, a[x] + a[y] + i.w + j.w + dis[i.x][j.x]);
		cout << ans << '\n';
	}
	return 0;
}