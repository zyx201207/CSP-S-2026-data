#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 0x3f3f3f3f;
const ll N = 500000;
ll n, m;
ll w[N + 5];

struct Edge {
	ll v;
	ll w;
};
vector<Edge> edge[N * 2 + 5];
ll d[N * 2 + 5];
bool vis[N * 2 + 5];

ll Dij(ll st, ll ed) {
	memset(d, MAXN, sizeof(d));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	d[st] = 0;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		ll u = pq.top().second;
		ll d_u = pq.top().first;
		//cout << u << ' ' << d_u << '\n';
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (ll i = 0; i < edge[u].size(); i++) {
			ll next = edge[u][i].v;
			ll w = edge[u][i].w;
			if (d[next] > d_u + w) {
				d[next] = d_u + w;
				pq.push(make_pair(d[next], next));
			}
		}
	}
	return d[ed];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll C, D, T;
	cin >> C;
	cin >> n >> m >> D >> T;
	for (ll i = 1; i <= m; i++)
		cin >> w[i];
	ll dot = 0;
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll a, t;
			cin >> a >> t;
			dot++;
			if (j != 1) {
				Edge e;
				e.v = dot;
				e.w = 0;
				edge[dot - 1].push_back(e);
				Edge e2;
				e2.v = dot - 1;
				e2.w = 0;
				edge[dot].push_back(e2);
				//cout << dot - 1 << ' ' << e.v << ' ' << e.w << '\n';
			}
			Edge e;
			e.v = dot;
			e.w = t;
			edge[N + a].push_back(e);
			Edge e2;
			e2.v = N + a;
			e2.w = t;
			edge[dot].push_back(e2);
			//cout << N + a << ' ' << e.v << ' ' << e.w << '\n';
		}
	}
	for (ll i = 1; i <= T; i++) {
		ll st, ed;
		cin >> st >> ed;
		ll ans = 0;
		ans += w[st] + w[ed];
		ans += Dij(N + st, N + ed);
		cout << ans << '\n';
	}
	return 0;
}