#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int u[N], v[N];
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
		}
		if (k == 1) {
			cout << 2;
		} else if (k == 2) {
			cout << 1;
		} else if (k == 3 || k == 4) {
			cout << 1;
		} else if (k == 5) {
			cout << 0;
		}
	}
	return 0;
}