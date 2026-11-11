# include <bits/stdc++.h>
# define ll long long
# define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll N = 1e6 + 5;
ll c, t, n, k, ans = inf, dis[N];
vector <ll> adj[N];
bool f[N], vis[N]; 

void DFS (ll x) {
	vis[x] = 1;
	for (ll i = 0; i < adj[x].size (); i ++) {
		ll y = adj[x][i];
		if (vis[y]) continue ;
		DFS (y);
	}
}

void Dij (ll root) {
	memset (dis, 0x3f, sizeof (dis));
	memset (f, 0, sizeof (f));
	priority_queue <pair <ll, ll> > q;
	dis[root] = 0;
	q.push ({0, root});
	while (! q.empty ()) {
		ll x = q.top ().second; q.pop ();
		f[x] = 1;
		for (ll i = 0; i < adj[x].size (); i ++) {
			ll y = adj[x][i];
			//if (f[y]) continue ;
			if (dis[x] + 1 < dis[y]) {
				dis[y] = dis[x] + 1;
				if (! f[y])
					q.push ({- dis[y], y});
			}
		}
	}
}

void dfs (ll lst, ll now) {
	if (now == 0) {
		ll cnt = 0;
		for (ll i = 1; i <= n; i ++) {
			if (f[i] && ! vis[i]) {
				cnt ++;
				DFS (i);
			} 
		}
		if (cnt > 2) return ;
		ll maxx = -inf;
		for (ll i = 1; i <= n; i ++) {
			Dij (i);
			ll minn = inf;
			for (ll j = 1; j <= n; j ++)
				if (f[j] && dis[j]) minn = min (minn, dis[j]);
			maxx = max (maxx, minn);
		}
		ans = min (ans, maxx);
		return ;
	}
	if (lst == n) return ;
	for (ll i = lst + 1; i <= n; i ++) {
		f[i] = 1;
		dfs (i, now - 1);
		f[i] = 0;
	}
}

int main () {
	
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		if (n <= 1e5) {
			ans = inf;
			for (ll i = 1; i < n; i ++) {
				ll u, v; cin >> u >> v;
				adj[u].push_back (v);
				adj[v].push_back (u);
			} 
			dfs (0, k);
			cout << ans << "\n";
		} else cout << 1 << "\n";
	}

	return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
