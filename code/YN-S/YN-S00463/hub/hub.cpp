#include <bits/stdc++.h>
#define int long long
using  namespace std;
int c, t;
int n, k;
int u, v;

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		cin >> u >> v;
		for (int i = LLONG_MIN; i <= LLONG_MAX; i++) {
			cout << i << '\n';
		}
	}
	return 0;
}
