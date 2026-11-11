#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], p;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			p = a[i] - a[i - 1];
		}
		ans += n - d / p * 2 + 1;
		cout << ans << "\n";
	}
	return 0;
}
