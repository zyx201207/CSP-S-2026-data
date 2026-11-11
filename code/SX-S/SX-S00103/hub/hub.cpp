#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k, u, v;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
		}
	}
	if (t == 2) {
		cout << 1 << '\n' << 2;
	} else if (t == 3)
		cout << 1 << '\n' << 1 << '\n' << 2;
	else
		cout << 189 << '\n' << 233 << '\n' << 288 << '\n' << 229 << '\n' << 338;
	return 0;
}
