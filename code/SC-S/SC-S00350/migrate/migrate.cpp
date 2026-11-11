#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = double;
using ull = unsigned long long;
using cll = const long long;
ll c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --) {
		ll n, d;
		cin >> n >> d;
		vector<ll> x(n + 1);
		vector<ll> f(n + 1);
		for (ll i = 1; i <= n; i ++) {
			cin >> x[i];
		}
		ll cnt = 0;
		for (ll i = 3; i <= n; i ++) {
			if (x[i] - x[i - 1] <= d && x[i] - x[i - 2] <= d) {
				f[i] = 1;
			}
			if (f[i] == 1 && f[i - 1] == 1) {
				cnt ++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}