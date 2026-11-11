#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c, T;
void solve() {
	int n;
	ll d;
	cin >> n >> d;
	vector<ll> a(n);
	for (auto& i: a) cin >> i;
	if (c <= 10) {
		vector<vector<int>> adj(n);
		for (int i = 0; i < n; i ++ ) {
			for (int j = i + 1; j < n; j ++ ) {
				if (a[j] - a[i] <= d) {
					adj[i].push_back(j);
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i ++ ) {
			queue<int> q;
			vector<int> dist(n, 2 * n);
			vector<int> tot(n, 0);
			q.push(i);
			dist[i] = 0;
			tot[i] = 1;
			while (q.size()) {
				int u = q.front(); q.pop();
				for (auto v: adj[u]) {
					if (dist[v] > dist[u] + 1) {
						dist[v] = dist[u] + 1;
						tot[v] = tot[u];
						q.push(v);
					} else if (dist[v] == dist[u] + 1) tot[v] += tot[u];
				}
			}
			for (int j = i + 1; j < n; j ++ )
				if (tot[j] == 2) ans ++;
		}
		cout << ans << '\n';
	} else if (c <= 12) {
		// cout << 4444 << '\n';
		ll t = a[1] - a[0];
		ll p = d / t;
		ll ans = 0;
		if (p < 2) cout << 0 << '\n';
		else {
			for (int i = 0; i < n; i ++ ) {
				int j = i + 2 * p - 1;;
				if (j < n) ans ++;
			}
			cout << ans << '\n';
		}
	} else if (c <= 14) {
		int idx = 0;
		ll ans = 0;
		for (int i = 0; i < n; i ++ ) {
			if (a[i] - a[0] <= d && a[n - 1] - a[i] <= d) {
				idx = i;
			}
		}
		deque<int> dq;
		for (int i = 0; i < n; i ++ ) {
			if (i < idx) dq.push_back(i);
			else if (i > idx) {
				while (!dq.empty() && a[i] - a[dq.front()] > d) dq.pop_front();
				if (dq.size())
					if (dq.front() != 0 && dq.front() == idx - 1) ans += idx - 1;
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	if (T == 12) c = 12;
	while (T -- ) solve();
	return 0;
}