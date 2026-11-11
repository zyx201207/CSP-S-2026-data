#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		ans = 0 ;
		int n, k;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			int u, v;
			cin >> u >> v;
			ans = min(ans, v - u);

		}
		cout << ans << "\n";
	}
	return 0;
}