#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ans = INT_MAX;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			ans = min(x, ans);
		}
		cout << ans << endl;
	}
	return 0;
}