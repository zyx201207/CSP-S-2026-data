#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, k, u, v;
		cin >> n >> k;
		for (int j = 1; j < n; j++) {
			cin >> u >> v;
		}
		if (k == n)
			cout << "0" << endl;
		else {
			if (((n - 1) / 2) <= k)
				cout << "1" << endl;
			else {
				int ui = ((n - 1) / 2) - k  ;
				if (ui % 4 == 0) {
					cout << ((ui / 4) + 1) << endl;
				} else {
					cout << ((ui / 4) + 2) << endl;
				}
			}
		}
	}
	return 0;
}
