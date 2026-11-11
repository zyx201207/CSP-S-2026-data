#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10;
const ll INF = 1e18;
ll c, t, ans = INF;
ll n, k;
map <ll, vector <ll> > ve;
map <ll, bool> isx;
map <ll, bool> vis;
void check (vector <ll> x) {
	isx.clear();
	vis.clear();
	for (auto e : x) {
		isx[e] = true;
	}
	ll cnt = 0;
	for (auto i : x) {
		if (vis[i] == false) {
			cnt++;
			queue <ll> q;
			q.push (i);
			while (!q.empty ()) {
				ll u = q.front();
				q.pop();
				vis[u] = true;
				for (auto v : ve[u]) {
					if (!vis[v] && isx.count (v)) {
						q.push (v);
					}
				}
			}
		}
	}
	if (cnt > 2) {
		return ;
	}
	ll maxlen = 0;
	for (ll i = 1; i <= n; i++) {
		queue <ll> q;
		q.push (i);
		cnt = 0;
		bool flag = true;
		vis.clear();
		while (!q.empty () && flag) {
			for (ll t = (ll)q.size(); t >= 1; t--) {
				ll u = q.front();
				q.pop();
				if (isx.count (u)) {
					maxlen = max (maxlen, cnt);
					flag = false;
					break;
				}
				vis[u] = true;
				for (auto v : ve[u]) {
					if (!vis[v]) {
						q.push(v);
					}
				}
			}
			cnt++;
		}
	}
	ans = min (ans, maxlen);
	return ;
}
void dfs (int idx, vector <ll> x) {
	if ((int)x.size() == k) {
		check (x);
		return ;
	}
	if (idx > n) {
		return ;
	}
	for (ll i = idx; i <= n; i++) {
		x.push_back (i);
		dfs (i + 1, x);
		x.pop_back ();
	}
}
void solve () {
	ans = INF;
	cin >> n >> k;
	for (ll i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		ve[u].push_back (v);
		ve[v].push_back (u);
	}
	dfs (1, vector<ll> {});
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		ve[i].clear();
	}
}
int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		solve ();
	}
	return 0;
}
