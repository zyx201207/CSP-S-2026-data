#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n, k, c, t, x, y;
ll ans, dis[MAXN], vis[MAXN], fa[MAXN];
vector<ll> f[MAXN], e[MAXN];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}
ll count(ll x) {
	ll cnt = 0;
	while (x) {
		x-=(x & -x);
		cnt++;
	}
	return cnt;
}
void dist(ll x) {
	memset(dis, 127, sizeof(dis));memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
		if (x & (1 << (i - 1))) {
			q.push(make_pair(0, i));
			dis[i] = 0;
		}
	for (int i = 1; i <= n; i++)
		if (dis[i] == 0) 
			for (int j = 0; j < f[i].size(); j++) {
				int sx = f[i][j];
				if (dis[sx] == 0) fa[find(sx)] = find(i);
			}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) == i && dis[i] == 0) cnt++;
	if (cnt != 2) return ;
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = 0; i < f[x].size(); i++) {
			int sx = f[x][i];
			if (dis[x] + 1 < dis[sx]) {
				dis[sx] = dis[x] + 1;
				q.push(make_pair(dis[sx], sx));
			}
		}
	}
	ll Mx = 0;
	for (int i = 1; i <= n; i++) Mx = max(Mx, dis[i]);
	ans = min(ans, Mx);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) f[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			f[x].push_back(y);f[y].push_back(x);
		} 
		ans = 2e18;
		for (ll i = 0; i < (1 << n); i++)
			if (count(i) == k) dist(i);
		cout << ans << "\n";
	}
	return 0;
}
