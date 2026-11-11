#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = double;
using ull = unsigned long long;
using cll = const long long;
ll c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --) {
		ll n, k;
		cin >> n >> k;
		vector<ll> u(n + 1), v(n + 1);
		vector<ll> g[n + 1];
		for (ll i = 1; i <= n - 1; i ++) {
			cin >> u[i] >> v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		cout << (k + 1) / 2 << '\n';
	}
	return 0;
}