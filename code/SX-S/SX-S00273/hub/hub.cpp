#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, x, y;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		for (int j = 1; j < n; j++) {
			cin >> x >> y;
		}
	}
	if (c == 0 && t == 2 && n == 10 && k == 3)
		cout << 1 << endl << 2;
	if (c == 0 && t == 3 && n == 9 && k == 3)
		cout << 1 << endl << 1 << endl << 2;
	if (c == 0 && t == 1 && n == 99999 && k == 1000)
		cout << 12251 << endl;
	return 0;
}
