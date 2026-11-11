#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t;
ll n, k;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (ll i = 1; i <= n - 1; ++i) {
			ll u, v;
			cin >> u >> v;
		}
		ll cur = n / 2 - k + 1;
		cout << (cur + 2) / 4 + 1 << "\n";
	}
	// time ./hub hhhhh
	// best /hub user
	return 0;
}