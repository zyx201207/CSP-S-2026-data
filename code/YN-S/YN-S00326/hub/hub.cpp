#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
		}
		if (k < n / 2)
			cout << (n + 8 - k * 2) / 8 + 1 << '\n';
		else if (k < n)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}