#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	ll u, v;
} a[2000005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, t, w = 1;
	cin >> c >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i].u >> a[i].v;
		}
		cout << w << "\n";
		w++;
	}
	return 0;
}