# include <bits/stdc++.h>
# define ll long long
# define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll N = 505; 
const ll M = 1e6 + 5;
ll c, n, m, d, q, ans = inf, tot;
ll w[M], dis[M];
vector <pair <ll, ll> > adj[M];
bool f[M];
map <pair <ll, ll>, ll> Mp;

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
			ll y = adj[x][i].first, z = adj[x][i].second;
			//if (f[y]) continue ;
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z;
				if (! f[y])
					q.push ({- dis[y], y});
			}
		}
	}
}

ll mp (pair <ll, ll> it) {
	if (Mp[it]) return Mp[it];
	return Mp[it] = ++ tot;
}

int main () {
	
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	tot = 2 * m;
	for (ll i = 1; i <= m; i ++) {
		cin >> w[i];
		adj[i].push_back ({m + i, w[i]});
		adj[m + i].push_back ({i, w[i]});
	}
	for (ll i = 1; i <= n; i ++) {
		ll k, lst = -1; cin >> k;
		for (ll j = 1; j <= k; j ++) {
			ll a, b; cin >> a >> b;
			if (lst != -1) {
				adj[mp({a, i})].push_back ({mp({lst, i}), 0});
				adj[mp({lst, i})].push_back ({mp({a, i}), 0});
			}
			lst = a;
			adj[a + m].push_back ({mp({a, i}), b});
			adj[mp({a, i})].push_back ({a + m, b});
		}
	}
	for (ll i = 1; i <= q; i ++) {
		ll s, t; cin >> s >> t;
		Dij (s); cout << dis[t] << "\n";
	}
	
	return 0;
}

/*
m 点 n 边
地铁口 ->(w_v) 站厅 -> 站台 (t_i,j)
编号：地铁口 1-m 站厅 m+1-2m 第i个地铁站的第j线路站台m+i*d+j
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
----
0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
---
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
