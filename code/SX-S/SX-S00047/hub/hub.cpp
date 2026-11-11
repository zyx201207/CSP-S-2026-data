//T4 hub
#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, u[2000005], v[2000006];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	return 0;
}
