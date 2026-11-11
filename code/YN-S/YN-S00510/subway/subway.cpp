#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
const ll INF = 1e18;
ll c, n, m, d, q;
ll a[N];
vector<pair<ll, ll>> adj[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ll t;
		cin >> t;
		ll t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		adj[t1].push_back({t3, t2 + t4});
		adj[t3].push_back({t1, t2 + t4});
	}
	priority_queue<pair<ll, ll>> que;
	for (int i = 1; i <= q; i++) {
		que = priority_queue<pair<ll, ll>>();
		ll start, end;
		cin >> start >> end;
		ll dist[N];
		for (int i = 1; i <= m; i++)
			dist[i] = INF;
		dist[start] = 0;
		que.push({0, start});
		ll fa;
		while (!que.empty()) {
			ll value = que.top().first;
			ll idx = que.top().second;
			que.pop();
			if (idx == end) {
				cout << value + a[start] + a[end] << endl;
				break;
			}
			if (dist[idx] > value) {
				dist[idx] = value;
			}
			for (auto v : adj[idx]) {
				ll next = v.first;
				ll dis = v.second;
				if (next != fa)
					que.push({ value + 2 * dis, next});

			}
			fa = idx;
		}
	}


	return 0;
}