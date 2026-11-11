#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+503;

struct ED {
	ll to, nxt, w;
} edge[N * 2];
ll head[N];
priority_queue<pair<ll, ll> > q;
bool vis[N];
ll dist[N];
ll cnt = 1;

inline void add(ll u, ll v, ll w) {
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}
//
//ll opg[N];

//
inline void dj(ll s) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	dist[s] = 0;
	while (q.size())
		q.pop();
	q.push(make_pair(0, s));
	while (q.size()) {
		ll u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;

		for (int i = head[u]; i; i = edge[i].nxt) {
			ll v = edge[i].to;
			if (vis[v])
				continue;
//			cout << "gfrdfg:" << u << " " << v << '\n';
			if (dist[v] > dist[u] + edge[i].w) {
				dist[v] = edge[i].w + dist[u];
				q.push(make_pair(-dist[v], v));
//				++opg[v];
//				if (opg[v] > 1)
//					cout << "stirp" << '\n';
			}
		}
	}
}
ll c, n, m, d, qe;
ll k;
ll w[N];
ll ans[N];
ll tot;

struct query {
	ll st, ed, id;
	bool operator < (const query &BR) const {
		return st < BR.st;
	}
} fg[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> qe;
	ll a, b;
	tot = m;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		++tot;
		for (int j = 1; j <= k; j++) {
			cin >> a >> b;
			add(a, tot, b);
			add(tot, a, b);
//			cout << "dfddf: " << a << " " << tot << '\n';
		}
	}
	fg[0] = {-20, -30, -96};
	for (int i = 1; i <= qe; i++) {


		cin >> a >> b;
		fg[i] = {a, b, i};

	}
	sort(fg + 1, fg + 1 + qe);
	for (int i = 1; i <= qe; i++) {
		if (fg[i].st != fg[i - 1].st) {
			dj(fg[i].st);
		}
		ans[fg[i].id] = dist[fg[i].ed] + w[fg[i].st] + w[fg[i].ed];

	}
	for (int i = 1; i <= qe; i++) {
		cout << ans[i] << '\n';
	}
//		for (int i = 1; i <= m; i++) {
//			cout << dist[i] << " ";
//		}
//		cout << '\n';

	return 0;
}