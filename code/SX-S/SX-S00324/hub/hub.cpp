#include <bits/stdc++.h>
using namespace std;
int u[1000010];
int v[1000010];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (;; t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
		if (n - 1 % 2 == 0) {
			cout << k / 2;
		} else {
			cout << k;
		}
	}
	return 0;
}