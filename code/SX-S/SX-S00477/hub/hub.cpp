#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, k, u[1000005], v[1000005], f[1000005], ans, nans;
bool vis[1000005];
vector<ll> vt[1000005];

ll getfa(ll x) {
	if (f[x] == x)
		return x;
	return f[x] = getfa(f[x]);
}

void bfs(ll x, ll fa, ll dep) {
	for (ll i = 0; i < vt[x].size(); i++) {
		ll vv = vt[x][i];
		if (vv == fa)
			continue;
		if (vis[vv]) {
			nans = min(nans, dep);
		}
		bfs(vv, x, dep + 1);
	}
}

void dfs(ll step, ll x) {
	if (step > k) {
		for (ll i = 1; i <= n; i++)
			f[i] = i;
		for (ll i = 1; i < n; i++) {
			if (vis[u[i]] && vis[v[i]]) {
//				cout << u[i] << " " << v[i] << " ";
				ll fx = getfa(u[i]), fy = getfa(v[i]);
//				cout << fx << " " << fy << endl;
				if (fx != fy)
					f[fx] = fy;
			}
		}
		ll num = 0;
		for (ll i = 1; i <= n; i++) {
			if (vis[i] && f[i] == i)
				num++;
		}
		if (num > 2)
			return ;
//		for (ll i = 1; i <= n; i++)
//			cout << vis[i] << " ";
//		cout << endl;
		ll nowans = 0;
		for (ll i = 1; i <= n; i++) {
			if (!vis[i]) {
				nans = 1e18;
				bfs(i, 0, 1);
//				cout << i << " " << nans << "\n";
				nowans = max(nowans, nans);
			}
		}
//		cout << endl;
//		cout << nowans << endl;
		ans = min(ans, nowans);
		return ;
	}
	for (ll i = x + 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		dfs(step + 1, i);
		vis[i] = 0;
	}
}

void solve() {
	cin >> n >> k;
	for (ll i = 1; i < n; i++) {
		cin >> u[i] >> v[i];
		vt[u[i]].push_back(v[i]);
		vt[v[i]].push_back(u[i]);
	}
	ans = 1e18;
	dfs(1, 0);
	cout << ans << endl;
	for (ll i = 1; i <= n; i++)
		vt[i].clear();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
		solve();
}