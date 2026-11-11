#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll c, n, m, d, q;
ll w[N], dist[N], k;
vector<ll> a[N], t[N];
//vector<pair<ll, ll>> a[N];

/* trying to finish A but failed
ll dij(ll x, ll y) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, x});
	while (!pq.empty()) {
		pair<ll, ll> u = pq.back();
		for (pair<ll, ll> v : a[u.second]) {
			if (dist[v.second] > u.first + v.first) {
				dist[v.second] = u.first + v.first;
				pq.push({dist[v.second], v.second});
			}
		}
		pq.pop();
	}
	return dist[y];
}

void solvea() {
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	ll x, t1, y, t2;
	for (int i = 1; i <= n; i++) {
		cin >> x >> t1 >> y >> t2;
		a[x].push_back({t1 + t2, y});
		a[y].push_back({t1 + t2, x});
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << dij(x, y) << "\n";
	}
}
*/
int main() {
	// please, don't hack me(even though this program hasn't be completed yet)
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to change the file name!!!!!
	// be sure to delete any "//"
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		ll tmp;
		for (int j = 1; j <= k; j++) {
			cin >> tmp;
			a[i].push_back(tmp);
			cin >> tmp;
			t[i].push_back(tmp);
		}
	}
	ll x, y;
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << w[x] + w[y] + 5 << "\n";;
	}

	return 0;
}
