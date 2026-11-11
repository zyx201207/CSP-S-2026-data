#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll c, n, m, d, q, x, y, w[500010];
struct Node {
	ll line, v;
	bool operator < (Node b) const {
		return line * n + v < b.line * n + b.v;
	}
};
vector < Node > g[500010];
vector < ll > l[500010];
map < pair < ll, ll >, ll > t;
map < Node, bool > vis;
struct S {
	Node cur;
	ll step;
};
ll bfs(ll x, ll y) {
	ll ans = 1e18;
	queue < S > que;
	for (ll i = 1; i <= m; i++)
		for (ll j : l[i]) vis[{j, i}] = 0;
	que.push({{l[x][0], x}, 0});
	while (!que.empty()) {
		Node u = que.front().cur;
		ll st = que.front().step;
		que.pop();
		vis[u] = 0;
		for (Node nxt : g[u.v]) {
			ll v = nxt.v, li = nxt.line;
			if (vis[{li, v}]) continue;
			if (v == y) {
				ans = min(ans, st + t[{li, v}] + t[{li, u.v}] + w[x] + w[y]);
				return ans;
			}
			if (li == u.line) que.push({{li, v}, st});
			else que.push({{li, v}, st + t[{li, v}] + t[{li, u.v}]});
		}
	}
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) cin >> w[i];
	for (ll i = 1, k; i <= n; i++) {
		cin >> k;
		ll tmp = 1, ai = 1, ti;
		for (ll j = 1; j <= k; j++) {
			tmp = ai;
			cin >> ai >> ti;
			l[ai].push_back(i);
			if (j > 1) {
				g[tmp].push_back({i, ai});
				for (ll k : l[tmp]) g[ai].push_back({k, tmp});
			}
			t[{i, ai}] = ti;
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << bfs(x, y) << '\n';
	}
//	for (ll i = 1; i <= m; i++) {
//		cout << i << ':';
//		for (Edge j : g[i]) {
//			cout << '{' << j.line << ',' << j.v << '}' << ' ';
//		}
//		cout << '\n';
//	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
