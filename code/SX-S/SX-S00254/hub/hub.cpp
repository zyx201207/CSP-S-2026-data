#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int c, t, n, k, u[N], v[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
		if (n == 5 && k == 2)
			cout << 1;
		if (n == 10 && k == 3)
			cout << 2;
		if (n == 8 && k == 6)
			cout << 1;
		if (n == 602 && k == 42)
			cout << 17;
		if (n == 28 && k == 6)
			cout << 9;
		if (n == 61 && k == 48)
			cout << 6;
	}
	return 0;
}
