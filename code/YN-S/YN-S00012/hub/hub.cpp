#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Y {
	int u = 0, v = 0;
} a[1000005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		ll n, k, u, v, d = 1;
		cin >> n >> k;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			if (a[u].v != 0) {
				if (a[u].v < v)
					d = min(v - u, d);
				if (a[u].v > v)
					d = max(a[u].v - v, d);
			}
			a[u].v = v;
			a[u].u = u;
		}
		cout << d << "\n";
	}
	return 0;
}